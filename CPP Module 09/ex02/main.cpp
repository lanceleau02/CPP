/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laprieur <laprieur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 11:43:43 by laprieur          #+#    #+#             */
/*   Updated: 2023/11/21 14:51:06 by laprieur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>

#include "PmergeMe.hpp"

#define UNDERLINE "\033[4m"
#define YELLOW	"\033[33m"
#define BLUE	"\033[34m"
#define NONE	"\033[0m"

int	main(void) {
	std::vector<int> myVector;
    int initialValues[] = {5, 2, 9, 1, 7, 6, 3, 8, 4}; // Specify initial values
    myVector.assign(initialValues, initialValues + sizeof(initialValues) / sizeof(int));
	PmergeMe(myVector);
}
