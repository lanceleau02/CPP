/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laprieur <laprieur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 13:44:27 by laprieur          #+#    #+#             */
/*   Updated: 2023/10/18 14:29:04 by laprieur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

int	main(void) {
	Data		obj;
	Data*		ptr = &obj;
	uintptr_t	serialized = Serializer::serialize(ptr);
	Data*		deserialized = Serializer::deserialize(serialized);

	if (ptr == deserialized)
		std::cout << "Success!" << std::endl;
	else
		std::cout << "Fail!" << std::endl;
}