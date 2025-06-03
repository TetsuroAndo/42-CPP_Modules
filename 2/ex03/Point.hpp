/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: teando <teando@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 15:36:45 by teando            #+#    #+#             */
/*   Updated: 2025/06/03 16:06:03 by teando           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
#define POINT_HPP
#include "Fixed.hpp"
#include <iostream>

class Point {
private:
	Fixed _x;
	Fixed _y;

public:
	Point();
	Point(float x, float y);
	Point(const Point &other);
	Point &operator=(const Point &other);
	~Point();

	Fixed getX() const;
	Fixed getY() const;
};

#endif // POINT_HPP