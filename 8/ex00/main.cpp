/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: teando <teando@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/03 17:33:31 by teando            #+#    #+#             */
/*   Updated: 2025/09/03 23:47:54 by teando           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"
#include <vector>
#include <list>

void testVector() {
	std::cout << "--- Testing std::vector ---" << std::endl;
	std::vector<int> vec;
	for (int i = 0; i < 5; ++i) {
		vec.push_back(i * 10); // 0, 10, 20, 30, 40
	}

	// 1. Found case
	try {
		std::vector<int>::iterator it = easyfind(vec, 30);
		std::cout << "Found value: " << *it << " at index " << std::distance(vec.begin(), it) << std::endl;
	} catch (const std::exception &e) {
		std::cerr << "Error: " << e.what() << std::endl;
	}

	// 2. Not found error case
	try {
		easyfind(vec, 99);
	} catch (const std::exception &e) {
		std::cerr << "Searching for 99... Correctly caught exception: " << e.what() << std::endl;
	}
}

void testList() {
	std::cout << "\n--- Testing std::list ---" << std::endl;
	std::list<int> lst;
	lst.push_back(5);
	lst.push_back(15);
	lst.push_back(25);

	// 1. Found case
	try {
		std::list<int>::iterator it = easyfind(lst, 15);
		std::cout << "Found value: " << *it << std::endl;
	} catch (const std::exception &e) {
		std::cerr << "Error: " << e.what() << std::endl;
	}

	// 2. Not found error case
	try {
		easyfind(lst, 100);
	} catch (const std::exception &e) {
		std::cerr << "Searching for 100... Correctly caught exception: " << e.what() << std::endl;
	}
}

int main() {
	testVector();
	testList();
	return 0;
}
