/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: teando <teando@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/15 11:05:35 by teando            #+#    #+#             */
/*   Updated: 2025/08/15 16:52:09 by teando           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat() : Animal("Cat") {
	putLogLevel("Cat", LOG_LV_WIDTH);
	std::cerr << "Constructor called" << std::endl;
	_brain = new Brain();
}

Cat::Cat(const Cat &other) : Animal(other) {
	putLogLevel("Cat", LOG_LV_WIDTH);
	std::cerr << "Copy constructor called" << std::endl;
	_brain = new Brain();
}

Cat &Cat::operator=(const Cat &other) {
	putLogLevel("Cat", LOG_LV_WIDTH);
	std::cerr << "Copy assignment operator called" << std::endl;
	if (this != &other) {
		Animal::operator=(other);
		_brain = new Brain();
	}
	return *this;
}

Cat::~Cat() {
	putLogLevel("Cat", LOG_LV_WIDTH);
	std::cerr << "Destructor called" << std::endl;
	delete _brain;
}

void Cat::makeSound() const {
	putLogLevel("Cat", LOG_LV_WIDTH);
	std::cerr << "makeSound called: ";
	std::cout << "Meow!" << std::endl;
}
