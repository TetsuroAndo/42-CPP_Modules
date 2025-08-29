/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: teando <teando@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/29 21:46:46 by teando            #+#    #+#             */
/*   Updated: 2025/08/30 03:15:53 by teando           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

class Bureaucrat;

class Form {
private:
	const std::string _name;
	bool _isSigned;
	const int _reqSignGrade;
	const int _reqExecGrade;

public:
	Form();
	Form(const std::string& name);
	Form(const std::string& name, int gradeToSign, int gradeToExec);
	Form(const Form& other);
	Form& operator=(const Form& other);
	~Form();

	const std::string& getName() const;
	bool getIsSigned() const;
	int getReqSignGrade() const;
	int getReqExecGrade() const;

	void beSigned(const Bureaucrat& bureaucrat);

public:
	class GradeTooHighException : public std::exception {
		const char* what() const throw();
	};
	class GradeTooLowException : public std::exception {
		const char* what() const throw();
	};
};

std::ostream& operator<<(std::ostream& os, const Form& Form);