/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laprieur <laprieur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 16:24:09 by laprieur          #+#    #+#             */
/*   Updated: 2023/10/26 16:38:34 by laprieur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP

#include <vector>
#include <stdexcept>
#include <algorithm>

class Span {
	private:
		std::vector<unsigned int>	_numbers;
		unsigned int				_idx;

		Span();
	
	public:
		Span(unsigned int n);
		Span(const Span& source);
		Span&	operator=(const Span& source);
		~Span();
		
		void			addNumber(unsigned int value);
		unsigned int	shortestSpan() const;
		unsigned int	longestSpan() const;
};

#endif