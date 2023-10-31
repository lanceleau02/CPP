/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laprieur <laprieur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 16:24:09 by laprieur          #+#    #+#             */
/*   Updated: 2023/10/31 14:56:12 by laprieur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP

#include <vector>
#include <stdexcept>
#include <algorithm>
#include <climits>

class Span {
	private:
		std::vector<int>	_numbers;

		Span();
	
	public:
		Span(unsigned int N);
		Span(const Span& source);
		Span&	operator=(const Span& source);
		~Span();

		int			getNumber(unsigned int idx) const;
		void		setNumber(unsigned int idx, int value);
		void		addNumber(int value);
		void		addNumbers(std::vector<int>::iterator begin, std::vector<int>::iterator end);
		long int	shortestSpan() const;
		long int	longestSpan() const;
};

#endif