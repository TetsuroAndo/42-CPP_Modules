/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   Intern.cpp										 :+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: teando <teando@student.42tokyo.jp>		 +#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2025/08/30 21:37:55 by teando			#+#	#+#			 */
/*   Updated: 2025/08/30 21:55:19 by teando		   ###   ########.fr	   */
/*																			*/
/* ************************************************************************** */

#include "Intern.hpp"
#include <map>

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

static AForm* createPresidential(const std::string& t) { return new PresidentialPardonForm(t); }
static AForm* createRobotomy(const std::string& t) { return new RobotomyRequestForm(t); }
static AForm* createShrubbery(const std::string& t) { return new ShrubberyCreationForm(t); }

AForm *Intern::makeForm(const std::string& formName, const std::string& target) {
	typedef AForm* (*formCall)(const std::string&);

	static std::map<std::string, formCall> type;
	if (type.empty()) {
		type["presidential pardon"] = &createPresidential;
		type["robotomy request"] = &createRobotomy;
		type["shrubbery creation"] = &createShrubbery;
	}

	std::map<std::string, formCall>::const_iterator it = type.find(formName);
	if (it != type.end())
		return it->second(target);

	std::cerr << "[ Intern ] " << this << " Unknown form type: " << formName << std::endl;
	return NULL;
}
