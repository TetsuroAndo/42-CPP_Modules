/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: teando <teando@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/30 22:17:16 by teando            #+#    #+#             */
/*   Updated: 2025/08/30 22:31:47 by teando           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern() {
	std::cerr << "[ Intern ] " << this << " Default constructor called" << std::endl;
}

Intern::Intern(const Intern& other) {
	(void)other;
	std::cerr << "[ Intern ] " << this << " Copy constructor called" << std::endl;
}

Intern& Intern::operator=(const Intern& other) {
	(void)other;
	std::cerr << "[ Intern ] " << this << " Copy assignment operator called" << std::endl;
	return *this;
}

Intern::~Intern() {
	std::cerr << "[ Intern ] " << this << " Destructor called" << std::endl;
}

static AForm* createPresidential(const std::string& t)	{ return new PresidentialPardonForm(t); }
static AForm* createRobotomy(const std::string& t)		{ return new RobotomyRequestForm(t); }
static AForm* createShrubbery(const std::string& t)		{ return new ShrubberyCreationForm(t); }

AForm *Intern::makeForm(const std::string& formName, const std::string& target) {
	typedef AForm* (*formFunc)(const std::string&);
	struct Entry {
		const char* name;
		formFunc create;
	};

	static const Entry forms[] = {
		{ "presidential pardon", &createPresidential },
		{ "robotomy request",	&createRobotomy },
		{ "shrubbery creation", &createShrubbery }
	};

	for (size_t i = 0; i < (sizeof(forms) / sizeof(forms[0])); ++i) {
		if (formName == forms[i].name) {
			std::cout << "Intern creates " << formName << std::endl;
			return forms[i].create(target);
		}
	}
	std::cout << "Intern " << " Unknown form " << formName << std::endl;
	return NULL;
}
