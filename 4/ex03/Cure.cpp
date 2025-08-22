/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: teando <teando@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/21 14:30:34 by teando            #+#    #+#             */
/*   Updated: 2025/08/23 06:29:39 by teando           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"
#include "PutLogLv.h"

Cure::Cure() : AMateria("cure") {
	putLogLevel("Cure", LOG_LV_WIDTH);
	std::cerr << "default constructor called" << std::endl;
}

Cure::Cure(const Cure &other) : AMateria(other) {
	putLogLevel("Cure", LOG_LV_WIDTH);
	std::cerr << "copy constructor called" << std::endl;
}

Cure &Cure::operator=(const Cure &other) {
	if (this != &other) {
		putLogLevel("Cure", LOG_LV_WIDTH);
	std::cerr << "assignment operator called" << std::endl;
		AMateria::operator=(other);
	}
	return *this;
}

Cure::~Cure() {
	putLogLevel("Cure", LOG_LV_WIDTH);
	std::cerr << "destructor called" << std::endl;
}

AMateria* Cure::clone() const {
	return new Cure(*this);
}

void Cure::use(ICharacter& target) {
	std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}
