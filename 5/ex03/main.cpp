/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: teando <teando@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/29 01:13:17 by teando            #+#    #+#             */
/*   Updated: 2025/08/30 22:02:37 by teando           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int main() {

	std::cout << "--- Testing Valid Bureaucrats ---" << std::endl;
	try {
		Bureaucrat officer("Steve", 2);
		std::cout << officer << std::endl;

		std::cout << "Attempting to promote grade..." << std::endl;
		officer.promoteGrade();
		std::cout << "After promote: " << officer << std::endl;

		Bureaucrat bob("Bob", 150);
		std::cout << "After copy: " << bob << std::endl;

		std::cout << "\n=== Test: Intern ===\n" << std::endl;
		Intern someRandomIntern;
		AForm* rrf;
		rrf = someRandomIntern.makeForm("robotomy request", "Bender");

		rrf->beSigned(officer);

		//rrf->execute(bob);
		bob = officer;
		rrf->execute(bob);

		std::cout << "\n--- Destroy ---" << std::endl;
	} catch (const std::exception& e) {
		std::cout << "Caught exception: " << e.what() << std::endl;
		std::cout << "\n--- Destroy ---" << std::endl;
	}

	return 0;
}
