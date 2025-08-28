/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: teando <teando@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/15 21:14:56 by teando            #+#    #+#             */
/*   Updated: 2025/08/28 22:31:24 by teando           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"
#include "PutLogLv.h"

Ice::Ice() : AMateria("ice") {
	putLogLevel("Ice", LOG_LV_WIDTH);
	std::cerr << "constructor called" << std::endl;
}

Ice::Ice(const Ice &other) : AMateria(other._type) {
	putLogLevel("Ice", LOG_LV_WIDTH);
	std::cerr << "copy constructor called" << std::endl;
}

Ice &Ice::operator=(const Ice &other) {
	if (this != &other) {
		putLogLevel("Ice", LOG_LV_WIDTH);
	std::cerr << "assignment operator called" << std::endl;
		AMateria::operator=(other);
	}
	return *this;
}

Ice::~Ice() {
	putLogLevel("Ice", LOG_LV_WIDTH);
	std::cerr << "destructor called" << std::endl;
}

AMateria* Ice::clone() const {
	return new Ice(*this);
}

void Ice::use(ICharacter& target) {
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}
