/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laprieur <laprieur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 11:43:43 by laprieur          #+#    #+#             */
/*   Updated: 2023/11/22 14:52:05 by laprieur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime> 

#include "PmergeMe.hpp"

int	main(void) {
	std::vector<int> myVector;
	const int arraySize = 10;
    int initialValues[arraySize];

    std::srand(static_cast<unsigned int>(std::time(NULL)));
    for (int i = 0; i < arraySize; ++i) {
        initialValues[i] = std::rand();
    }
    myVector.assign(initialValues, initialValues + sizeof(initialValues) / sizeof(int));
	PmergeMe(myVector);
}
