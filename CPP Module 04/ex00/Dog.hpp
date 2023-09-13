/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laprieur <laprieur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 15:22:46 by laprieur          #+#    #+#             */
/*   Updated: 2023/09/12 09:37:42 by laprieur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP

#include "Animal.hpp"

class Dog : public virtual Animal {
	private:
	
	public:
		Dog();
		Dog(const Dog& source);
		Dog&	operator=(const Dog& source);
		~Dog();
};

#endif