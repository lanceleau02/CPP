/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laprieur <laprieur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 11:40:55 by laprieur          #+#    #+#             */
/*   Updated: 2023/11/23 13:08:27 by laprieur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

static int	Jacobsthal(int n) {
	int	pprev = 0;
	int	prev = 2;
	int	res = 2;

	for (int i = 0; i < n; i++) {
		res = prev + (2 * pprev);
		pprev = prev;
		prev = res;
	}
	return res;
}

static std::deque<int>	MergeInsertionSort(std::deque<int> X) {
	size_t	n = X.size();
	std::deque<std::pair<int, int> > pairs;
	std::deque<int>	S;
	
	if (n == 1)
		return X;

	// STEP 1: Group the elements of X into [n/2] pairs of elements.
	for (std::deque<int>::iterator it = X.begin(); it != X.end(); it += 2) {
		std::pair<int, int> pair;
		if (it + 1 == X.end())
			break ;
		// STEP 2: Perform [n/2] comparisons, one per pair, to determine the larger of the two elements in each pair.
		pair.first = (*it > *(it + 1)) ? *it : *(it + 1);
		pair.second = (*it < *(it + 1)) ? *it : *(it + 1);
		pairs.push_back(pair);
		S.push_back(pair.first);
	}

	// STEP 3: Recursively sort the [n/2] larger elements from each pair.
	S = MergeInsertionSort(S);
	std::deque<int> copyS(S);
	
	copyS.erase(copyS.begin());
	
	// STEP 4: Insert at the start of S the element that was paired with the first and smallest element of S.
	std::deque<std::pair<int, int> >::iterator	it = findElement(pairs, S.front());
	
	S.insert(S.begin(), it->second);
	pairs.erase(it);

	// STEP 5: Insert the remaining [n/2] - 1 elements of X\S into S, one at a time.
	std::deque<int>	group;
	int					i = 0;

	while (!copyS.empty()) {
		int size = Jacobsthal(i);
		if (size > (int)copyS.size())
			group.insert(group.begin(), copyS.begin(), copyS.end());
		else
			group.insert(group.begin(), copyS.begin(), copyS.begin() + size);
		std::reverse(group.begin(), group.end());
		for (std::deque<int>::iterator it = group.begin(); it != group.end(); it++) {
			std::deque<std::pair<int, int> >::iterator	min = findElement(pairs, *it);
			int index = std::distance(S.begin(), binarySearch(S, 0, S.size() - 1, min->first) - 1);
			S.insert(binarySearch(S, 0, index, min->second), min->second);
			pairs.erase(min);
		}
		if (size > (int)copyS.size())
			copyS.clear();
		else
			copyS.erase(copyS.begin(), copyS.begin() + size);
		group.clear();
		i++;
	}
	if (X.size() % 2 != 0)
		S.insert(binarySearch(S, 0, S.size() - 1, *(X.end() - 1)), *(X.end() - 1));

	return S;
}

static std::vector<int>	MergeInsertionSort(std::vector<int> X) {
	size_t	n = X.size();
	std::vector<std::pair<int, int> > pairs;
	std::vector<int>	S;
	
	if (n == 1)
		return X;

	// STEP 1: Group the elements of X into [n/2] pairs of elements.
	for (std::vector<int>::iterator it = X.begin(); it != X.end(); it += 2) {
		std::pair<int, int> pair;
		if (it + 1 == X.end())
			break ;
		// STEP 2: Perform [n/2] comparisons, one per pair, to determine the larger of the two elements in each pair.
		pair.first = (*it > *(it + 1)) ? *it : *(it + 1);
		pair.second = (*it < *(it + 1)) ? *it : *(it + 1);
		pairs.push_back(pair);
		S.push_back(pair.first);
	}

	// STEP 3: Recursively sort the [n/2] larger elements from each pair.
	S = MergeInsertionSort(S);
	std::vector<int> copyS(S);
	
	copyS.erase(copyS.begin());
	
	// STEP 4: Insert at the start of S the element that was paired with the first and smallest element of S.
	std::vector<std::pair<int, int> >::iterator	it = findElement(pairs, S.front());
	
	S.insert(S.begin(), it->second);
	pairs.erase(it);

	// STEP 5: Insert the remaining [n/2] - 1 elements of X\S into S, one at a time.
	std::vector<int>	group;
	int					i = 0;

	while (!copyS.empty()) {
		int size = Jacobsthal(i);
		if (size > (int)copyS.size())
			group.insert(group.begin(), copyS.begin(), copyS.end());
		else
			group.insert(group.begin(), copyS.begin(), copyS.begin() + size);
		std::reverse(group.begin(), group.end());
		for (std::vector<int>::iterator it = group.begin(); it != group.end(); it++) {
			std::vector<std::pair<int, int> >::iterator	min = findElement(pairs, *it);
			int index = std::distance(S.begin(), binarySearch(S, 0, S.size() - 1, min->first) - 1);
			S.insert(binarySearch(S, 0, index, min->second), min->second);
			pairs.erase(min);
		}
		if (size > (int)copyS.size())
			copyS.clear();
		else
			copyS.erase(copyS.begin(), copyS.begin() + size);
		group.clear();
		i++;
	}
	if (X.size() % 2 != 0)
		S.insert(binarySearch(S, 0, S.size() - 1, *(X.end() - 1)), *(X.end() - 1));

	return S;
}

static double	elapsedTime(clock_t startTime, clock_t endTime) {
	return ((static_cast<double>(endTime - startTime) / CLOCKS_PER_SEC) * 1000000);
}

void	PmergeMe(char **argv) {
	std::vector<int>	vector;
	std::deque<int>		deque;

	for (int i = 1; argv[i] != NULL; i++) {
		int nb = atoi(argv[i]);
		std::string	str(argv[i]);
		if (nb < 0 || str.find_first_not_of("0123456789+") != std::string::npos)
			throw std::invalid_argument("Error");
		vector.push_back(nb);
		deque.push_back(nb);
	}
	
	std::cout << "Before:\t";
	for (int i = 1; argv[i] != NULL; i++)
		std::cout << argv[i] << " "; 
	std::cout << std::endl << "After:\t";

    clock_t startTime = clock();

	std::vector<int> sVector = MergeInsertionSort(vector);
	clock_t endTimeV = clock();
	std::deque<int> sDeque = MergeInsertionSort(deque);
	clock_t endTimeD = clock();
	
	for (std::vector<int>::iterator it = sVector.begin(); it != sVector.end(); it++)
		std::cout << *it << " ";
	std::cout << std::endl;

	std::cout << "Time to process a range of " << sVector.size() << " elements with std::vector : " << elapsedTime(startTime, endTimeV) << " µs" << std::endl;
	std::cout << "Time to process a range of " << sDeque.size() << " elements with std::deque  : " << elapsedTime(startTime, endTimeD) << " µs" << std::endl;
}
