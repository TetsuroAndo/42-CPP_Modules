/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: teando <teando@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/31 15:21:31 by teando            #+#    #+#             */
/*   Updated: 2025/06/04 23:56:41 by teando           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog() : Animal("Dog") {
	std::cout << "[ Dog ] Default constructor called" << std::endl;
}

Dog::Dog(const Dog &other) : Animal(other) {
	std::cout << "[ Dog ] Copy constructor called" << std::endl;
}

Dog &Dog::operator=(const Dog &other) {
	std::cout << "[ Dog ] Copy assignment operator called" << std::endl;
	if (this != &other) {
		Animal::operator=(other);
	}
	return *this;
}

Dog::~Dog() {
	std::cout << "[ Dog ] Destructor called" << std::endl;
}

void Dog::makeSound() const {
	std::cout << "Dog: Woof" << std::endl;
}