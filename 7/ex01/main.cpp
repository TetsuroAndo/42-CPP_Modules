/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: teando <teando@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 21:29:40 by teando            #+#    #+#             */
/*   Updated: 2025/09/03 05:06:16 by teando           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"

template <typename T>
void printElem(const T& elem) {
	std::cout << elem << std::endl;
}

void increment(int& x) {
	++x;
}

int main() {
	int nums[] = {1, 2, 3, 4, 5};
	size_t numsLen = sizeof(nums) / sizeof(nums[0]);

	std::cout << "Original ints:" << std::endl;
	iter(nums, numsLen, printElem<int>);

	iter(nums, numsLen, increment);

	std::cout << "After increment:" << std::endl;
	iter(nums, numsLen, printElem<int>);

	const std::string words[] = {"hello", "world", "iter"};
	size_t wordsLen = sizeof(words) / sizeof(words[0]);

	std::cout << "Const strings:" << std::endl;
	iter(words, wordsLen, printElem<std::string>);

	return 0;
}
