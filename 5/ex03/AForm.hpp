/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: teando <teando@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/29 21:46:46 by teando            #+#    #+#             */
/*   Updated: 2025/08/30 19:52:14 by teando           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

class Bureaucrat;

class AForm {
private:
	const std::string _name;
	bool _isSigned;
	const int _reqSignGrade;
	const int _reqExecGrade;

public:
	AForm();
	AForm(const std::string& name);
	AForm(const std::string& name, int gradeToSign, int gradeToExec);
	AForm(const AForm& other);
	AForm& operator=(const AForm& other);
	virtual~AForm();

	virtual const std::string& getName() const;
	virtual bool getIsSigned() const;
	virtual int getReqSignGrade() const;
	virtual int getReqExecGrade() const;

	virtual void beSigned(const Bureaucrat& bureaucrat);
	virtual void execute(Bureaucrat const & executor) const = 0;

public:
	class GradeTooHighException : public std::exception {
		const char* what() const throw();
	};
	class GradeTooLowException : public std::exception {
		const char* what() const throw();
	};
};

std::ostream& operator<<(std::ostream& os, const AForm& AForm);
