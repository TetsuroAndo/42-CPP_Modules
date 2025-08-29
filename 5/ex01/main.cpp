/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: teando <teando@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/29 01:13:17 by teando            #+#    #+#             */
/*   Updated: 2025/08/30 02:50:29 by teando           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int main() {

	std::cout << "--- Testing Valid Bureaucrats ---" << std::endl;
	try {
		Bureaucrat man("Steve", 43);
		std::cout << man << std::endl;

		std::cout << "Attempting to promote grade..." << std::endl;
		man.promoteGrade();
		std::cout << "After promote: " << man << std::endl;

		Bureaucrat bob("Bob", 150);
		bob = man;
		std::cout << "After copy: " << bob << std::endl;

		std::cout << "\n=== Form Tests ===============================" << std::endl;

		Form former("SSL", 42, 21);
		std::cout << former << std::endl;
		
		bob.signForm(former);

		std::cout << "\n=== Error Case ===============================" << std::endl;

		Bureaucrat bob2("Bob", 150);
		bob2.signForm(former);
	} catch (const std::exception& e) {
		std::cout << "Caught exception: " << e.what() << std::endl;
	}

	return 0;
}
