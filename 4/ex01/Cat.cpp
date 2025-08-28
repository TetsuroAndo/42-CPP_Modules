/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: teando <teando@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/15 11:05:35 by teando            #+#    #+#             */
/*   Updated: 2025/08/28 22:31:05 by teando           ###   ########.fr       */
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
	_brain = new Brain(*other._brain);
}

Cat &Cat::operator=(const Cat &other) {
	putLogLevel("Cat", LOG_LV_WIDTH);
	std::cerr << "Copy assignment operator called" << std::endl;
	if (this != &other) {
		Animal::operator=(other);
		Brain* tmp = new Brain(*other._brain);
		if (tmp == NULL) return *this;
		delete _brain;
		_brain = tmp;
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

Brain *Cat::getBrain() const {
	return _brain;
}
