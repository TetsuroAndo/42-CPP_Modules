/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: teando <teando@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 06:58:29 by teando            #+#    #+#             */
/*   Updated: 2025/05/29 00:18:40 by teando           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"
#include <iostream>
#include <iomanip>

namespace
{
	static std::string prompt(const std::string &label) {
		std::string s;
		std::cout << label << ": ";
		if (!std::getline(std::cin, s))
			return "";
		return s;
	}

	static bool getField(std::string &field, const std::string &label) {
		field = prompt(label);
		return !field.empty();
	}

	static std::string fmt(const std::string &s) {
		if (s.length() > 10)
			return s.substr(0, 9) + '.';
		return s;
	}
}

bool	Contact::setContact() {
	if (!getField(firstName, "First name")     ||
		!getField(lastName, "Last name")       ||
		!getField(nickname, "Nickname")        ||
		!getField(phoneNumber, "Phone number") ||
		!getField(darkestSecret, "Darkest secret")) {
		std::cout << "[ERROR] Fields must not be empty.\n";
		return false;
	}
	return true;
}

void	Contact::displayRow(int idx) const {
	std::cout	<< std::setw(10)	<< idx				<< '|'
				<< std::setw(10)	<< fmt(firstName)	<< '|'
				<< std::setw(10)	<< fmt(lastName)	<< '|'
				<< std::setw(10)	<< fmt(nickname)	<< '|'
				<< '\n';
}

void	Contact::displayFull() const {
	std::cout	<< "First name    : " << firstName		<< '\n'
				<< "Last name     : " << lastName		<< '\n'
				<< "Nickname      : " << nickname		<< '\n'
				<< "Phone number  : " << phoneNumber	<< '\n'
				<< "Darkest secret: " << darkestSecret	<< '\n';
}
