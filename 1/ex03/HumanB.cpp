/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: teando <teando@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 02:46:35 by teando            #+#    #+#             */
/*   Updated: 2025/05/30 19:20:09 by teando           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(std::string name) : _name(name), _weapon(NULL) {}

void HumanB::setWeapon(Weapon &weapon) { _weapon = &weapon; }

void HumanB::attack() const {
	if (_weapon == NULL) {
		std::cout << _name << " has no weapon" << std::endl;
		return;
	}
	std::cout	<< _name
				<< " attacks with their "
				<< _weapon->getType()
				<< std::endl;
}
