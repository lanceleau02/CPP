/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laprieur <laprieur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 09:36:12 by laprieur          #+#    #+#             */
/*   Updated: 2023/10/20 11:43:54 by laprieur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
# define ARRAY_HPP

template <typename T>
class Array {
	private:
		T*				_array;
		unsigned int	_size;

	public:
		Array();
		Array(unsigned int n);
		Array(const Array& source);
		Array&	operator=(const Array& source);
		T&		operator[](unsigned int idx);
		~Array();
		
		unsigned int	size() const;
		
		class IndexIsOutOfBoundsException : public std::exception {
			public:
    			virtual const char* what() const throw();
		};
};

#include "Array.tpp"

#endif