/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: teando <teando@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/31 11:51:55 by teando            #+#    #+#             */
/*   Updated: 2025/08/14 20:34:25 by teando           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"

int main(void) {
std::cout << "--- 💎 DiamondTrap Construction 💎 ---\n" << std::endl;
	DiamondTrap diamond("HERO");

	std::cout << "\n--- 📝 Initial Status Check 📝 ---\n" << std::endl;
	diamond.whoAmI();

	std::cout << "Initial HP and EP: " << std::endl;
	diamond.beRepaired(0);
	std::cout << "Initial AD: " << std::endl;
	diamond.attack("Target");

	std::cout << "\n--- 💥 Testing Abilities 💥 ---\n" << std::endl;

	diamond.attack("Villain");
	diamond.takeDamage(20);
	diamond.beRepaired(10);
	std::cout << std::endl;

	diamond.guardGate();
	diamond.highFivesGuys();

	std::cout << "\n--- 📜 Orthodox Canonical Form Test 📜 ---\n" << std::endl;
	DiamondTrap diamond_copy(diamond);
	std::cout << "--- Copied Diamond ---\n";
	diamond_copy.whoAmI();
	diamond_copy.attack("Another Villain");

	DiamondTrap diamond_assign("Dummy");
	diamond_assign = diamond;
	std::cout << "--- Assigned Diamond ---\n";
	diamond_assign.whoAmI();


	std::cout << "\n--- 💥 No Energy/HP Test 💥 ---\n" << std::endl;
	diamond.takeDamage(1000);
	diamond.attack("Ghost");
	diamond.beRepaired(10);

	std::cout << "\n--- 💣 Destruction 💣 ---\n" << std::endl;
	return 0;
}
