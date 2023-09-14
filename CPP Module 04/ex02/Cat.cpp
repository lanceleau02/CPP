/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laprieur <laprieur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 16:36:43 by laprieur          #+#    #+#             */
/*   Updated: 2023/09/14 11:54:43 by laprieur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat() {
	std::cout << GREEN << "Cat class Default constructor called!" << NONE << std::endl;
	_type = "Cat";
	_brain = new Brain();
}

Cat::Cat(const Cat& source) : AAnimal(source) {
	std::cout << GREEN << "Cat class Copy constructor called!" << NONE << std::endl;
	_brain = new Brain();
	*this = source;
}

Cat&	Cat::operator=(const Cat& source) {
	std::cout << GREEN << "Cat class Assignment operator called!" << NONE << std::endl;
	_type = source._type;
	*_brain = *source._brain;
	return *this;
}

Cat::~Cat() {
	std::cout << RED << "Cat class Default destructor called!" << NONE << std::endl;
	delete _brain;
}

Brain*	Cat::getBrain(void) const {
	return _brain;
}

void	Cat::makeSound(void) const {
	std::cout << BLUE << "Meow!" << NONE << std::endl;
}
