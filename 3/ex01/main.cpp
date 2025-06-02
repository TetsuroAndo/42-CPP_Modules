/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: teando <teando@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/31 11:51:55 by teando            #+#    #+#             */
/*   Updated: 2025/05/31 11:54:37 by teando           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main(void) {
	std::cout << "=== Testing ClapTrap ===" << std::endl;
	ClapTrap claptrap("CT-001");
	claptrap.attack("Target");
	claptrap.takeDamage(5);
	claptrap.beRepaired(3);

	std::cout << "\n=== Testing ScavTrap ===" << std::endl;
	ScavTrap scavtrap("ST-001");
	scavtrap.attack("Enemy");
	scavtrap.takeDamage(30);
	scavtrap.beRepaired(20);
	scavtrap.guardGate();

	std::cout << "\n=== Testing Destruction Order ===" << std::endl;
	{
		ScavTrap temp("Temp");
		std::cout << "ScavTrap object going out of scope..." << std::endl;
	}

	return 0;
}