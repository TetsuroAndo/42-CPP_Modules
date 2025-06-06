/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: teando <teando@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/31 11:52:00 by teando            #+#    #+#             */
/*   Updated: 2025/06/03 13:06:16 by teando           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include <limits>

ClapTrap::ClapTrap() : _name("default"), _hitPoints(10), _energyPoints(10), _attackDamage(0) {
	std::cout << "[ ClapTrap ] Default constructor called" << std::endl;
}

ClapTrap::ClapTrap(std::string name) : _name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0) {
	std::cout << "[ ClapTrap ] Name constructor called" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &other) : _name(other._name), _hitPoints(other._hitPoints), _energyPoints(other._energyPoints), _attackDamage(other._attackDamage) {
	std::cout << "[ ClapTrap ] Copy constructor called" << std::endl;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &other) {
	std::cout << "[ ClapTrap ] Copy assignment operator called" << std::endl;
	if (this != &other) {
		_name = other._name;
		_hitPoints = other._hitPoints;
		_energyPoints = other._energyPoints;
		_attackDamage = other._attackDamage;
	}
	return *this;
}

ClapTrap::~ClapTrap() {
	std::cout << "[ ClapTrap ] Destructor called" << std::endl;
}

void ClapTrap::attack(const std::string &target) {
	if (_energyPoints <= 0 || _hitPoints <= 0) {
		std::cout << "ClapTrap " << _name << " can't attack because it has no energy or hit points left!" << std::endl;
		return;
	}
	_energyPoints--;
	std::cout << "ClapTrap " << _name << " attacks " << target << ", causing " << _attackDamage << " points of damage!" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount) {
	std::cout << "ClapTrap " << _name << " takes " << amount << " points of damage!" << std::endl;
	if (_hitPoints > static_cast<int>(amount)) {
		_hitPoints -= static_cast<int>(amount);
	} else {
		_hitPoints = 0;
	}
	std::cout << "ClapTrap " << _name << " has " << _hitPoints << " hit points left." << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount) {
	if (_energyPoints <= 0 || _hitPoints <= 0) {
		std::cout << "ClapTrap " << _name << " can't repair itself because it has no energy or hit points left!" << std::endl;
		return;
	}
	_energyPoints--;
	std::cout << "ClapTrap " << _name << " repairs itself for " << amount << " hit points!" << std::endl;
	if (static_cast<unsigned int>(std::numeric_limits<int>::max()) - amount < static_cast<unsigned int>(_hitPoints)) {
		_hitPoints = std::numeric_limits<int>::max() - 1;
		std::cout << "ClapTrap " << _name << " hit points maxed out!" << std::endl;
	} else {
		_hitPoints += amount;
	}
	std::cout << "ClapTrap " << _name << " now has " << _hitPoints << " hit points." << std::endl;
}

const std::string &ClapTrap::getName() const {
	return _name;
}
