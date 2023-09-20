/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laprieur <laprieur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 10:52:35 by laprieur          #+#    #+#             */
/*   Updated: 2023/09/20 16:45:03 by laprieur         ###   ########.fr       */
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
		IMateriaSource*	materia = new MateriaSource();
		
		materia->learnMateria(new Ice());
		materia->learnMateria(new Cure());

		std::cout << std::endl << "equip() function tests:" << std::endl;
		
		ICharacter*		characterTest = new Character("characterTest");
		AMateria*		tmp[5];
		
		tmp[0] = materia->createMateria("ice");
		characterTest->equip(tmp[0]);
		tmp[1] = materia->createMateria("cure");
		characterTest->equip(tmp[1]);
		tmp[2] = materia->createMateria("ice");
		characterTest->equip(tmp[2]);
		tmp[3] = materia->createMateria("cure");
		characterTest->equip(tmp[3]);
		tmp[4] = materia->createMateria("ice");
		characterTest->equip(tmp[4]);
		
		std::cout << std::endl << "use() function tests:" << std::endl;
		
		ICharacter*		bob = new Character("bob");

		characterTest->use(0, *bob);
		characterTest->use(1, *bob);
		characterTest->use(2, *bob);
		characterTest->use(3, *bob);
		characterTest->use(4, *bob);

		std::cout << std::endl << "unequip() function tests:" << std::endl;

		characterTest->unequip(0);
		characterTest->unequip(1);
		characterTest->unequip(2);
		characterTest->unequip(3);
		characterTest->unequip(4);
		
		std::cout << std::endl;
		
		for (int i = 0; i < 4; i++)
			delete tmp[i];
		delete bob;
		delete characterTest;
		delete materia;
	}
	return 0;
}