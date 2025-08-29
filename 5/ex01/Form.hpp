/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: teando <teando@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/29 21:46:46 by teando            #+#    #+#             */
/*   Updated: 2025/08/29 22:18:44 by teando           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include "Bureaucrat.hpp"

class Form {
private:
	const std::string _name;
	bool _isSigned;
	int _gradeToSign;
	int _gradeToExecute;

public:
	Form();
	Form(const std::string& name, int gradeToSign, int gradeToExecute);
	Form(const Form& other);
	Form& operator=(const Form& other);
	~Form();

	const std::string& getName() const;

};
