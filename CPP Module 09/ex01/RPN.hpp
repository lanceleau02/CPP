/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laprieur <laprieur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 13:13:06 by laprieur          #+#    #+#             */
/*   Updated: 2023/11/09 15:06:22 by laprieur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
# define RPN_HPP

#include <stack>

class RPN {
	private:
		std::stack<int>	stack;

		RPN(const RPN& source);
		RPN&	operator=(const RPN& source);

	public:
		RPN();
		~RPN();
};

#endif