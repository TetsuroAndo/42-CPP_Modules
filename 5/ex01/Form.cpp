/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: teando <teando@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/29 21:46:42 by teando            #+#    #+#             */
/*   Updated: 2025/08/30 02:43:35 by teando           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form()
	: _name("Default"), _isSigned(false), _reqSignGrade(42), _reqExecGrade(21) {
	std::cerr << "[ Form ] default constructor called" << std::endl;
}

Form::Form(const std::string& name)
	: _name(name), _isSigned(false), _reqSignGrade(42), _reqExecGrade(21) {
	std::cerr << "[ Form ] default constructor called" << std::endl;
}

Form::Form(const std::string& name, int gradeToSign, int gradeToExec)
	: _name(name), _isSigned(false), _reqSignGrade(gradeToSign), _reqExecGrade(gradeToExec) {
	if (gradeToSign < 1 || gradeToExec < 1)
		throw GradeTooHighException();
	else if (gradeToSign > 150 || gradeToExec > 150)
		throw GradeTooLowException();
	std::cerr << "[ Form ] parameterized constructor called" << std::endl;
}

Form::Form(const Form& other) :
	_name(other._name),
	_isSigned(other._isSigned),
	_reqSignGrade(other._reqSignGrade),
	_reqExecGrade(other._reqExecGrade)
{
	std::cerr << "[ Form ] " << this << " Name: " << other._name << " copy constructor called" << std::endl;
}

Form& Form::operator=(const Form& other) {
	std::cerr << "[ Form ] " << this << " Name: " << other._name << " copy assignment operator called" << std::endl;
	if (this != &other) {
		_isSigned = other._isSigned;
		_reqSignGrade = other._reqSignGrade;
		_reqExecGrade = other._reqExecGrade;
	}
	return *this;
}

Form::~Form() {
	std::cerr << "[ Form ] " << this << " Destructor called" << std::endl;
}

const std::string& Form::getName() const {
	return _name;
}

bool Form::getIsSigned() const {
	return _isSigned;
}

int Form::getReqSignGrade() const {
	return _reqSignGrade;
}

int Form::getReqExecGrade() const {
	return _reqExecGrade;
}

void Form::beSigned(const Bureaucrat& bureaucrat) {
	if (bureaucrat.getGrade() > _reqSignGrade) {
		throw GradeTooLowException();
	}
	_isSigned = true;
}

const char* Form::GradeTooHighException::what() const throw() {
	return "Grade is too high.";
}

const char* Form::GradeTooLowException::what() const throw() {
	return "Grade is too low.";
}

std::ostream& operator<<(std::ostream& os, const Form& Form) {
	os << "Form Name: " << Form.getName()
	   << ", Signed: " << (Form.getIsSigned() ? "Yes" : "No")
	   << ", Required Sign Grade: " << Form.getReqSignGrade()
	   << ", Required Execute Grade: " << Form.getReqExecGrade();
	return os;
}
