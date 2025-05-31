/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: teando <teando@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/31 10:07:07 by teando            #+#    #+#             */
/*   Updated: 2025/05/31 10:55:23 by teando           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>

int main(void) {
	// Fixed a;
	// Fixed const b(Fixed(5.05f) * Fixed(2));
	// std::cout << a << std::endl;
	// std::cout << ++a << std::endl;
	// std::cout << a << std::endl;
	// std::cout << a++ << std::endl;
	// std::cout << a << std::endl;
	// std::cout << b << std::endl;
	// std::cout << Fixed::max(a, b) << std::endl;
	// return 0;

	Fixed a;
	Fixed const b(Fixed(5.05f) * Fixed(2));

	std::cout << "\n--- Testing comparison operators ---" << std::endl;
	Fixed c(10.5f);
	Fixed d(10.5f);
	Fixed e(5.05f);

	std::cout << "c == d: " << (c == d) << std::endl;
	std::cout << "c != d: " << (c != d) << std::endl;
	std::cout << "c > e: " << (c > e) << std::endl;
	std::cout << "c < e: " << (c < e) << std::endl;
	std::cout << "c >= d: " << (c >= d) << std::endl;
	std::cout << "c <= e: " << (c <= e) << std::endl;

	std::cout << "\n--- Testing arithmetic operators ---" << std::endl;
	Fixed f(12.5f);
	Fixed g(2.5f);

	std::cout << "f + g = " << (f + g) << std::endl;
	std::cout << "f - g = " << (f - g) << std::endl;
	std::cout << "f * g = " << (f * g) << std::endl;
	std::cout << "f / g = " << (f / g) << std::endl;

	std::cout << "\n--- Testing increment/decrement operators ---" <<
	std::endl; Fixed h(42.42f);

	std::cout << "h = " << h << std::endl;
	std::cout << "++h = " << ++h << std::endl;
	std::cout << "h = " << h << std::endl;
	std::cout << "h++ = " << h++ << std::endl;
	std::cout << "h = " << h << std::endl;
	std::cout << "--h = " << --h << std::endl;
	std::cout << "h = " << h << std::endl;
	std::cout << "h-- = " << h-- << std::endl;
	std::cout << "h = " << h << std::endl;

	std::cout << "\n--- Testing min and max functions ---" << std::endl;
	Fixed i(100.1f);
	Fixed j(200.2f);

	std::cout << "i = " << i << ", j = " << j << std::endl;
	std::cout << "min(i, j) = " << Fixed::min(i, j) << std::endl;
	std::cout << "max(i, j) = " << Fixed::max(i, j) << std::endl;

	// Testing with const values
	const Fixed k(300.3f);
	const Fixed l(400.4f);

	std::cout << "k = " << k << ", l = " << l << std::endl;
	std::cout << "min(k, l) = " << Fixed::min(k, l) << std::endl;
	std::cout << "max(k, l) = " << Fixed::max(k, l) << std::endl;

	std::cout << "\n--- Original test from subject ---" << std::endl;
	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;

	std::cout << b << std::endl;

	std::cout << Fixed::max(a, b) << std::endl;
	return 0;
}