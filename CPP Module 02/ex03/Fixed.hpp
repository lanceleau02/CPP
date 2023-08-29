/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laprieur <laprieur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/25 14:18:28 by laprieur          #+#    #+#             */
/*   Updated: 2023/08/29 13:56:43 by laprieur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed {
	private:
		int					_rawBits;
		static const int	_nbFractionalBits = 8;
	
	public:
		Fixed();
		Fixed(const int param);
		Fixed(const float param);
		Fixed(const Fixed& source);
		Fixed&	operator=(const Fixed& source);

		bool	operator>(const Fixed& source);
		bool	operator<(const Fixed& source);
		bool	operator>=(const Fixed& source);
		bool	operator<=(const Fixed& source);
		bool	operator==(const Fixed& source);
		bool	operator!=(const Fixed& source);

		Fixed	operator+(const Fixed& source);
		Fixed	operator-(const Fixed& source);
		Fixed	operator*(const Fixed& source);
		Fixed	operator/(const Fixed& source);

		Fixed&	operator++(void);
		Fixed	operator++(int);
		Fixed&	operator--(void);
		Fixed	operator--(int);
		~Fixed();

		int					getRawBits(void) const;
		int					toInt(void) const;
		float				toFloat(void) const;
		void				setRawBits(int const raw);
		static Fixed&		min(Fixed& f1, Fixed& f2);
		static const Fixed&	min(const Fixed& f1, const Fixed& f2);
		static Fixed&		max(Fixed& f1, Fixed& f2);
		static const Fixed&	max(const Fixed& f1, const Fixed& f2);
};

std::ostream&	operator<<(std::ostream& os, const Fixed& fp);

#endif