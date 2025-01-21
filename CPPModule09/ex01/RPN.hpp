/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laprieur <laprieur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 13:13:06 by laprieur          #+#    #+#             */
/*   Updated: 2023/11/24 11:28:50 by laprieur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
# define RPN_HPP

#include <iostream>
#include <string>
#include <stack>
#include <cstdlib>
#include <sstream>

class RPN {
	private:
		static std::stack<int>	_stack;

		RPN();
		RPN(const RPN& source);
		RPN&	operator=(const RPN& source);
		~RPN();

	public:
		static void	program(const char* rpn);
};

#endif