/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: teando <teando@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/31 10:07:07 by teando            #+#    #+#             */
/*   Updated: 2025/06/03 16:07:44 by teando           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"
#include <iostream>

// bsp prototype (implemented in bsp.cpp)
bool bsp(Point const a, Point const b, Point const c, Point const point);

static void test(Point const &a, Point const &b, Point const &c, Point const &p) {
	std::cout	<< "P(" << p.getX() << ", " << p.getY() << ") inside? => "
				<< (bsp(a, b, c, p) ? "YES" : "NO") << std::endl;
}

int main() {
	Point A(0.0f, 0.0f);
	Point B(10.0f, 0.0f);
	Point C(0.0f, 10.0f);

	std::cout << "\n=== BSP simple tests ===" << std::endl;
	test(A, B, C, Point(2.0f, 2.0f));    // inside → YES
	test(A, B, C, Point(5.0f, 0.0f));    // edge   → NO
	test(A, B, C, Point(0.0f, 0.0f));    // vertex → NO
	test(A, B, C, Point(20.0f, 20.0f));  // outside→ NO

	return 0;
}
