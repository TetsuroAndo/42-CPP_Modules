/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: teando <teando@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/15 19:39:03 by teando            #+#    #+#             */
/*   Updated: 2025/08/23 06:06:49 by teando           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"
#include "PutLogLv.h"

AMateria::AMateria() : _type("undefined") {
	putLogLevel("AMateria", LOG_LV_WIDTH);
	std::cerr << "default constructor called" << std::endl;
}

AMateria::AMateria(std::string const &type) : _type(type) {
	putLogLevel("AMateria", LOG_LV_WIDTH);
	std::cerr << "constructor called for type: " << _type << std::endl;
}

AMateria::AMateria(const AMateria &other) : _type(other._type) {
	putLogLevel("AMateria", LOG_LV_WIDTH);
	std::cerr << "copy constructor called for type: " << _type << std::endl;
}

AMateria &AMateria::operator=(const AMateria &other) {
	if (this != &other) {
		putLogLevel("AMateria", LOG_LV_WIDTH);
	std::cerr << "assignment operator called for type: " << other._type << std::endl;
		_type = other._type;
	}
	return *this;
}

AMateria::~AMateria() {
	putLogLevel("AMateria", LOG_LV_WIDTH);
	std::cerr << "destructor called for type: " << _type << std::endl;
}

std::string const & AMateria::getType() const {
	return _type;
}

void AMateria::use(ICharacter& target) {
	std::cout << " this materia does nothing to " << target.getName() << std::endl;
}
