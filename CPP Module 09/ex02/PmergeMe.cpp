/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laprieur <laprieur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 11:40:55 by laprieur          #+#    #+#             */
/*   Updated: 2023/11/22 14:52:50 by laprieur         ###   ########.fr       */
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
		S.push_back(pair.first);
	}

	for (std::vector<std::pair<int, int> >::iterator it = pairs.begin(); it != pairs.end(); it++) {
		std::cout << "(" << it->first << ", " << it->second << ")" << std::endl;
	}
	
	// STEP 2: Perform [n/2] comparisons, one per pair, to determine the larger of the two elements in each pair.
	std::cout << std::endl;
	std::cout << "STEP 2: Perform [n/2] comparisons, one per pair, to determine the larger of the two elements in each pair." << std::endl;
	std::cout << std::endl;
	
	std::cout << "S = ";
	for (std::vector<int>::iterator it = S.begin(); it != S.end(); it++)
		std::cout << *it << " ";
	std::cout << std::endl;
	
	// STEP 3: Recursively sort the [n/2] larger elements from each pair
	std::cout << std::endl;
	std::cout << "STEP 3: Recursively sort the [n/2] larger elements from each pair" << std::endl;
	std::cout << std::endl;

	S = PmergeMe(S);
	std::vector<int>	copyS(S);
	copyS.erase(copyS.begin());

	std::cout << "Sorted = ";
	for (std::vector<int>::iterator it = S.begin(); it != S.end(); it++)
		std::cout << *it << " ";
	std::cout << std::endl;

	// STEP 4: Insert at the start of S the element that was paired with the first and smallest element of S.
	std::cout << std::endl;
	std::cout << "STEP 4: Insert at the start of S the element that was paired with the first and smallest element of S." << std::endl;
	std::cout << std::endl;

	std::vector<std::pair<int, int> >::iterator	it = findElement(pairs, S.front());
	
	S.insert(S.begin(), it->second);
	pairs.erase(it);

	std::cout << "S = ";
	for (std::vector<int>::iterator it = S.begin(); it != S.end(); it++)
		std::cout << *it << " ";
	std::cout << std::endl;

	std::cout << "copyS = ";
	for (std::vector<int>::iterator it = copyS.begin(); it != copyS.end(); it++)
		std::cout << *it << " ";
	std::cout << std::endl;

	// Jacobsthal

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
	
	std::cout << "copyS = ";
	for (std::vector<int>::iterator it = copyS.begin(); it != copyS.end(); it++)
		std::cout << *it << " ";
	std::cout << std::endl;

	// STEP 5: Insert the remaining [n/2] - 1 elements of X\S into S, one at a time
	
/* 	for (std::vector<int>::iterator it = group.begin() + 1; it != group.end(); it++) {
		std::vector<std::pair<int, int> >::iterator	min = findElement(pairs, *it);
		S.insert(binarySearch(S, 0, S.size() - 1, min->second), min->second);
		pairs.erase(min);
	} */

	std::cout << "S = ";
	for (std::vector<int>::iterator it = S.begin(); it != S.end(); it++)
		std::cout << *it << " ";
	std::cout << std::endl;

	if (X.size() % 2 != 0) {
		std::cout << "inserting rest:" << *(X.end() - 1) << std::endl;
		S.insert(binarySearch(S, 0, S.size() - 1, *(X.end() - 1)), *(X.end() - 1));
	}

	std::cout << "S = ";
	for (std::vector<int>::iterator it = S.begin(); it != S.end(); it++)
		std::cout << *it << " ";
	std::cout << std::endl;

	return S;
}

/*
La suite de Jacobsthal va nous servir à créer des paquets de 2, 2, 6, 10, 22, 42... minimums
en suivant l'ordre des maximums triés.

Exemple :

Pour la suite {5, 2, 9, 1, 7, 6, 3, 8, 4}, les maximums triés sont : 5, 7, 8, 9.

Le minimum associé à 5 (2) est déjà inséré donc on va commencer à partir de 7
et insérer les 2 minimums de 7 et 8 en commençant par la fin, donc on obtient : 2, 3, 5, 6, 7, 8, 9.
*/