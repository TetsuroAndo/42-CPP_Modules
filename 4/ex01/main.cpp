/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: teando <teando@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/31 15:20:05 by teando            #+#    #+#             */
/*   Updated: 2025/06/03 15:26:44 by teando           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include <iostream>

void testBasicPolymorphism() {
	std::cout << "\n===== Basic Polymorphism Test =====\n" << std::endl;

	const Animal *meta = new Animal();
	const Animal *j = new Dog();
	const Animal *i = new Cat();

	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;

	i->makeSound();	   // Will output the cat sound!
	j->makeSound();	   // Will output the dog sound!
	meta->makeSound(); // Will output the animal sound!

	delete meta;
	delete j;
	delete i;
}

void testWrongPolymorphism() {
	std::cout << "\n===== Wrong Polymorphism Test =====\n" << std::endl;

	const WrongAnimal *wrongMeta = new WrongAnimal();
	const WrongAnimal *wrongCat = new WrongCat();

	std::cout << wrongMeta->getType() << " " << std::endl;
	std::cout << wrongCat->getType() << " " << std::endl;

	wrongMeta->makeSound(); // Will output the wrong animal sound
	wrongCat->makeSound();	// Will also output the wrong animal sound (NOT cat
						   // sound) This demonstrates the problem when not
						   // using virtual functions

	// Direct call to demonstrate the difference
	const WrongCat directWrongCat;
	directWrongCat
		.makeSound(); // Will output the cat sound when called directly

	delete wrongMeta;
	delete wrongCat;
}

void testAnimalArray() {
	std::cout << "\n===== Animal Array Test =====\n" << std::endl;

	const int arraySize = 10;
	Animal *animals[arraySize];

	// Fill the array with Dogs and Cats
	for (int i = 0; i < arraySize; i++) {
		if (i % 2 == 0) {
			animals[i] = new Dog();
		} else {
			animals[i] = new Cat();
		}
	}

	// Make all animals sound
	std::cout << "\nMaking all animals sound:\n" << std::endl;
	for (int i = 0; i < arraySize; i++) {
		std::cout << "Animal " << i << " (" << animals[i]->getType() << "): ";
		animals[i]->makeSound();
	}

	// Clean up
	for (int i = 0; i < arraySize; i++) {
		delete animals[i];
	}
}

int main() {
	testBasicPolymorphism();
	testWrongPolymorphism();
	testAnimalArray();
	return 0;
}
