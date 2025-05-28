/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: teando <teando@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 03:25:04 by teando            #+#    #+#             */
/*   Updated: 2025/05/29 04:31:10 by teando           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"
#include <iostream>

void Harl::debug(void) {
	std::cout << "[ DEBUG ]\nI love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger.\nI really do!\n" << std::endl;
}

void Harl::info(void) {
	std::cout << "[ INFO ]\nI cannot believe adding extra bacon costs more money.\nYou didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!\n" << std::endl;
}

void Harl::warning(void) {
	std::cout << "[ WARNING ]\nI think I deserve to have some extra bacon for free.\nI've been coming for years, whereas you started working here just last month.\n" << std::endl;
}

void Harl::error(void) {
	std::cout << "[ ERROR ]\nThis is unacceptable! I want to speak to the manager now.\n" << std::endl;
}

void Harl::complain(std::string level) {
	const std::string levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	t_FuncPtr funcs[4] = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};

	int idx = -1;
	for (int i = 0; i < 4; i++) {
		if (levels[i] == level)
			idx = i;
	}
	switch (idx) {
		default:
			std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
			break;
		case 0:
			(this->*funcs[0])();
		case 1:
			(this->*funcs[1])();
		case 2:
			(this->*funcs[2])();
		case 3:
			(this->*funcs[3])();
	}
}
