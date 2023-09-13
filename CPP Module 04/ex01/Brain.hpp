/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laprieur <laprieur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 11:15:23 by laprieur          #+#    #+#             */
/*   Updated: 2023/09/13 16:11:32 by laprieur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
# define BRAIN_HPP

#include <string>
#include <iostream>

#define RED		"\033[31m"
#define GREEN	"\033[32m"
#define NONE	"\033[0m"

class Brain {
	private:
		std::string	_ideas[100];

	public:
		Brain();
		Brain(const Brain& source);
		Brain(const std::string& idea);
		Brain&	operator=(const Brain& source);
		~Brain();
		
		void		setIdea(int index, const std::string& idea);
		std::string	getIdea(int index);
};

#endif