/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laprieur <laprieur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 15:24:49 by laprieur          #+#    #+#             */
/*   Updated: 2023/10/04 15:53:01 by laprieur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
# define INTERN_HPP

#include <string>

#include "AForm.hpp"

class Intern {
	public:
		Intern();
		Intern(const Intern& source);
		Intern& operator=(const Intern& source);
		~Intern();
		
		AForm*	makeForm(const std::string& formName, const std::string& formTarget);

		class InvalidFormNameException : public std::exception {
			public:
    			virtual const char* what() const throw();
		};
};

void	verifyFormName(const std::string& formName) const;

#endif