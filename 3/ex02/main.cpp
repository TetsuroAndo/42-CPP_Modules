/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: teando <teando@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/31 11:51:55 by teando            #+#    #+#             */
/*   Updated: 2025/08/14 11:43:50 by teando           ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main(void) {
	ClapTrap claptrap("CT-001");
	claptrap.attack("Target");
	claptrap.takeDamage(5);
	claptrap.beRepaired(3);

	ScavTrap scavtrap("ST-002");
	scavtrap.attack("Target");
	scavtrap.takeDamage(5);
	scavtrap.beRepaired(3);
	scavtrap.guardGate();

	FragTrap fragtrap("FT-003");
	fragtrap.attack("Target");
	fragtrap.takeDamage(500);
	fragtrap.beRepaired(1200);
	fragtrap.highFivesGuys();

	return 0;
}
