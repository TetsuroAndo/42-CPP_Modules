/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: teando <teando@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/01 20:12:09 by teando            #+#    #+#             */
/*   Updated: 2025/06/04 21:15:37 by teando           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain() {
	std::cout << "[ Brain ] Default constructor called\n";
}

Brain::Brain(const Brain &o) {
	std::cout << "[ Brain ] Copy constructor called\n";
	for (size_t i = 0; i < 100; ++i)
		ideas[i] = o.ideas[i];
}

Brain &Brain::operator=(const Brain &o) {
	std::cout << "[ Brain ] Copy assignment operator called\n";
	if (this != &o)
		for (size_t i = 0; i < 100; ++i)
			ideas[i] = o.ideas[i];
	return *this;
}

Brain::~Brain() {
	std::cout << "[ Brain ] Destructor called\n";
}

std::string &Brain::operator[](size_t idx) {
	return ideas[idx];
}

const std::string &Brain::operator[](size_t idx) const {
	return ideas[idx];
}
