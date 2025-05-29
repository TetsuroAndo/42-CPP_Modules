/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: teando <teando@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 06:58:35 by teando            #+#    #+#             */
/*   Updated: 2025/05/29 23:36:23 by teando           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include <iostream>
#include <iomanip>
#include <sstream>

PhoneBook::PhoneBook() : size(0), oldest(0) {}

void PhoneBook::add() {
	Contact tmp;
	if (!tmp.setContact())
		return ;

	contacts[oldest] = tmp;
	if (size < 8)
		++size;
	oldest = (oldest + 1) % 8;
	std::cout << "Contact saved!\n";
}

void PhoneBook::search() const {
	if (size == 0){
		std::cout << "Empty contacts.\n";
		return;
	}

	std::cout	<< std::setw(10) << "Index"			<< '|'
				<< std::setw(10) << "First name"	<< '|'
				<< std::setw(10) << "Last name"		<< '|'
				<< std::setw(10) << "Nickname"		<< '|'
				<< '\n';
	for (int i = 0; i < size; ++i)
		contacts[i].displayRow(i);

	std::cout << "Choose index to inspect: ";
	std::string line;
	if (!std::getline(std::cin, line))
		return;
	std::istringstream iss(line);
	int idx;
	if (!(iss >> idx) || idx < 0 || idx >= size) {
		std::cout << "[Error] Invalid index.\n";
		return;
	}
	contacts[idx].displayFull();
}
