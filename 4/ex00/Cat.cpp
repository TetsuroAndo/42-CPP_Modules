/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: teando <teando@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/15 11:05:35 by teando            #+#    #+#             */
/*   Updated: 2025/08/15 11:52:15 by teando           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat(std::string type) : Animal(type) {
	std::cerr << "[ Cat ] Constructor called" << std::endl;
}

Cat::Cat(const Cat &other) : Animal(other) {
	std::cerr << "[ Cat ] Copy constructor called" << std::endl;
}

Cat &Cat::operator=(const Cat &other) {
	std::cerr << "[ Cat ] Copy assignment operator called" << std::endl;
	if (this != &other) {
		Animal::operator=(other);
	}
	return *this;
}

Cat::~Cat() {
	std::cerr << "[ Cat ] Destructor called" << std::endl;
}

void Cat::makeSound() const {
	std::cerr << "[ Cat ] makeSound called: ";
	std::cout << "Meow!" << std::endl;
}
