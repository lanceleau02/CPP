/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laprieur <laprieur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 13:13:06 by laprieur          #+#    #+#             */
/*   Updated: 2023/11/10 12:11:08 by laprieur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
# define RPN_HPP

#include <iostream>
#include <string>
#include <stack>
#include <vector>
#include <exception>
#include <cctype>
#include <cstdlib>

class RPN {
	private:
		std::stack<int, std::vector<int> >	_stack;

		RPN(const RPN& source);
		RPN&	operator=(const RPN& source);

	public:
		RPN();
		~RPN();
		
void	program(const char* rpn);
void	parsing(const std::string& rpn);
};

#endif