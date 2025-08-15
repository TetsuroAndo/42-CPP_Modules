/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: teando <teando@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/15 11:05:39 by teando            #+#    #+#             */
/*   Updated: 2025/08/15 11:39:35 by teando           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal(std::string type) : _type(type) {
	std::cerr << "[ Animal ] Constructor called" << std::endl;
}

Animal::Animal(const Animal &other) : type(other.type) {
	std::cerr << "[ Animal ] Copy constructor called" << std::endl;
}

Animal &Animal::operator=(const Animal &other) {
	std::cerr << "[ Animal ] Copy assignment operator called" << std::endl;
	if (this != &other) {
		type = other.type;
	}
	return *this;
}

Animal::~Animal() {
	std::cerr << "[ Animal ] Destructor called" << std::endl;
}

void Animal::makeSound() const {
	std::cerr << "[ Animal ] makeSound called: ";
	std::cout << "Animal sound!" << std::endl;
}

std::string Animal::getType() const {
	std::cerr << "[ Animal ] getType called: " << type << std::endl;
	return type;
}
