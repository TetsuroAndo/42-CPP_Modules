/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: teando <teando@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/04 00:06:03 by teando            #+#    #+#             */
/*   Updated: 2025/09/04 17:52:51 by teando           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

#include <iostream>
#include <cstdlib>
#include <ctime>

int main() {
	std::cout << "## PDF Main Test ##" << std::endl;
	try {
		Span sp = Span(5);
		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);

		std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
		std::cout << "Longest span: " << sp.longestSpan() << std::endl;
	} catch (const std::exception& e) {
		std::cerr << "Exception: " << e.what() << std::endl;
	}
	std::cout << "------------------------------------------" << std::endl << std::endl;

	std::cout << "## Large Scale Test (15,000 numbers) ##" << std::endl;
	try {
		const unsigned int numElements = 15000;
		Span sp_large(numElements);

		std::vector<int> source_numbers;
		source_numbers.reserve(numElements);

		srand(time(NULL));
		for (unsigned int i = 0; i < numElements; ++i) {
			if (rand() % 2 == 0) {
				source_numbers.push_back(-rand());
			} else {
				source_numbers.push_back(rand());
			}
		}

		sp_large.addRange(source_numbers.begin(), source_numbers.end());

		std::cout << "Successfully added " << numElements << " numbers." << std::endl;
		std::cout << "Shortest span: " << sp_large.shortestSpan() << std::endl;
		std::cout << "Longest span: " << sp_large.longestSpan() << std::endl;

	} catch (const std::exception& e) {
		std::cerr << "Exception: " << e.what() << std::endl;
	}
	std::cout << "------------------------------------------" << std::endl << std::endl;

	std::cout << "## Overflow Tests ##" << std::endl;
	try {
		Span sp_overflow(2);
		sp_overflow.addNumber(-2147483648);
		sp_overflow.addNumber(2147483647);
		std::cout << "Shortest span: " << sp_overflow.shortestSpan() << std::endl;
		std::cout << "Longest span: " << sp_overflow.longestSpan() << std::endl;
	} catch (const std::exception& e) {
		std::cerr << "Caught expected exception: " << e.what() << std::endl;
	}

	std::cout << "------------------------------------------" << std::endl << std::endl;

	std::cout << "## Exception Tests ##" << std::endl;


	std::cout << "1. Testing addNumber to a full Span..." << std::endl;
	try {
		Span sp_full(3);
		sp_full.addNumber(1);
		sp_full.addNumber(2);
		sp_full.addNumber(3);
		sp_full.addNumber(4);
	} catch (const std::exception& e) {
		std::cerr << "Caught expected exception: " << e.what() << std::endl;
	}

	std::cout << "\n2. Testing span calculation with one element..." << std::endl;
	try {
		Span sp_one(1);
		sp_one.addNumber(100);
		sp_one.shortestSpan();
	} catch (const std::exception& e) {
		std::cerr << "Caught expected exception: " << e.what() << std::endl;
	}
	try {
		Span sp_one(1);
		sp_one.longestSpan();
	} catch (const std::exception& e) {
		std::cerr << "Caught expected exception: " << e.what() << std::endl;
	}
	std::cout << "------------------------------------------" << std::endl;

	return 0;
}
