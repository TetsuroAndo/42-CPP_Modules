/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: teando <teando@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/15 11:05:35 by teando            #+#    #+#             */
/*   Updated: 2025/08/15 15:43:34 by teando           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat() : Animal("Cat") {
	putLogLevel("Cat", LOG_LV_WIDTH);
	std::cerr << "Constructor called" << std::endl;
}

Cat::Cat(const Cat &other) : Animal(other) {
	putLogLevel("Cat", LOG_LV_WIDTH);
	std::cerr << "Copy constructor called" << std::endl;
}

Cat &Cat::operator=(const Cat &other) {
	putLogLevel("Cat", LOG_LV_WIDTH);
	std::cerr << "Copy assignment operator called" << std::endl;
	if (this != &other) {
		Animal::operator=(other);
	}
	return *this;
}

Cat::~Cat() {
	putLogLevel("Cat", LOG_LV_WIDTH);
	std::cerr << "Destructor called" << std::endl;
}

void Cat::makeSound() const {
	putLogLevel("Cat", LOG_LV_WIDTH);
	std::cerr << "makeSound called: ";
	std::cout << "Meow!" << std::endl;
}
