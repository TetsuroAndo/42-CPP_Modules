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
	typedef AForm* (*FactoryFunc)(const std::string&);

	static std::map<std::string, FactoryFunc> factories;
	if (factories.empty()) {
		factories["presidential pardon"] = &createPresidential;
		factories["robotomy request"] = &createRobotomy;
		factories["shrubbery creation"] = &createShrubbery;
	}

	std::map<std::string, FactoryFunc>::const_iterator it = factories.find(formName);
	if (it != factories.end())
		return it->second(target);

	std::cerr << "[ Intern ] " << this << " Unknown form type: " << formName << std::endl;
	return nullptr;
}
