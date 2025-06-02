/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: teando <teando@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 20:45:03 by teando            #+#    #+#             */
/*   Updated: 2025/06/02 20:45:03 by teando           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

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

    std::cout << "\n=== Testing FragTrap ===" << std::endl;
    FragTrap fragtrap("FT-001");
    fragtrap.attack("Monster");
    fragtrap.takeDamage(50);
    fragtrap.beRepaired(30);
    fragtrap.highFivesGuys();

    std::cout << "\n=== Testing Destruction Order ===" << std::endl;
    {
        std::cout << "\n--- ScavTrap ---" << std::endl;
        ScavTrap tempScav("TempScav");
        std::cout << "ScavTrap object going out of scope..." << std::endl;
    }
    {
        std::cout << "\n--- FragTrap ---" << std::endl;
        FragTrap tempFrag("TempFrag");
        std::cout << "FragTrap object going out of scope..." << std::endl;
    }

    return 0;
}
