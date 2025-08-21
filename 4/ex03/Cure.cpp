/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: teando <teando@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/21 14:30:34 by teando            #+#    #+#             */
/*   Updated: 2025/08/21 14:32:06 by teando           ###   ########.fr       */
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

