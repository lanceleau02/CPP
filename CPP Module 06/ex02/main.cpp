/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laprieur <laprieur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 15:01:37 by laprieur          #+#    #+#             */
/*   Updated: 2023/10/18 16:40:29 by laprieur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

#include <iostream>
#include <cstdlib>
#include <ctime>

Base*	generate(void) {
	switch (std::rand() % 3) {
		case 0:
			return (new A);
		case 1:
			return (new B);
		default:
			return (new C);
	}
}

/* void	identify(Base* p) {

} */

int	main(void) {
	std::srand(std::time(NULL));
	
	Base*	a = generate();
	
	std::cout << &a << std::endl;
}