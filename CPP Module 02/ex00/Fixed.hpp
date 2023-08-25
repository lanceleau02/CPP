/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laprieur <laprieur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/25 14:18:28 by laprieur          #+#    #+#             */
/*   Updated: 2023/08/25 16:48:26 by laprieur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed {
	private:
		int					fpnValue;
		static const int	nbFractionalBits = 8;
	
	public:
		Fixed();
		Fixed(const Fixed& source);
		Fixed& operator=(const Fixed& source);
		~Fixed();
		
		int		getRawBits(void) const;
		//void	setRawBits(int const raw);
};

#endif