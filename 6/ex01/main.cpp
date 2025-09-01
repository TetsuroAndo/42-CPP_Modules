/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: teando <teando@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 14:32:15 by teando            #+#    #+#             */
/*   Updated: 2025/09/01 15:08:15 by teando           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

int main () {
	// 1. Create Data structure
	Data* originPtr = new Data;
	originPtr->s = "Hello, world!";

	std::cout << "Original Pointer Address: " << originPtr << std::endl;
	std::cout << "Original Data: s = \"" << originPtr->s << "\"" << std::endl;

	// 2. Serialize from original pointer (Transform to uintptr_t)
	uintptr_t raw = Serializer::serialize(originPtr);
	std::cout << "\nSerialized to uintptr_t: " << raw << std::endl;
	std::cout << "Size of uintptr_t: " << sizeof(raw) << " bytes" << std::endl;

	// 3. Deserialize uintptr_t (Transform back to Data*)
	Data* deserializedPtr = Serializer::deserialize(raw);
	std::cout << "\nDeserialized Pointer Address: " << deserializedPtr << std::endl;

	// 4. Check if the original and deserialized pointers are the same
	if (deserializedPtr == originPtr) {
		std::cout << "\nSuccess: Pointers are the same." << std::endl;
		std::cout << "Deserialized Data: s = \"" << deserializedPtr->s << "\"" << std::endl;
	} else {
		std::cout << "\nFailure: Pointers are different." << std::endl;
	}

	delete originPtr;
	return 0;
}
