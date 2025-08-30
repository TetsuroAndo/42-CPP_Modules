/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: teando <teando@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/30 13:06:55 by teando            #+#    #+#             */
/*   Updated: 2025/08/30 13:23:07 by teando           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target)
	: AForm(target, ShrubberyCreationForm::SIGN_GRADE, ShrubberyCreationForm::EXEC_GRADE)
{
	std::cerr << "[ ShrubberyCreationForm ] " << this << " Target: " << target << " constructor called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other)
	: AForm(other)
{
	std::cerr << "[ ShrubberyCreationForm ] " << this << " Copy constructor called" << std::endl;
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other){
	std::cerr << "[ ShrubberyCreationForm ] " << this << " Copy Assignment operator called" << std::endl;
	if (this != &other) {
		AForm::operator=(other);
	}
	return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	std::cerr << "[ ShrubberyCreationForm ] " << this << " Destructor called" << std::endl;
}

