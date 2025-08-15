/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: teando <teando@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/15 11:05:25 by teando            #+#    #+#             */
/*   Updated: 2025/08/15 16:12:55 by teando           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"

int main() {

	std::cout << "\n--- Animal ---\n" << std::endl;

	Animal *animals[3];

	animals[0] = new Animal();
	animals[1] = new Dog();
	animals[2] = new Cat();

	for (int i = 0; i < 3; ++i) {
		std::cout << "Animal type: " << animals[i]->getType() << std::endl;
		animals[i]->makeSound();
		delete animals[i];
	}

	std::cout << "\n--- Wrong Animal ---\n" << std::endl;

	WrongAnimal *wrongAnimals[2];

	wrongAnimals[0] = new WrongAnimal();
	wrongAnimals[1] = new WrongCat();

	for (int i = 0; i < 2; ++i) {
		std::cout << "Animal type: " << wrongAnimals[i]->getType() << std::endl;
		wrongAnimals[i]->makeSound();
		delete wrongAnimals[i];
	}

	return 0;
}
