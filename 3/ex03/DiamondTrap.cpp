/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: teando <teando@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/14 12:37:54 by teando            #+#    #+#             */
/*   Updated: 2025/08/14 13:14:17 by teando           ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap() : ScavTrap("default_clap_name"), FragTrap("default_clap_name"), _name("default") {
	std::cerr << "[DiamondTrap] Default constructor called" << std::endl;
	this->ClapTrap::_name = _name + "_clap_name";
	this->_hitPoints = FragTrap::_hitPoints;
	this->_energyPoints = ScavTrap::_energyPoints;
	this->_attackDamage = FragTrap::_attackDamage;
}

DiamondTrap::DiamondTrap(const std::string &name) : ScavTrap(name + "_clap_name"), FragTrap(name + "_clap_name"), _name(name) {
	std::cerr << "[DiamondTrap] name: " << name << " constructor called" << std::endl;
	this->_name = name;
	this->ClapTrap::_name = _name + "_clap_name";
	this->_hitPoints = FragTrap::_hitPoints;
	this->_energyPoints = ScavTrap::_energyPoints;
	this->_attackDamage = FragTrap::_attackDamage;
}

DiamondTrap::DiamondTrap(const DiamondTrap &other) : ScavTrap(other), FragTrap(other), _name(other._name) {
	std::cerr << "[DiamondTrap] Copy constructor called" << std::endl;
}

DiamondTrap &DiamondTrap::operator=(const DiamondTrap &other) {
	std::cerr << "[DiamondTrap] Copy assignment operator called" << std::endl;
	if (this != &other) {
		this->_name = other._name;
	}
	return *this;
}

DiamondTrap::~DiamondTrap() {
	std::cerr << "[DiamondTrap] Destructor called" << std::endl;
}

void DiamondTrap::whoAmI() {
	std::cout << "My name is " << this->_name << " and my ClapTrap name is " << this->ClapTrap::_name << std::endl;
}

void DiamondTrap::attack(const std::string &target) {
	ScavTrap::attack(target);
}
