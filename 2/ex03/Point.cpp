/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: teando <teando@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 15:36:35 by teando            #+#    #+#             */
/*   Updated: 2025/06/03 16:12:33 by teando           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"
#include <iostream>

Point::Point() : _x(0), _y(0) {
	std::cerr << "[ Point ] Default constructor called" << std::endl;
}

Point::Point(float x, float y) : _x(x), _y(y) {
	std::cerr << "[ Point ] Param constructor called" << std::endl;
}

Point::Point(const Point &other) : _x(other._x), _y(other._y) {
	std::cerr << "[ Point ] Copy constructor called" << std::endl;
}

Point &Point::operator=(const Point &other) {
	std::cerr << "[ Point ] Assignment operator called (no‑op)" << std::endl;
	(void)other;  // _x, _y are const – nothing to assign
	return *this;
}

Point::~Point() {
	std::cerr << "[ Point ] Destructor called" << std::endl;
}

Fixed Point::getX() const { return _x; }
Fixed Point::getY() const { return _y; }
