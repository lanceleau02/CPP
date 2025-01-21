/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laprieur <laprieur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 17:02:17 by laprieur          #+#    #+#             */
/*   Updated: 2023/10/04 11:28:48 by laprieur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

#include <fstream>

#include "AForm.hpp"

class ShrubberyCreationForm : public AForm {
	private:
		ShrubberyCreationForm();
	
	public:
		ShrubberyCreationForm(const std::string& target);
		ShrubberyCreationForm(const ShrubberyCreationForm& source);
		ShrubberyCreationForm&	operator=(const ShrubberyCreationForm& source);
		~ShrubberyCreationForm();
		
		void	ShrubberyCreation() const;
		void	execute(const Bureaucrat& executor) const;
};


#endif