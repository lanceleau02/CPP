/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laprieur <laprieur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 13:54:08 by laprieur          #+#    #+#             */
/*   Updated: 2023/10/31 09:19:22 by laprieur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
# define ITER_HPP

#include <iostream>

template <typename T>
void	iter(T* array, size_t size, void (*function)(T&)) {
	for (size_t i = 0; i < size; i++)
		(*function)(array[i]);
}

template <typename T>
void	print(T& i) {
	std::cout << i;
}

#endif