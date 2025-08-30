/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: teando <teando@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/30 12:44:28 by teando            #+#    #+#             */
/*   Updated: 2025/08/30 13:22:47 by teando           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "AForm.hpp"

class ProsidentialPardonForm : public AForm {
public:
	const int SIGN_GRADE = 25;
	const int EXEC_GRADE = 5;

public:
	ProsidentialPardonForm(const std::string& target);
	ProsidentialPardonForm(const ProsidentialPardonForm& other);
	ProsidentialPardonForm& operator=(const ProsidentialPardonForm& other);
	virtual ~ProsidentialPardonForm();

	virtual void execute(const Bureaucrat& executor) const;
};
