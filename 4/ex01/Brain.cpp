/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: teando <teando@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/01 20:12:09 by teando            #+#    #+#             */
/*   Updated: 2025/06/03 15:25:13 by teando           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain() {
	std::cout << "[ Brain ] Default constructor called" << std::endl;
	for (int i = 0; i < 100; ++i) {
		this->ideas[i] = "Empty idea";
	}
}

Brain::Brain(const Brain &other) {
	std::cout << "[ Brain ] Copy constructor called" << std::endl;
	for (int i = 0; i < 100; ++i) {
		this->ideas[i] = other.ideas[i];
	}
}

Brain &Brain::operator=(const Brain &other) {
	if (this != &other) {
		for (int i = 0; i < 100; ++i) {
			this->ideas[i] = other.ideas[i];
		}
	}
	return *this;
}

Brain::~Brain() {
	std::cout << "Brain destructor called" << std::endl;
}