/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: teando <teando@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/29 21:46:42 by teando            #+#    #+#             */
/*   Updated: 2025/08/30 03:15:17 by teando           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

AForm::AForm()
	: _name("Default"), _isSigned(false), _reqSignGrade(42), _reqExecGrade(21) {
	std::cerr << "[ AForm ] default constructor called" << std::endl;
}

AForm::AForm(const std::string& name)
	: _name(name), _isSigned(false), _reqSignGrade(42), _reqExecGrade(21) {
	std::cerr << "[ AForm ] default constructor called" << std::endl;
}

AForm::AForm(const std::string& name, int gradeToSign, int gradeToExec)
	: _name(name), _isSigned(false), _reqSignGrade(gradeToSign), _reqExecGrade(gradeToExec) {
	if (gradeToSign < 1 || gradeToExec < 1)
		throw GradeTooHighException();
	else if (gradeToSign > 150 || gradeToExec > 150)
		throw GradeTooLowException();
	std::cerr << "[ AForm ] parameterized constructor called" << std::endl;
}

AForm::AForm(const AForm& other) :
	_name(other._name),
	_isSigned(other._isSigned),
	_reqSignGrade(other._reqSignGrade),
	_reqExecGrade(other._reqExecGrade)
{
	std::cerr << "[ AForm ] " << this << " Name: " << other._name << " copy constructor called" << std::endl;
}

AForm& AForm::operator=(const AForm& other) {
	std::cerr << "[ AForm ] " << this << " Name: " << other._name << " copy assignment operator called" << std::endl;
	if (this != &other) {
		_isSigned = other._isSigned;
	}
	return *this;
}

AForm::~AForm() {
	std::cerr << "[ AForm ] " << this << " Destructor called" << std::endl;
}

const std::string& AForm::getName() const {
	return _name;
}

bool AForm::getIsSigned() const {
	return _isSigned;
}

int AForm::getReqSignGrade() const {
	return _reqSignGrade;
}

int AForm::getReqExecGrade() const {
	return _reqExecGrade;
}

void AForm::beSigned(const Bureaucrat& bureaucrat) {
	if (bureaucrat.getGrade() > _reqSignGrade) {
		throw GradeTooLowException();
	}
	_isSigned = true;
}

void AForm::execute(Bureaucrat const & executor) const {
	if (!_isSigned) {
		throw GradeTooLowException();
	}
	if (executor.getGrade() > _reqExecGrade) {
		throw GradeTooLowException();
	}
}

const char* AForm::GradeTooHighException::what() const throw() {
	return "Grade is too high.";
}

const char* AForm::GradeTooLowException::what() const throw() {
	return "Grade is too low.";
}

std::ostream& operator<<(std::ostream& os, const AForm& AForm) {
	os << "AForm Name: " << AForm.getName()
	   << ", Signed: " << (AForm.getIsSigned() ? "Yes" : "No")
	   << ", Required Sign Grade: " << AForm.getReqSignGrade()
	   << ", Required Execute Grade: " << AForm.getReqExecGrade();
	return os;
}
