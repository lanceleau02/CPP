/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laprieur <laprieur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 17:16:02 by laprieur          #+#    #+#             */
/*   Updated: 2023/09/19 15:36:26 by laprieur         ###   ########.fr       */
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

		virtual AMateria* clone() const;
    	virtual void use(ICharacter& target);
};

#endif