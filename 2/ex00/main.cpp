/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: teando <teando@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 03:25:07 by teando            #+#    #+#             */
/*   Updated: 2025/05/30 21:40:24 by teando           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>

int main() {
	Fixed a;
	Fixed b(a);
	Fixed c;
	c = b;
	std::cout << a.getRawBits() << std::endl;
	std::cout << b.getRawBits() << std::endl;
	std::cout << c.getRawBits() << std::endl;

	a.setRawBits(42);
	std::cout << "\nAfter setting to 42: " << a.getRawBits() << std::endl;

	b.setRawBits(100);
	std::cout << "\nAfter changing copy to 100: " << b.getRawBits() << std::endl;
	std::cout << "\nOriginal value: " << a.getRawBits() << std::endl;

	a = b;
	std::cout << "\nAfter assignment: " << a.getRawBits() << std::endl;
	return 0;
}

/*

$ ./a.out
Default constructor called
Copy constructor called
Copy assignment operator called   // 実装によりこの行は省略される場合あり
getRawBits member function called
Default constructor called
Copy assignment operator called
getRawBits member function called
getRawBits member function called
0
getRawBits member function called
0
getRawBits member function called
0
Destructor called
Destructor called
Destructor called
$

*/