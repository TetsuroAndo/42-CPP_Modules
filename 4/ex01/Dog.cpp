/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: teando <teando@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/31 15:21:31 by teando            #+#    #+#             */
/*   Updated: 2025/06/05 00:04:28 by teando           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog() : Animal("Dog"), brain(new Brain) {
	std::cout << "[ Dog ] Default constructor called" << std::endl;
}

Dog::Dog(const Dog &other) : Animal(other), brain(new Brain(*other.brain)) {
	std::cout << "[ Dog ] Copy constructor called" << std::endl;
}

Dog &Dog::operator=(const Dog &other) {
	std::cout << "[ Dog ] Copy assignment operator called" << std::endl;
	if (this != &other) {
		Animal::operator=(other);
		delete brain;
		*brain = *other.brain;
	}
	return *this;
}

Dog::~Dog() {
	std::cout << "[ Dog ] Destructor called" << std::endl;
	delete brain;
}

void Dog::makeSound() const {
	std::cout << "Dog: Woof" << std::endl;
}