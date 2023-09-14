/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laprieur <laprieur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 15:22:46 by laprieur          #+#    #+#             */
/*   Updated: 2023/09/14 11:50:59 by laprieur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public virtual Animal {
	private:
		Brain*	_brain;
	
	public:
		Dog();
		Dog(const Dog& source);
		Dog&	operator=(const Dog& source);
		~Dog();

		Brain*	getBrain(void) const;
};

#endif