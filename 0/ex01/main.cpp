/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: teando <teando@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 06:58:33 by teando            #+#    #+#             */
/*   Updated: 2025/05/29 23:36:37 by teando           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include <iostream>

int main() {
	PhoneBook book;
	std::string cmd;

	std::cout << "=== My Awesome PhoneBook ===\n";
	while (std::cout << "\nCommand [ADD | SEARCH | EXIT]: "
		&& std::getline(std::cin, cmd))
	{
		for (std::string::iterator it = cmd.begin(); it != cmd.end(); ++it)
			*it = std::toupper(static_cast<unsigned char>(*it));
		if (cmd == "ADD")
			book.add();
		else if (cmd == "SEARCH")
			book.search();
		else if (cmd == "EXIT")
			break;
		else if (!cmd.empty())
			std::cout << "Unknown command.\n";
	}
	std::cout << "Bye!" << std::endl;
	return 0;
}
