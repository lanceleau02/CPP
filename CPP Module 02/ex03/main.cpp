/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laprieur <laprieur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/25 14:47:26 by laprieur          #+#    #+#             */
/*   Updated: 2023/08/29 17:48:07 by laprieur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

void	print(Point a, Point b, Point c, Point p) {
	std::cout << "Coordinates:" << std::endl;
	std::cout << "a(" << a.getX() << "," << a.getY() << ")" << std::endl;
	std::cout << "b(" << b.getX() << "," << b.getY() << ")" << std::endl;
	std::cout << "c(" << c.getX() << "," << c.getY() << ")" << std::endl;
	std::cout << "p(" << p.getX() << "," << p.getY() << ")" << std::endl;
	std::cout << std::endl;
	
	if (bsp(a, b, c, p) == true)
		std::cout << "The point lies in the triangle!" << std::endl;
	else
		std::cout << "The point isn't in the triangle!" << std::endl;
	std::cout << std::endl;
}

int	main(void) {
	// Point lies in the triangle
	Point	a1;
	Point	b1(0.0, 3.0);
	Point	c1(3.0, 0.0);
	Point	p1(1.0, 1.0);

	print(a1, b1, c1, p1);

	// Point isn't in the triangle
	Point	a2;
	Point	b2(0.0, 3.0);
	Point	c2(3.0, 0.0);
	Point	p2(2.0, 2.0);
	
	print(a2, b2, c2, p2);
	
	// Point is on an edge
	Point	a3;
	Point	b3(0.0, 3.0);
	Point	c3(3.0, 0.0);
	Point	p3(1.0, 2.0);
	
	print(a3, b3, c3, p3);
	
	// Point is a vertex
	Point	a4;
	Point	b4(0.0, 3.0);
	Point	c4(3.0, 0.0);
	Point	p4(3.0, 0.0);
	
	print(a4, b4, c4, p4);
}