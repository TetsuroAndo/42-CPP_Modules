/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: teando <teando@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/30 13:05:28 by teando            #+#    #+#             */
/*   Updated: 2025/08/31 09:19:57 by teando           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"
#include <cstdlib>
#include <ctime>

namespace {
	unsigned int getTimeSeed()
	{
		unsigned long seed = static_cast<unsigned long>(std::clock());
		return static_cast<unsigned int>(seed);
	}
}

RobotomyRequestForm::RobotomyRequestForm(const std::string& target)
	: AForm(target, RobotomyRequestForm::SIGN_GRADE, RobotomyRequestForm::EXEC_GRADE)
{
	std::cerr << "[ RobotomyRequestForm ] " << this << " Target: " << target << " constructor called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other)
	: AForm(other)
{
	std::cerr << "[ RobotomyRequestForm ] " << this << " Copy constructor called" << std::endl;
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& other) {
	std::cerr << "[ RobotomyRequestForm ] " << this << " Copy Assignment operator called" << std::endl;
	if (this != &other) {
		AForm::operator=(other);
	}
	return *this;
}

RobotomyRequestForm::~RobotomyRequestForm() {
	std::cerr << "[ RobotomyRequestForm ] " << this << " Destructor called" << std::endl;
}

void RobotomyRequestForm::execute(Bureaucrat const & executor) const {
	AForm::execute(executor);
	std::srand(getTimeSeed());
	if (std::rand() % 2 == 0) {
		std::cout << "Bzzzzzz... " << getName() << " has been robotomized successfully." << std::endl;
	} else {
		std::cout << "Bzzzzzz... " << getName() << " has failed to be robotomized." << std::endl;
	}
}
