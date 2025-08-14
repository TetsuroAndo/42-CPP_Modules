/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: teando <teando@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/31 11:52:00 by teando            #+#    #+#             */
/*   Updated: 2025/08/14 09:55:59 by teando           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include <limits>

ClapTrap::ClapTrap() : _name("default"), _hitPoints(100), _energyPoints(50), _attackDamage(20) {
	std::cerr << "[ ClapTrap ] Default constructor called" << std::endl;
}

ClapTrap::ClapTrap(const std::string &name) : _name(name),  _hitPoints(100), _energyPoints(50), _attackDamage(20) {
	std::cerr << "[ ClapTrap ] Name " << name << " constructor called" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &other) : _name(other._name), _hitPoints(other._hitPoints), _energyPoints(other._energyPoints), _attackDamage(other._attackDamage) {
	std::cerr << "[ ClapTrap ] Copy constructor called" << std::endl;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &other) {
	std::cerr << "[ ClapTrap ] Copy assignment operator called" << std::endl;
	if (this != &other) {
		_name = other._name;
		_hitPoints = other._hitPoints;
		_energyPoints = other._energyPoints;
		_attackDamage = other._attackDamage;
	}
	return *this;
}

ClapTrap::~ClapTrap() {
	std::cerr << "[ ClapTrap ] Destructor called" << std::endl;
}

void ClapTrap::attack(const std::string &target) {
	std::cout << "ClapTrap " << _name << " attack to " << target << "!\n";
	if (_energyPoints <= 0 || _hitPoints <= 0) {
		std::cout << "ClapTrap " << _name << " has no energy or hit points!" << std::endl;
		return;
	}
	_energyPoints--;
	std::cout << "ClapTrap " << _name << " attacks "  << target << ", causing " << _attackDamage << " points of damage!" << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount) {
	std::cout << "ClapTrap " << _name << " repairs itself for " << amount << " hit points!\n";
	if (_energyPoints <= 0) {
		std::cout << "ClapTrap " << _name << " has no energy points!" << std::endl;
		return;
	}
	_energyPoints--;
	if (_hitPoints + amount > std::numeric_limits<unsigned int>::max() - _hitPoints) {
		_hitPoints = std::numeric_limits<unsigned int>::max();
	} else {
		_hitPoints += amount;
	}
	std::cout << "ClapTrap " << _name << " now has " << _hitPoints << " hit points and " << _energyPoints << " energy points left." << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount) {
	std::cout << "ClapTrap " << _name << " takes " << amount << " points of damage!" << std::endl;
	if (_hitPoints > amount) {
		_hitPoints -= amount;
	} else {
		_hitPoints = 0;
	}
	std::cout << "ClapTrap " << _name << " has " << _hitPoints << " hit points left." << std::endl;
}
