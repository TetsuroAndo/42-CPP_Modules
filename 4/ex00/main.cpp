/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: teando <teando@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/15 11:05:25 by teando            #+#    #+#             */
/*   Updated: 2025/08/15 17:44:21 by teando           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"

int main() {

	std::cout << "\n--- Create Dog and Cat Array ---\n" << std::endl;
	const int numAnimals = 3;
	Animal* animals[numAnimals];
	animals[0] = new Cat();
	animals[1] = new Dog();
	animals[2] = new Animal();
	
	for (int i = 0; i < numAnimals; ++i) {
		std::cout << "Animal type: " << animals[i]->getType() << "\n";
		animals[i]->makeSound();
	}

	std::cout << "\n--- Destroy ---\n" << std::endl;
	for (int i = 0; i < numAnimals; ++i) {
		delete animals[i];
	}

	std::cout << "\n--- Wrong Animal ---\n" << std::endl;
	WrongAnimal *wrongAnimals[2];
	wrongAnimals[0] = new WrongAnimal();
	wrongAnimals[1] = new WrongCat();

	for (int i = 0; i < 2; ++i) {
		std::cout << "Animal type: " << wrongAnimals[i]->getType() << "\n";
		wrongAnimals[i]->makeSound();
	}

	std::cout << "\n--- Destroy ---\n" << std::endl;
	for (int i = 0; i < 2; ++i) {
		delete wrongAnimals[i];
	}

	return 0;
}
