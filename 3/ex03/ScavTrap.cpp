/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: teando <teando@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/13 19:39:25 by teando            #+#    #+#             */
/*   Updated: 2025/08/15 16:17:00 by teando           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap("default"), _guardMode(false) {
	std::cerr << "[ ScavTrap ] Default constructor called" << std::endl;
	this->_hitPoints = 100;
	this->_energyPoints = 50;
	this->_attackDamage = 20;
}

ScavTrap::ScavTrap(const std::string &name) : ClapTrap(name), _guardMode(false) {
	std::cerr << "[ ScavTrap ] Name: " << name <<" constructor called" << std::endl;
	this->_hitPoints = 100;
	this->_energyPoints = 50;
	this->_attackDamage = 20;
}

ScavTrap::ScavTrap(const ScavTrap &other) : ClapTrap(other), _guardMode(other._guardMode) {
	std::cerr << "[ ScavTrap ] Copy Constructor called" << std::endl;
}

ScavTrap &ScavTrap::operator=(const ScavTrap &other) {
	std::cerr << "[ ScavTrap ] Copy assignment operator called" << std::endl;
	if (this != &other) {
		ClapTrap::operator=(other);
		_guardMode = other._guardMode;
	}
	return *this;
}

ScavTrap::~ScavTrap() {
	std::cerr << "[ ScavTrap ] Destructor called" << std::endl;
}


void ScavTrap::guardGate() {
	if (_guardMode) {
		std::cout << "ScavTrap " << _name << " is already in guard mode!" << std::endl;
	} else {
		std::cout << "ScavTrap " << _name << " is now in guard mode!" << std::endl;
		_guardMode = true;
	}
}

void ScavTrap::attack(const std::string &target) {
	std::cout << "ScavTrap " << _name << " attack to " << target << "!\n";
	if (_energyPoints <= 0 || _hitPoints <= 0) {
		std::cout << "ScavTrap " << _name << " has no energy or hit points!" << std::endl;
		return;
	}
	_energyPoints--;
	std::cout << "ScavTrap " << _name << " attacks "  << target << ", causing " << _attackDamage << " points of damage!" << std::endl;
}
