/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: teando <teando@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/30 13:05:28 by teando            #+#    #+#             */
/*   Updated: 2025/08/30 13:13:52 by teando           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm()
	: AForm("RobotomyRequestForm", RobotomyRequestForm::SIGN_GRADE, RobotomyRequestForm::EXEC_GRADE)
{
	std::cerr << "[ RobotomyRequestForm ] " << this << " Default constructor called" << std::endl;
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

