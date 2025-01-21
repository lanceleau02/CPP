/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laprieur <laprieur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 13:12:53 by laprieur          #+#    #+#             */
/*   Updated: 2023/11/27 11:42:25 by laprieur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

std::stack<int>	RPN::_stack;

static int	operate(int nb1, int nb2, char op) {
	return (op == '+') ? nb1 + nb2 : (op == '-') ? nb1 - nb2 : (op == '*') ? nb1 * nb2 : (op == '/') ? nb1 / nb2 : 0;
}

void	RPN::program(const char* str) {
	std::string	rpn(str);

	if (rpn.find_first_not_of("0123456789+-/* ") != std::string::npos)
			throw std::invalid_argument("Error");
	for (std::string::iterator it = rpn.begin(); it != rpn.end(); ++it) {
        char c = *it;
		char *s = &c;
        if (isdigit(c) && it + 1 != rpn.end() && isdigit(*(it + 1)))
			throw std::invalid_argument("Error: invalid value(s)");
		else if (isdigit(c))
			_stack.push(atoi(s));
		if (_stack.size() > 1 && (c == '+' || c == '-' || c == '/' || c == '*')) {
			int nb2 = _stack.top();
			if (nb2 == 0 && c == '/')
				throw std::runtime_error("Error: division by zero");
			_stack.pop();
			int nb1 = _stack.top();
			_stack.pop();
			_stack.push(operate(nb1, nb2, c));
		}
	}
	if (!_stack.empty() && _stack.size() == 1)
		std::cout << _stack.top() << std::endl;
	else if (!_stack.empty())
		throw std::runtime_error("Error");
}