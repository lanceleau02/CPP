/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laprieur <laprieur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 17:16:02 by laprieur          #+#    #+#             */
/*   Updated: 2023/09/18 14:10:32 by laprieur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CURE_HPP
# define CURE_HPP

class Cure : public AMateria {
	private:
	
	public:
		Cure();
		Cure(const Cure& source);	
		Cure&	operator=(const Cure& source);
		~Cure();

		virtual AMateria*	clone() const;
};

#endif