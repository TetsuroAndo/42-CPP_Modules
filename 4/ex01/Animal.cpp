/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: teando <teando@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/15 11:05:39 by teando            #+#    #+#             */
/*   Updated: 2025/08/15 15:43:00 by teando           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal() : _type("Animal") {
	putLogLevel("Animal", LOG_LV_WIDTH);
	std::cerr << "Default constructor called" << std::endl;
}

Animal::Animal(std::string type) : _type(type) {
	putLogLevel("Animal", LOG_LV_WIDTH);
	std::cerr << "Type Constructor called" << std::endl;
}

Animal::Animal(const Animal &other) : _type(other._type) {
	putLogLevel("Animal", LOG_LV_WIDTH);
	std::cerr << "Copy constructor called" << std::endl;
}

Animal &Animal::operator=(const Animal &other) {
	putLogLevel("Animal", LOG_LV_WIDTH);
	std::cerr << "Copy assignment operator called" << std::endl;
	if (this != &other) {
		_type = other._type;
	}
	return *this;
}

Animal::~Animal() {
	putLogLevel("Animal", LOG_LV_WIDTH);
	std::cerr << "Destructor called" << std::endl;
}

void Animal::makeSound() const {
	putLogLevel("Animal", LOG_LV_WIDTH);
	std::cerr << "makeSound called: ";
	std::cout << "This is Animal! NO SOUND!" << std::endl;
}

std::string Animal::getType() const {
	return _type;
}
