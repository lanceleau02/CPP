/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laprieur <laprieur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 11:43:43 by laprieur          #+#    #+#             */
/*   Updated: 2023/11/16 13:40:42 by laprieur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>

#define UNDERLINE "\033[4m"
#define YELLOW	"\033[33m"
#define BLUE	"\033[34m"
#define NONE	"\033[0m"

std::vector<int>&	rSort(std::vector<int>& max) {
	bool isSorted = true;
	for (std::vector<int>::iterator it = max.begin(); it != max.end(); it++) {
		if (it + 1 != max.end() && *it > *(it + 1)) {
			isSorted = false;
			break ;
		}
	}
	if (isSorted || max.size() == 1)
		return max;
	
	static size_t	i = 0;
	
	if (max[i] > max[i + 1])
		std::swap(max[i], max[i + 1]);
	else
		i++;
	if (i < max.size())
		rSort(max);
	return max;
}

int	main(void) {
	std::cout << YELLOW << "+--------+ START: X and n initializations +--------+" << NONE << std::endl;
	std::cout << std::endl;
	
	int	array[9] = {5, 2, 9, 1, 7, 6, 3, 8, 4};
	std::vector<int>	X;
	for (size_t i = 0; i < sizeof(array) / sizeof(int); i++)
		X.push_back(array[i]);
	size_t	n = X.size();

	std::cout << "X = {";
	for (std::vector<int>::iterator it = X.begin(); it != X.end(); it++) {
		std::cout << *it;
		if (it + 1 != X.end())
			std::cout << ", ";
		else
			std::cout << "}" << std::endl;
	}
	std::cout << "n = " << n << std::endl;

	/* ************************************************************************** */
	
	std::cout << std::endl;
	std::cout << YELLOW << "+--------+ STEP 1: Group the elements of X into [n/2] pairs of elements +--------+" << NONE << std::endl;
	std::cout << std::endl;
	
	std::vector<std::vector<int> >	newX;
	newX.resize(n / 2 + n % 2);

    for (size_t i = 0; i < n; i += 2) {
        if (i + 1 < n) {
            newX[i / 2].push_back(X[i]);
            newX[i / 2].push_back(X[i + 1]);
        } else
            newX[i / 2].push_back(X[i]);
    }
	
	for (size_t i = 0; i < newX.size(); i++) {
        std::cout << "newX[" << i << "] = ";
        for (size_t j = 0; j < newX[i].size(); j++) {
            std::cout << newX[i][j] << " ";
        }
        std::cout << std::endl;
    }
	
	/* ************************************************************************** */

	std::cout << std::endl;
	std::cout << YELLOW << "+--------+ STEP 2: Determine greatest element in each pair +--------+" << NONE << std::endl;
	std::cout << std::endl;
	
	std::vector<int>	max;

	for (size_t i = 0; i < n / 2; i++) {
		if (newX[i][0] > newX[i][1])
			max.push_back(newX[i][0]);
		else	
			max.push_back(newX[i][1]);
    }
	
	std::cout << "Greatest elements in newX = ";
	for (std::vector<int>::iterator it = max.begin(); it != max.end(); it++)
		std::cout << *it << " ";
	std::cout << std::endl;
		
	/* ************************************************************************** */
	
	std::cout << std::endl;
	std::cout << YELLOW << "+--------+ STEP 3: Recursively sort the [n/2] larger elements from each pair +--------+" << NONE << std::endl;
	std::cout << std::endl;

	std::vector<int>	S;
	
	S = rSort(max);
	
	std::cout << "S = ";
	for (std::vector<int>::iterator it = S.begin(); it != S.end(); it++)
		std::cout << *it << " ";
	std::cout << std::endl;

	/* ************************************************************************** */
	
	std::cout << std::endl;
	std::cout << YELLOW << "+--------+ STEP 4: Recursively sort the [n/2] larger elements from each pair +--------+" << NONE << std::endl;
	std::cout << std::endl;
}