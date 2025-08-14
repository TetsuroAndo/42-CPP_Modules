/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: teando <teando@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/31 11:51:55 by teando            #+#    #+#             */
/*   Updated: 2025/08/14 09:57:52 by teando           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

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

	return 0;
}
