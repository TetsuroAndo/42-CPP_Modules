/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: teando <teando@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/15 15:04:24 by teando            #+#    #+#             */
/*   Updated: 2025/08/15 16:02:37 by teando           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal("WrongCat") {
	putLogLevel("WrongCat", LOG_LV_WIDTH);
	std::cerr << "Default constructor called" << std::endl;
}

WrongCat::WrongCat(const WrongCat &other) : WrongAnimal(other) {
	putLogLevel("WrongCat", LOG_LV_WIDTH);
	std::cerr << "Copy constructor called" << std::endl;
}

WrongCat &WrongCat::operator=(const WrongCat &other) {
	putLogLevel("WrongCat", LOG_LV_WIDTH);
	std::cerr << "Copy assignment operator called" << std::endl;
	if (this != &other) {
		WrongAnimal::operator=(other);
	}
	return *this;
}

WrongCat::~WrongCat() {
	putLogLevel("WrongCat", LOG_LV_WIDTH);
	std::cerr << "Destructor called" << std::endl;
}

void WrongCat::makeSound() const {
	putLogLevel("WrongCat", LOG_LV_WIDTH);
	std::cerr << "makeSound called: ";
	std::cout << "Wrong Meow!" << std::endl;
}
