/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: teando <teando@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 21:29:40 by teando            #+#    #+#             */
/*   Updated: 2025/09/02 04:44:32 by teando           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"

namespace {
	template <class T>
	void printElement(const T &e) {
		std::cout << e << std::endl;
	}
}

int main() {
	int arr[] = {1, 2, 3, 4, 5};
	std::string strArr[] = {"Hello", "World", "!"};

	std::cout << "int array:" << std::endl;
	iter(arr, 5, printElement<int>);

	std::cout << "string array:" << std::endl;
	iter(strArr, 3, printElement<std::string>);

	return 0;
}
