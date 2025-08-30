/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: teando <teando@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/29 01:13:17 by teando            #+#    #+#             */
/*   Updated: 2025/08/30 21:34:52 by teando           ###   ########.fr       */
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
		Bureaucrat officer("Steve", 2);
		std::cout << officer << std::endl;

		std::cout << "Attempting to promote grade..." << std::endl;
		officer.promoteGrade();
		std::cout << "After promote: " << officer << std::endl;

		Bureaucrat bob("Bob", 150);
		std::cout << "After copy: " << bob << std::endl;

		std::cout << "\n=== Test: ShrubberyCreationForm ===\n" << std::endl;

		ShrubberyCreationForm shrub("Home");
		std::cout << shrub << std::endl;

		officer.signForm(shrub);
		bob.executeForm(shrub); // fails

		std::cout << "promote: " << bob << " to " << shrub.getReqExecGrade() << std::endl;
		for (int i = bob.getGrade(); i > shrub.getReqExecGrade(); i--) {
			bob.promoteGrade();
		}
		bob.executeForm(shrub); // succeeds

		std::cout << "\n=== Test: RobotomyRequestForm ===\n" << std::endl;

		RobotomyRequestForm robot("Robot");
		std::cout << robot << std::endl;

		officer.signForm(robot);
		bob.executeForm(robot); // fails

		std::cout << "promote: " << bob << " to " << robot.getReqExecGrade() << std::endl;
		for (int i = bob.getGrade(); i > robot.getReqExecGrade(); i--) {
			bob.promoteGrade();
		}
		bob.executeForm(robot);
		bob.executeForm(robot);
		bob.executeForm(robot);

		std::cout << "\n=== Test: PresidentialPardonForm ===\n" << std::endl;

		PresidentialPardonForm pardon("President");
		std::cout << pardon << std::endl;

		officer.signForm(pardon);
		bob.executeForm(pardon); // fails

		std::cout << "promote: " << bob << " to " << pardon.getReqExecGrade() << std::endl;
		for (int i = bob.getGrade(); i > pardon.getReqExecGrade(); i--) {
			bob.promoteGrade();
		}
		bob.executeForm(pardon);

		std::cout << "\n--- Destroy ---" << std::endl;
	} catch (const std::exception& e) {
		std::cout << "Caught exception: " << e.what() << std::endl;
		std::cout << "\n--- Destroy ---" << std::endl;
	}

	return 0;
}
