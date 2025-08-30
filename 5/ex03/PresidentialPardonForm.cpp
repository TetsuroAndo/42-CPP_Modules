/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: teando <teando@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/30 13:01:38 by teando            #+#    #+#             */
/*   Updated: 2025/08/30 18:26:43 by teando           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(const std::string& target)
	: AForm(target, PresidentialPardonForm::SIGN_GRADE, PresidentialPardonForm::EXEC_GRADE)
{
	std::cerr << "[ PresidentialPardonForm ] " << this << " Target: " << target << " constructor called" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& other)
	: AForm(other)
{
	std::cerr << "[ PresidentialPardonForm ] " << this << " Copy constructor called" << std::endl;
}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& other) {
	std::cerr << "[ PresidentialPardonForm ] " << this << " Copy Assignment operator called" << std::endl;
	if (this != &other) {
		AForm::operator=(other);
	}
	return *this;
}

PresidentialPardonForm::~PresidentialPardonForm() {
	std::cerr << "[ PresidentialPardonForm ] " << this << " Destructor called" << std::endl;
}

void PresidentialPardonForm::execute(Bureaucrat const & executor) const {
	AForm::execute(executor);
	std::cout << getName() << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}
