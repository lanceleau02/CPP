/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laprieur <laprieur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 11:47:10 by laprieur          #+#    #+#             */
/*   Updated: 2023/10/12 18:13:05 by laprieur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

std::string ScalarConverter::_input;
char		ScalarConverter::_charValue;
int			ScalarConverter::_intValue;
float		ScalarConverter::_floatValue;
double		ScalarConverter::_doubleValue;

int	main(int argc, char **argv) {
	(void)argc;
	if (argv[1]) {
		ScalarConverter::setInput(argv[1]);
		ScalarConverter::convert();
	}
}