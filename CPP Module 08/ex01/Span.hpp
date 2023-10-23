/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laprieur <laprieur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 16:24:09 by laprieur          #+#    #+#             */
/*   Updated: 2023/10/23 16:41:10 by laprieur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP

#include <vector>

class Span {
	private:
		std::vector<unsigned int>	numbers;

	public:
		Span();
		Span(const Span& source);
		Span&	operator=(const Span& source);
		~Span();
		
		void			addNumber();
		unsigned int	shortestSpan() const;
		unsigned int	longestSpan() const;
};

#endif