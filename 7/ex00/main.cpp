/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: teando <teando@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 18:33:10 by teando            #+#    #+#             */
/*   Updated: 2025/09/01 21:20:09 by teando           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "whatever.hpp"

int main( void ) {
	int a = 0x42;
	int b = 042;
	std::cout << "Before: a = " << a << ", b = " << b << "\n";
	::swap( a, b );
	std::cout << "After : a = " << a << ", b = " << b << "\n";
	std::cout << "min( a, b ) = " << ::min( a, b ) << "\n";
	std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl;

	std::string c = "Hello World!";
	std::string d = "The world is Undefined";
	std::cout << "\nBefore: c = " << c << ", d = " << d << "\n";
	::swap(c, d);
	std::cout << "After : c = " << c << ", d = " << d << "\n";
	std::cout << "min( c, d ) = " << ::min( c, d ) << "\n";
	std::cout << "max( c, d ) = " << ::max( c, d ) << std::endl;
	return 0;
}
