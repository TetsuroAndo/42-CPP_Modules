/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: teando <teando@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/21 14:30:34 by teando            #+#    #+#             */
/*   Updated: 2025/08/23 04:25:30 by teando           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"

Cure::Cure() : AMateria("cure") {
	std::cerr << "[ Cure ] default constructor called" << std::endl;
}

Cure::Cure(const Cure &other) : AMateria(other) {
	std::cerr << "[ Cure ] copy constructor called" << std::endl;
}

Cure &Cure::operator=(const Cure &other) {
	if (this != &other) {
		std::cerr << "[ Cure ] assignment operator called" << std::endl;
		AMateria::operator=(other);
	}
	return *this;
}

Cure::~Cure() {
	std::cerr << "[ Cure ] destructor called" << std::endl;
}

AMateria* Cure::clone() const {
	return new Cure(*this);
}

void Cure::use(ICharacter& target) {
	std::cout << "* shoots an cure bolt at " << target.getName() << " *" << std::endl;
}
