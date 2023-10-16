/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laprieur <laprieur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 17:22:35 by laprieur          #+#    #+#             */
/*   Updated: 2023/10/09 14:30:02 by laprieur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target) : AForm("ShrubberyCreation", 145, 137, target) {}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& source) : AForm(source) {
	*this = source;
}

ShrubberyCreationForm&	ShrubberyCreationForm::operator=(const ShrubberyCreationForm& source) {
	if (this != &source)
		_signed = source._signed;
	return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

void	ShrubberyCreationForm::ShrubberyCreation() const {
	std::ifstream	infile;
	std::ofstream	outfile;

	infile.open("trees.txt");
	outfile.open((_target + "_shrubbery").c_str());
	if (infile.is_open() == false || outfile.is_open() == false) {
		std::cerr << "Error: Impossible to open the file!" << std::endl;
		return ;
	}
	outfile << infile.rdbuf();
	infile.close();
	outfile.close();
}

void	ShrubberyCreationForm::execute(const Bureaucrat& executor) const {
	if (_signed == true && executor.getGrade() <= _gradeToExecute)
		this->ShrubberyCreation();
	else if (_signed == false && executor.getGrade() <= _gradeToExecute)
		throw AForm::FormNotSignedException();
	else
		throw Bureaucrat::GradeTooLowException();
}