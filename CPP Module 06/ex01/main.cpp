/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laprieur <laprieur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 13:44:27 by laprieur          #+#    #+#             */
/*   Updated: 2023/10/19 11:30:57 by laprieur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

#define RED		"\033[31m"
#define GREEN	"\033[32m"

int	main(void) {
	Data		obj;
	Data*		ptr = &obj;
	uintptr_t	serialized = Serializer::serialize(ptr);
	Data*		deserialized = Serializer::deserialize(serialized);

	if (ptr == deserialized)
		std::cout << GREEN << "Success!" << std::endl;
	else
		std::cout << RED << "Fail!" << std::endl;
	return (0);
}