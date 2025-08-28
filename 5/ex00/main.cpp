/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: teando <teando@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/29 01:13:17 by teando            #+#    #+#             */
/*   Updated: 2025/08/29 01:21:57 by teando           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main() {

	std::cout << "--- Testing Valid Bureaucrats ---" << std::endl;
	try {
		Bureaucrat validBureaucrat("Zaphod", 42);
		std::cout << validBureaucrat << std::endl;

		std::cout << "Attempting to promote grade..." << std::endl;
		validBureaucrat.promoteGrade(); // Grade becomes 41
		std::cout << "After promote: " << validBureaucrat << std::endl;

		std::cout << "Attempting to demote grade..." << std::endl;
		validBureaucrat.demoteGrade(); // Grade becomes 42
		std::cout << "After demote: " << validBureaucrat << std::endl;

		Bureaucrat copy;
		copy = validBureaucrat;
		std::cout << "After copy: " << copy << std::endl;

	} catch (const std::exception& e) {
		std::cerr << "Caught exception: " << e.what() << std::endl;
	}

	std::cout << "\n=== Error Case ===============================" << std::endl;

	std::cout << "\n--- Testing Grade Too High on Construction ---" << std::endl;
	try {
		Bureaucrat highGradeBureaucrat("Ford", 0);
		std::cout << highGradeBureaucrat << std::endl;
	} catch (const std::exception& e) {
		std::cerr << "Caught exception: " << e.what() << std::endl;
	}

	std::cout << "\n--- Testing Grade Too Low on Construction ---" << std::endl;
	try {
		Bureaucrat lowGradeBureaucrat("Arthur", 151);
		std::cout << lowGradeBureaucrat << std::endl;
	} catch (const std::exception& e) {
		std::cerr << "Caught exception: " << e.what() << std::endl;
	}

	std::cout << "\n--- Testing promote from Highest Grade ---" << std::endl;
	try {
		Bureaucrat topBureaucrat("Marvin", 1);
		std::cout << topBureaucrat << std::endl;
		std::cout << "Attempting to promote grade from 1..." << std::endl;
		topBureaucrat.promoteGrade();
	} catch (const std::exception& e) {
		std::cerr << "Caught exception: " << e.what() << std::endl;
	}

	std::cout << "\n--- Testing demote from Lowest Grade ---" << std::endl;
	try {
		Bureaucrat bottomBureaucrat("Trillian", 150);
		std::cout << bottomBureaucrat << std::endl;
		std::cout << "Attempting to demote grade from 150..." << std::endl;
		bottomBureaucrat.demoteGrade();
	} catch (const std::exception& e) {
		std::cerr << "Caught exception: " << e.what() << std::endl;
	}

	return 0;
}
