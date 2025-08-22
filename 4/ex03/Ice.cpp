/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: teando <teando@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/15 21:14:56 by teando            #+#    #+#             */
/*   Updated: 2025/08/23 04:25:56 by teando           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"

Ice::Ice() : AMateria("ice") {
	std::cerr << "[ Ice  ] constructor called" << std::endl;
}

Ice::Ice(const Ice &other) : AMateria(other._type) {
	std::cerr << "[ Ice  ] copy constructor called" << std::endl;
}

Ice &Ice::operator=(const Ice &other) {
	if (this != &other) {
		std::cerr << "[ Ice  ] assignment operator called" << std::endl;
		AMateria::operator=(other);
	}
	return *this;
}

Ice::~Ice() {
	std::cerr << "[ Ice  ] destructor called" << std::endl;
}

AMateria* Ice::clone() const {
	return new Ice(*this);
}

void Ice::use(ICharacter& target) {
	std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}
