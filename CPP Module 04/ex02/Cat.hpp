/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laprieur <laprieur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 15:22:46 by laprieur          #+#    #+#             */
/*   Updated: 2023/09/14 11:54:40 by laprieur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP

#include "AAnimal.hpp"
#include "Brain.hpp"

class Cat : public virtual AAnimal {
	private:
		Brain*	_brain;

	public:
		Cat();
		Cat(const Cat& source);
		Cat&	operator=(const Cat& source);
		~Cat();
		
		Brain*	getBrain(void) const;
		void	makeSound(void) const;
};

#endif