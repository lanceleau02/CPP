/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laprieur <laprieur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 11:40:55 by laprieur          #+#    #+#             */
/*   Updated: 2023/11/20 16:41:06 by laprieur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

std::vector<int>::iterator	binarySearch(std::vector<int> A, size_t n, int T) {
	int	L = 0;
	int	R = n - 1;
	
	while (L <= R) {
		int m = floor((L + R) / 2);
		if (A[m] < T)
			L = m + 1;
		else if (A[m] > T)
			R = m - 1;
		else
			return A.begin() + m;
	}
	std::vector<int>::iterator it = A.begin();
	std::advance(it, L);
	return it;
}

std::vector<std::pair<int, int> >::iterator findElement(std::vector<std::pair<int, int> >& pairs, int target) {
	for (std::vector<std::pair<int, int> >::iterator it; it != pairs.end(); it++) {
		if (it->first == target)
			return it;
	}
	return (pairs.end());
}

std::vector<int>	PmergeMe(std::vector<int> X) {
	size_t				n = X.size();
	std::vector<std::pair<int, int> > pairs;
	std::vector<int>	S;
	
	if (n == 1)
		return X;

	// STEP 1: Group the elements of X into [n/2] pairs of elements
	std::cout << std::endl;
	std::cout << "STEP 1: Group the elements of X into [n/2] pairs of elements" << std::endl;
	std::cout << std::endl;

	for (std::vector<int>::iterator it = X.begin(); it != X.end(); it += 2) {
		std::pair<int, int> pair;
		if (it + 1 == X.end())
			break ;
		pair.first = (*it > *(it + 1)) ? *it : *(it + 1);
		pair.second = (*it < *(it + 1)) ? *it : *(it + 1);
		pairs.push_back(pair);
	}

	for (std::vector<std::pair<int, int> >::iterator it = pairs.begin(); it != pairs.end(); it++) {
		std::cout << "(" << it->first << ", " << it->second << ")" << std::endl;
	}
	
	// STEP 2: Perform [n/2] comparisons, one per pair, to determine the larger of the two elements in each pair.
	std::cout << std::endl;
	std::cout << "STEP 2: Perform [n/2] comparisons, one per pair, to determine the larger of the two elements in each pair." << std::endl;
	std::cout << std::endl;

	for (std::vector<std::pair<int, int> >::iterator it = pairs.begin(); it != pairs.end(); it++) {
		if (it->first > it->second)
			S.push_back(it->first);
		else
			S.push_back(it->second);
	}
	
	std::cout << "S = ";
	for (std::vector<int>::iterator it = S.begin(); it != S.end(); it++)
		std::cout << *it << " ";
	std::cout << std::endl;
	
	// STEP 3: Recursively sort the [n/2] larger elements from each pair
	std::cout << std::endl;
	std::cout << "STEP 3: Recursively sort the [n/2] larger elements from each pair" << std::endl;
	std::cout << std::endl;

	S = PmergeMe(S);

	std::cout << "S = ";
	for (std::vector<int>::iterator it = S.begin(); it != S.end(); it++)
		std::cout << *it << " ";
	std::cout << std::endl;

	// STEP 4: Insert at the start of S the element that was paired with the first and smallest element of S.
	std::cout << std::endl;
	std::cout << "STEP 4: Insert at the start of S the element that was paired with the first and smallest element of S." << std::endl;
	std::cout << std::endl;

	std::vector<std::pair<int, int> >::iterator	it = findElement(pairs, S.front());
	
	S.insert(S.begin(), it->second);

/* 	if (pairs[0][0] < pairs[0][1]) {
		S.insert(S.begin(), pairs[0][0]);
	}
	else {
		S.insert(S.begin(), pairs[0][1]);
	} */

	std::cout << "S = ";
	for (std::vector<int>::iterator it = S.begin(); it != S.end(); it++)
		std::cout << *it << " ";
	std::cout << std::endl;
	
/* 	// STEP 5: Insert the remaining [n/2] - 1 elements of X\S into S, one at a time
	
	for (std::vector<int>::iterator it = pairs.begin(); it != pairs.end(); it++)
		S.insert(binarySearch(S, S.size(), it->second), it->second);

	std::cout << "S = ";
	for (std::vector<int>::iterator it = S.begin(); it != S.end(); it++)
		std::cout << *it << " ";
	std::cout << std::endl;
		
	for (size_t i = 0; i < pairs.size(); i++)
		S.insert(binarySearch(S, S.size(), pairs[i][0]), pairs[i][0]); */

	return S;
}