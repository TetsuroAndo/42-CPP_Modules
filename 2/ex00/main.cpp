/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: teando <teando@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 03:25:07 by teando            #+#    #+#             */
/*   Updated: 2025/05/29 03:54:29 by teando           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"
#include <iostream>

int main(int ac, char **av) {
	if (ac != 2) {
		std::cout << "Usage: " << av[0] << " <level>" << std::endl;
		return 1;
	}
	Harl harl;
	std::string s(av[1]);
	for (std::size_t i = 0; i < s.length(); i++) {
		s[i] = std::toupper(s[i]);
	}
	harl.complain(s);
	return 0;
}
