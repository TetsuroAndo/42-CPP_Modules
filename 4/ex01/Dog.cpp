/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: teando <teando@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/15 11:05:30 by teando            #+#    #+#             */
/*   Updated: 2025/08/15 16:52:26 by teando           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog() : Animal("Dog") {
	putLogLevel("Dog", LOG_LV_WIDTH);
	std::cerr << "Constructor called" << std::endl;
	_brain = new Brain();
}

Dog::Dog(const Dog &other) : Animal(other) {
	putLogLevel("Dog", LOG_LV_WIDTH);
	std::cerr << "Copy constructor called" << std::endl;
	_brain = new Brain();
}

Dog &Dog::operator=(const Dog &other) {
	putLogLevel("Dog", LOG_LV_WIDTH);
	std::cerr << "Copy assignment operator called" << std::endl;
	if (this != &other) {
		Animal::operator=(other);
		_brain = new Brain();
	}
	return *this;
}

Dog::~Dog() {
	putLogLevel("Dog", LOG_LV_WIDTH);
	std::cerr << "Destructor called" << std::endl;
	delete _brain;
}

void Dog::makeSound() const {
	putLogLevel("Dog", LOG_LV_WIDTH);
	std::cerr << "makeSound called: ";
	std::cout << "Woooooof!" << std::endl;
}
