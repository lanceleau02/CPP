/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laprieur <laprieur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 11:15:15 by laprieur          #+#    #+#             */
/*   Updated: 2023/09/14 11:52:43 by laprieur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain() {
	std::cout << GREEN << "Brain class Default constructor called!" << NONE << std::endl;
	for (int i = 0; i < 100; i++)
		setIdea(i, "Something...");
}

Brain::Brain(const std::string& idea) {
	std::cout << GREEN << "Brain class Ideas constructor called!" << NONE << std::endl;
	for (int i = 0; i < 100; i++)
		setIdea(i, idea);
}

Brain::Brain(const Brain& source) {
	std::cout << GREEN << "Brain class Copy constructor called!" << NONE << std::endl;
	*this = source;
}

Brain&	Brain::operator=(const Brain& source) {
	std::cout << GREEN << "Brain class Assignment operator called!" << NONE << std::endl;
	for (int i = 0; i < 100; i++)
		_ideas[i] = source._ideas[i];
	return *this;
}

Brain::~Brain() {
	std::cout << RED << "Brain class Default destructor called!" << NONE << std::endl;
}

void	Brain::setIdea(int index, const std::string& idea) {
	if (index < 0 || index > 99)
		return ;
	_ideas[index] = idea;
}

std::string Brain::getIdea(int index) const {
	if (index < 0 || index > 99)
		return ("");
	return _ideas[index];
}
