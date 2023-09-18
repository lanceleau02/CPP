/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laprieur <laprieur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 17:16:02 by laprieur          #+#    #+#             */
/*   Updated: 2023/09/18 15:30:30 by laprieur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CURE_HPP
# define CURE_HPP

#include "AMateria.hpp"

class Cure : public AMateria {
	private:
	
	public:
		Cure();
		Cure(const Cure& source);	
		Cure&	operator=(const Cure& source);
		~Cure();

		std::string const& getType() const;
		virtual AMateria* clone() const;
    	virtual void use(ICharacter& target);
};

#endif