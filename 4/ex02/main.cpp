/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: teando <teando@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/15 11:05:25 by teando            #+#    #+#             */
/*   Updated: 2025/08/15 17:47:02 by teando           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"
#include "Brain.hpp"

int main() {
	std::cout << "\n--- Create Dog and Cat Array ---\n" << std::endl;
	const int numAnimals = 3;
	Animal* animals[numAnimals];
	animals[0] = new Cat();
	animals[1] = new Dog();
	//animals[2] = new Animal();
	animals[2] = new Cat(); // Changed to Cat for demonstration

	for (int i = 0; i < numAnimals; ++i) {
		std::cout << "Animal type: " << animals[i]->getType() << "\n";
		animals[i]->makeSound();
	}

	std::cout << "\n--- Destroy ---\n" << std::endl;
	for (int i = 0; i < numAnimals; ++i) {
		delete animals[i];
	}

	// std::cout << "\n--- Wrong Animal ---\n" << std::endl;
	// WrongAnimal *wrongAnimals[2];
	// wrongAnimals[0] = new WrongAnimal();
	// wrongAnimals[1] = new WrongCat();

	// for (int i = 0; i < 2; ++i) {
	// 	std::cout << "Animal type: " << wrongAnimals[i]->getType() << "\n";
	// 	wrongAnimals[i]->makeSound();
	// }

	// std::cout << "\n--- Destroy ---\n" << std::endl;
	// for (int i = 0; i < 2; ++i) {
	// 	delete wrongAnimals[i];
	// }
	
	std::cout << "\n--- Test Deep Copy ---\n" << std::endl;
	Dog* original_dog = new Dog();
	original_dog->getBrain()->setIdea(0, "I want to chase the mailman!");
	Dog* copied_dog = new Dog(*original_dog);

	std::cout << "Original Dog's Idea: " << original_dog->getBrain()->getIdea(0) << std::endl;
	std::cout << "Copied Dog's Idea:   " << copied_dog->getBrain()->getIdea(0) << std::endl;

	std::cout << "\n--- Change idea ---\n" << std::endl;
	original_dog->getBrain()->setIdea(0, "I want a bone!");

	std::cout << "Original Dog's new Idea: " << original_dog->getBrain()->getIdea(0) << std::endl;
	std::cout << "Copied Dog's Idea (should be unchanged): " << copied_dog->getBrain()->getIdea(0) << std::endl;

	// check if the copied dog has its own brain
	std::cout << "\n--- Delete original ---\n" << std::endl;
	delete original_dog;

	std::cout << "\n--- Check if the copied dog has its own brain ---\n" << std::endl;
	std::cout << "Copied Dog's Idea after original is deleted: " << copied_dog->getBrain()->getIdea(0) << std::endl;
	delete copied_dog;

	std::cout << "\n--- Test Deep Copy (Assignment Operator) ---\n" << std::endl;
	Cat cat1;
	cat1.getBrain()->setIdea(0, "I want to sleep.");

	Cat cat2;
	cat2 = cat1; // using assignment operator here

	std::cout << "Cat1's Idea: " << cat1.getBrain()->getIdea(0) << std::endl;
	std::cout << "Cat2's Idea: " << cat2.getBrain()->getIdea(0) << std::endl;

	std::cout << "\n--- Change Cat1's idea ---\n" << std::endl;
	cat1.getBrain()->setIdea(0, "I want to eat.");

	std::cout << "Cat1's new Idea: " << cat1.getBrain()->getIdea(0) << std::endl;
	std::cout << "Cat2's Idea (should be unchanged): " << cat2.getBrain()->getIdea(0) << std::endl;

	std::cout << "\n--- Clean up ---\n" << std::endl;
	return 0;
}
