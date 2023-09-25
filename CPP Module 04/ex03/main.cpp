/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laprieur <laprieur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 10:52:35 by laprieur          #+#    #+#             */
/*   Updated: 2023/09/25 14:20:31 by laprieur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"
#include "Cure.hpp"
#include "Ice.hpp"
#include "MateriaSource.hpp"

int main()
{
	std::cout << YELLOW << "+--------+ SUBJECT TESTS +--------+" << NONE << std::endl;
	std::cout << std::endl;
	{
		std::cout << "learnMateria() function tests:" << std::endl;
		
		IMateriaSource* src = new MateriaSource();
		src->learnMateria(new Ice());
		src->learnMateria(new Cure());
		
		std::cout << std::endl << "equip() function tests:" << std::endl;
		
		ICharacter* me = new Character("me");
		
		AMateria* tmp;
		tmp = src->createMateria("ice");
		me->equip(tmp);
		tmp = src->createMateria("cure");
		me->equip(tmp);
		
		std::cout << std::endl << "use() function tests:" << std::endl;
		
		ICharacter* bob = new Character("bob");
		
		me->use(0, *bob);
		me->use(1, *bob);

		std::cout << std::endl;
		
		delete bob;
		delete me;
		delete src;
	}
	std::cout << std::endl;
	std::cout << YELLOW << "+--------+ CHARACTER CLASS TESTS +--------+" << NONE << std::endl;
	std::cout << std::endl;
	{
		IMateriaSource*	src = new MateriaSource();
		
		src->learnMateria(new Ice());
		src->learnMateria(new Cure());

		std::cout << std::endl << "equip() function tests:" << std::endl;
		
		ICharacter*		me = new Character("me");
		AMateria*		tmp[5];
		
		for (int i = 0; i < 5; i++) {
			if (i % 2 == 0)
				tmp[i] = src->createMateria("ice");
			else
				tmp[i] = src->createMateria("cure");
			me->equip(tmp[i]);
		}
		
		std::cout << std::endl << "use() function tests:" << std::endl;
		
		ICharacter*		bob = new Character("bob");

		for (int i = 0; i < 5; i++)
			me->use(i, *bob);

		std::cout << std::endl << "unequip() function tests:" << std::endl;

		for (int i = 0; i < 5; i++)
			me->unequip(i);
		
		std::cout << std::endl;
		
		for (int i = 0; i < 5; i++)
			delete tmp[i];
		delete bob;
		delete me;
		delete src;
	}
	std::cout << std::endl;
	std::cout << YELLOW << "+--------+ MATERIASOURCE CLASS TESTS +--------+" << NONE << std::endl;
	std::cout << std::endl;
	{
		std::cout << "learnMateria() function tests:" << std::endl;
		
		IMateriaSource*	src = new MateriaSource();
		AMateria*		ice = new Ice();
		
		for (int i = 0; i < 4; i++) {
			if (i % 2 == 0)
				src->learnMateria(new Ice());
			else
				src->learnMateria(new Cure());
		}
		src->learnMateria(ice);
		
		std::cout << std::endl << "createMateria() function tests:" << std::endl;
		
		AMateria*	tmp[5];
		
		for (int i = 0; i < 5; i++)
			tmp[i] = src->createMateria("cure");

		std::cout << std::endl;

		for (int i = 0; i < 5; i++)
			delete tmp[i];
		delete ice;
		delete src;
	}
	return 0;
}