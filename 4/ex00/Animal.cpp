/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: teando <teando@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/31 15:21:16 by teando            #+#    #+#             */
/*   Updated: 2025/05/31 15:22:49 by teando           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal() : _type("Animal") {
	std::cout << "[ Animal ] Default constructor called" << std::endl;
}

Animal::Animal(std::string type) : _type(type) {
	std::cout << "[ Animal ] Type constructor called" << std::endl;
}

Animal::Animal(const Animal &other) : _type(other._type) {
	std::cout << "[ Animal ] Copy constructor called" << std::endl;
}

Animal &Animal::operator=(const Animal &other) {
	std::cout << "[ Animal ] Copy assignment operator called" << std::endl;
	if (this != &other) {
		_type = other._type;
	}
	return *this;
}

Animal::~Animal() {
	std::cout << "[ Animal ] Destructor called" << std::endl;
}

std::string Animal::getType() const {
	return _type;
}

void Animal::makeSound() const {
	std::cout << "Animal sound" << std::endl;
}
