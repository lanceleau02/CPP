/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laprieur <laprieur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 11:40:55 by laprieur          #+#    #+#             */
/*   Updated: 2023/11/22 15:09:25 by laprieur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

std::vector<int>::iterator	binarySearch(std::vector<int>& A, int L, int R, int T) {	
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
	for (std::vector<std::pair<int, int> >::iterator it = pairs.begin(); it != pairs.end(); it++) {
		if (it->first == target)
			return it;
	}
	return (pairs.end());
}

int	Jacobsthal(int n) {
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

std::vector<int>	PmergeMe(std::vector<int> X) {
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
	S = PmergeMe(S);
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
