/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: teando <teando@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/29 00:33:47 by teando            #+#    #+#             */
/*   Updated: 2025/08/30 16:46:43 by teando           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"

Bureaucrat::Bureaucrat() : _name("default"), _grade(150) {
	std::cerr << "[ Bureaucrat ] " << this << " Default constructor called" << std::endl;
}

Bureaucrat::Bureaucrat(const std::string& name) : _name(name), _grade(150) {
	std::cerr << "[ Bureaucrat ] " << this << " Name: " << name << " constructor called" << std::endl;
}

Bureaucrat::Bureaucrat(const std::string& name, int grade) : _name(name), _grade(grade) {
	if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
	else if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
	std::cerr << "[ Bureaucrat ] " << this << " Name: " << name << ", Grade: " << grade << " constructor called" << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat& other) : _name(other._name), _grade(other._grade) {
	std::cerr << "[ Bureaucrat ] " << this << " Copy constructor called" << std::endl;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other) {
	std::cerr << "[ Bureaucrat ] " << this << " Copy Assignment operator called" << std::endl;
	if (this != &other) {
		_grade = other._grade;
	}
	return *this;
}

Bureaucrat::~Bureaucrat() {
	std::cerr << "[ Bureaucrat ] " << this << " Destructor called" << std::endl;
}

const std::string& Bureaucrat::getName() const {
	return _name;
}

int Bureaucrat::getGrade() const {
	return _grade;
}

void Bureaucrat::promoteGrade() {
	if (_grade > 1)
		_grade--;
	else
		throw Bureaucrat::GradeTooHighException();
}

void Bureaucrat::demoteGrade() {
	if (_grade < 150)
		_grade++;
	else
		throw Bureaucrat::GradeTooLowException();
}

void Bureaucrat::signAForm(AForm& form) const {
	try {
		std::cout << _name << " signs " << form.getName() << std::endl;
		form.beSigned(*this);
	} catch (const std::exception& e) {
		std::cout << _name << " cannot sign " << form.getName() << " because " << e.what() << std::endl;
		return;
	}
}

const char* Bureaucrat::GradeTooHighException::what() const throw() {
	return "Grade too high";
}

const char* Bureaucrat::GradeTooLowException::what() const throw() {
	return "Grade too low";
}

std::ostream& operator<<(std::ostream& os, const Bureaucrat& bureaucrat) {
	os << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade();
	return os;
}
