/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: teando <teando@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/31 15:21:38 by teando            #+#    #+#             */
/*   Updated: 2025/06/04 23:56:45 by teando           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat() : Animal("Cat") {
	std::cout << "[ Cat ] Default constructor called" << std::endl;
}

Cat::Cat(const Cat &other) : Animal(other) {
	std::cout << "[ Cat ] Copy constructor called" << std::endl;
}

Cat &Cat::operator=(const Cat &other) {
	std::cout << "[ Cat ] Copy assignment operator called" << std::endl;
	if (this != &other) {
		Animal::operator=(other);
	}
	return *this;
}

Cat::~Cat() {
	std::cout << "[ Cat ] Destructor called" << std::endl;
}

void Cat::makeSound() const {
	std::cout << "Cat: Meow" << std::endl;
}
