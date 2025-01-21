/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laprieur <laprieur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 16:04:56 by laprieur          #+#    #+#             */
/*   Updated: 2023/09/08 16:05:20 by laprieur         ###   ########.fr       */
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
		~Fixed();
		
		int		getRawBits(void) const;
		int		toInt(void) const;
		float	toFloat(void) const;
		void	setRawBits(int const raw);
};

std::ostream&	operator<<(std::ostream& os, const Fixed& fp);

#endif
