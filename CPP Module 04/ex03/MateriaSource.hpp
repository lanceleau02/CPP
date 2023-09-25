/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laprieur <laprieur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 10:53:04 by laprieur          #+#    #+#             */
/*   Updated: 2023/09/25 10:18:28 by laprieur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP

#include "AMateria.hpp"
#include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource {
	private:
		AMateria	*_materias[4];
	
	public:
		MateriaSource();
		MateriaSource(const MateriaSource& source);
		MateriaSource& operator=(const MateriaSource& source);
		~MateriaSource();

		void learnMateria(AMateria* m);
		AMateria* createMateria(std::string const& type);
};

#endif