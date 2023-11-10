/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laprieur <laprieur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 13:12:53 by laprieur          #+#    #+#             */
/*   Updated: 2023/11/10 12:11:57 by laprieur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

RPN::RPN() {

}

RPN::~RPN() {}

void	RPN::program(const char* str) {
	std::string	rpn(str);

	if (rpn.find_first_not_of("0123456789+-/* ") != std::string::npos)
			throw std::invalid_argument("Error");
	for (std::string::iterator it = rpn.begin(); it != rpn.end(); ++it) {
        char c = *it;
		char *s = &c;
        if (isdigit(*it) && it + 1 != rpn.end() && isdigit(*(it + 1)))
			throw std::invalid_argument("Error");
		else if (isdigit(*it))
			_stack.push(atoi(s));
    }
	while (!_stack.empty()) {
        std::cout << _stack.top() << " ";
		_stack.pop();
    }
}