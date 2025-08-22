/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: teando <teando@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/15 19:39:03 by teando            #+#    #+#             */
/*   Updated: 2025/08/23 05:36:37 by teando           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

AMateria::AMateria() : _type("undefined") {
	std::cerr << "[ AMateria ] default constructor called" << std::endl;
}

AMateria::AMateria(std::string const &type) : _type(type) {
	std::cerr << "[ AMateria ] constructor called for type: " << _type << std::endl;
}

AMateria::AMateria(const AMateria &other) : _type(other._type) {
	std::cerr << "[ AMateria ] copy constructor called for type: " << _type << std::endl;
}

AMateria &AMateria::operator=(const AMateria &other) {
	if (this != &other) {
		std::cerr << "[ AMateria ] assignment operator called for type: " << other._type << std::endl;
		_type = other._type;
	}
	return *this;
}

AMateria::~AMateria() {
	std::cerr << "[ AMateria ] destructor called for type: " << _type << std::endl;
}

std::string const & AMateria::getType() const {
	return _type;
}

void AMateria::use(ICharacter& target) {}
