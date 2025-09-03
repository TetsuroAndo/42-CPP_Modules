/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: teando <teando@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/04 06:11:30 by teando            #+#    #+#             */
/*   Updated: 2025/09/04 08:36:12 by teando           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <list>
#include "MutantStack.hpp"

int main()
{
	std::cout << "--- Testing MutantStack ---" << std::endl;
	{
		MutantStack<int> mstack;

		// Pushing elements
		mstack.push(5);
		mstack.push(17);

		// Testing top()
		std::cout << "Top element is: " << mstack.top() << std::endl; // Should be 17

		// Testing pop()
		mstack.pop();

		// Testing size()
		std::cout << "Size after pop: " << mstack.size() << std::endl; // Should be 1

		// Pushing more elements
		mstack.push(3);
		mstack.push(5);
		mstack.push(737);
		mstack.push(0);

		std::cout << "\nIterating through MutantStack:" << std::endl;
		MutantStack<int>::iterator it = mstack.begin();
		MutantStack<int>::iterator ite = mstack.end();

		// Test increment and decrement
		++it;
		--it;

		while (it != ite)
		{
			std::cout << *it << std::endl;
			++it;
		}

		// Test copy constructor
		std::cout << "\nTesting copy and assignment:" << std::endl;
		std::stack<int> s(mstack); // Copying to a standard stack
		MutantStack<int> mstack_copy = mstack;
		std::cout << "Top of original: " << mstack.top() << std::endl;
		std::cout << "Top of copy: " << mstack_copy.top() << std::endl;
	}

	std::cout << "\n--- Comparing with std::list ---" << std::endl;
	{
		std::list<int> list;

		// Performing the same operations as with MutantStack
		list.push_back(5);
		list.push_back(17);
		std::cout << "Back element is: " << list.back() << std::endl; // list uses back()
		list.pop_back(); // list uses pop_back()
		std::cout << "Size after pop: " << list.size() << std::endl;
		list.push_back(3);
		list.push_back(5);
		list.push_back(737);
		list.push_back(0);

		std::cout << "\nIterating through std::list:" << std::endl;
		std::list<int>::iterator it = list.begin();
		std::list<int>::iterator ite = list.end();
		++it;
		--it;
		while (it != ite)
		{
			std::cout << *it << std::endl;
			++it;
		}
	}

	return 0;
}
