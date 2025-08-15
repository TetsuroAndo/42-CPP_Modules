/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: teando <teando@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/15 14:57:22 by teando            #+#    #+#             */
/*   Updated: 2025/08/15 15:44:23 by teando           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() : _type("WrongAnimal") {
	putLogLevel("WrongAnimal", LOG_LV_WIDTH);
	std::cerr << "Default constructor called" << std::endl;
}

WrongAnimal::WrongAnimal(std::string type) : _type(type) {
	putLogLevel("WrongAnimal", LOG_LV_WIDTH);
	std::cerr << "Type constructor called" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &other) : _type(other._type) {
	putLogLevel("WrongAnimal", LOG_LV_WIDTH);
	std::cerr << "Copye constructor called" << std::endl;
}

WrongAnimal &WrongAnimal::operator=(const WrongAnimal &other) {
	putLogLevel("WrongAnimal", LOG_LV_WIDTH);
	std::cerr << "Copy assignment operator called" << std::endl;
	if (this != &other) {
		_type = other._type;
	}
	return *this;
}

WrongAnimal::~WrongAnimal() {
	putLogLevel("WrongAnimal", LOG_LV_WIDTH);
	std::cerr << "Destructor called" << std::endl;
}

void WrongAnimal::makeSound() const {
	putLogLevel("WrongAnimal", LOG_LV_WIDTH);
	std::cerr << "makeSound called: ";
	std::cout << "This is Wrong Animal! BIG NOISE!" << std::endl;
}

std::string WrongAnimal::getType() const {
	return _type;
}
