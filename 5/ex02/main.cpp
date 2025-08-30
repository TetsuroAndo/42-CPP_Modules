/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: teando <teando@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/29 01:13:17 by teando            #+#    #+#             */
/*   Updated: 2025/08/30 19:03:08 by teando           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main() {

	std::cout << "--- Testing Valid Bureaucrats ---" << std::endl;
	try {
		Bureaucrat officer("Steve", 146);
		std::cout << officer << std::endl;

		std::cout << "Attempting to promote grade..." << std::endl;
		officer.promoteGrade();
		std::cout << "After promote: " << officer << std::endl;

		Bureaucrat bob("Bob", 150);
		bob = officer;
		std::cout << "After copy: " << bob << std::endl;

		std::cout << "\n=== Test: ShrubberyCreationForm ===" << std::endl;

		ShrubberyCreationForm shrub("Home");
		std::cout << shrub << std::endl;

		officer.signForm(shrub);
		officer.executeForm(shrub);

		std::cout << "\n=== Test: RobotomyRequestForm ===" << std::endl;

		RobotomyRequestForm robot("Robot");
		std::cout << robot << std::endl;

		std::cout << "\n=== Test: PresidentialPardonForm ===" << std::endl;

		PresidentialPardonForm pardon("President");
		std::cout << pardon << std::endl;

		std::cout << "\n--- Destroy ---" << std::endl;
	} catch (const std::exception& e) {
		std::cout << "Caught exception: " << e.what() << std::endl;
		std::cout << "\n--- Destroy ---" << std::endl;
	}

	return 0;
}
