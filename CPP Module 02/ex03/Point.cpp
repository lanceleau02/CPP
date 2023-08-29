/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laprieur <laprieur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 13:30:24 by laprieur          #+#    #+#             */
/*   Updated: 2023/08/29 17:34:07 by laprieur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point() : _x(0.0f), _y(0.0f) {}

Point::Point(const float xValue, const float yValue) : _x(xValue), _y(yValue) {}

Point::Point(const Point& source) : _x(source.getX()), _y(source.getY()) {}

Point&	Point::operator=(const Point& source) {
	(void)source;
	return *this;
}

Point::~Point() {}

float	Point::getX() const {
	return this->_x.toFloat();
}

float	Point::getY() const {
	return this->_y.toFloat();
}
