/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: teando <teando@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/30 13:01:38 by teando            #+#    #+#             */
/*   Updated: 2025/08/30 13:22:44 by teando           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

ProsidentialPardonForm::ProsidentialPardonForm(const std::string& target)
	: AForm(target, ProsidentialPardonForm::SIGN_GRADE, ProsidentialPardonForm::EXEC_GRADE)
{
	std::cerr << "[ ProsidentialPardonForm ] " << this << " Target: " << target << " constructor called" << std::endl;
}

ProsidentialPardonForm::ProsidentialPardonForm(const ProsidentialPardonForm& other)
	: AForm(other)
{
	std::cerr << "[ ProsidentialPardonForm ] " << this << " Copy constructor called" << std::endl;
}

ProsidentialPardonForm& ProsidentialPardonForm::operator=(const ProsidentialPardonForm& other) {
	std::cerr << "[ ProsidentialPardonForm ] " << this << " Copy Assignment operator called" << std::endl;
	if (this != &other) {
		AForm::operator=(other);
	}
	return *this;
}

ProsidentialPardonForm::~ProsidentialPardonForm() {
	std::cerr << "[ ProsidentialPardonForm ] " << this << " Destructor called" << std::endl;
}
