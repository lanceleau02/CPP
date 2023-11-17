/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laprieur <laprieur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 11:40:55 by laprieur          #+#    #+#             */
/*   Updated: 2023/11/17 15:59:57 by laprieur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

std::vector<int>::iterator	binarySearch(std::vector<int> A, size_t n, int T) {
	int	L = 0;
	int	R = n - 1;
	
	while (L <= R) {
		int m = floor((L + R) / 2);
		if (S[m] < T)
			L = m + 1;
		else if (S[m] > T)
			R = m - 1;
	}
	std::vector<int>::iterator it = S.begin();
	std::advance(it, L);
	return it;
}

std::vector<int>	PmergeMe(std::vector<int> X) {
	size_t				n = X.size();
	std::vector<std::vector<int> > pairs;
	pairs.resize(n / 2 + n % 2);
	std::vector<int>	S;
	
	if (n == 1)
		return X;

	// STEP 1: Group the elements of X into [n/2] pairs of elements

	for (size_t i = 0; i < n; i += 2) {
		std::vector<int> pair;
		pair.push_back(X[i]);
		if (i + 1 < n)
			pair.push_back(X[i + 1]);
		pairs[i / 2] = pair;
	}
	for (size_t i = 0; i < pairs.size(); i++) {
		std::cout << "pairs[" << i << "] = ";
		for (size_t j = 0; j < pairs[i].size(); j++) {
			std::cout << pairs[i][j] << " ";
		}
		std::cout << std::endl;
	}
	
	// STEP 2: Perform [n/2] comparisons, one per pair, to determine the larger of the two elements in each pair.
	
	for (size_t i = 0; i < n / 2; i++) {
		if (pairs[i][0] > pairs[i][1])
			S.push_back(pairs[i][0]);
		else
			S.push_back(pairs[i][1]);
	}
	std::cout << "S = ";
	for (std::vector<int>::iterator it = S.begin(); it != S.end(); it++)
		std::cout << *it << " ";
	std::cout << std::endl;
	
	// STEP 3: Recursively sort the [n/2] larger elements from each pair

	S = PmergeMe(S);

	std::cout << "S = ";
	for (std::vector<int>::iterator it = S.begin(); it != S.end(); it++)
		std::cout << *it << " ";
	std::cout << std::endl;
	
	// STEP 4: Insert at the start of S the element that was paired with the first and smallest element of S.
	
	if (pairs[0][0] < pairs[0][1])
		S.insert(S.begin(), pairs[0][0]);
	else
		S.insert(S.begin(), pairs[0][1]);

	std::cout << "S = ";
	for (std::vector<int>::iterator it = S.begin(); it != S.end(); it++)
		std::cout << *it << " ";
	std::cout << std::endl;
	
	// STEP 5: Insert the remaining [n/2] - 1 elements of X\S into S, one at a time
	
	for (std::vector<int>::iterator it = pairs.begin(); it != pairs.end(); it++)
		S.insert(binarySearch(S, S.size(), ))

	return X;
}