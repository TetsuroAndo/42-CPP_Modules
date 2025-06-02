/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: teando <teando@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 20:45:03 by teando            #+#    #+#             */
/*   Updated: 2025/06/02 21:41:22 by teando           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap() {
    _hitPoints = 100;
    _energyPoints = 50;
    _attackDamage = 20;
    std::cout << "[ ScavTrap ] Default constructor called" << std::endl;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name) {
    _hitPoints = 100;
    _energyPoints = 50;
    _attackDamage = 20;
    std::cout << "[ ScavTrap ] Name constructor called" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &other) : ClapTrap(other) {
    std::cout << "[ ScavTrap ] Copy constructor called" << std::endl;
}

ScavTrap &ScavTrap::operator=(const ScavTrap &other) {
    std::cout << "[ ScavTrap ] Copy assignment operator called" << std::endl;
    if (this != &other) {
        ClapTrap::operator=(other);
    }
    return *this;
}

ScavTrap::~ScavTrap() {
    std::cout << "[ ScavTrap ] Destructor called" << std::endl;
}

void ScavTrap::attack(const std::string &target) {
    if (_energyPoints <= 0 || _hitPoints <= 0) {
        std::cout << "ScavTrap " << getName() << " can't attack because it has no energy or hit points left!" << std::endl;
        return;
    }
    _energyPoints--;
    std::cout << "ScavTrap " << getName() << " attacks " << target << ", causing " << _attackDamage << " points of damage!" << std::endl;
}

void ScavTrap::takeDamage(unsigned int amount) {
    std::cout << "ScavTrap " << getName() << " takes " << amount << " points of damage!" << std::endl;
    if (this->_hitPoints > static_cast<int>(amount)) {
        this->_hitPoints -= static_cast<int>(amount);
    } else {
        this->_hitPoints = 0;
    }
    std::cout << "ScavTrap " << getName() << " has " << this->_hitPoints << " hit points left." << std::endl;
}

void ScavTrap::beRepaired(unsigned int amount) {
    if (this->_energyPoints <= 0 || this->_hitPoints <= 0) {
        std::cout << "ScavTrap " << getName() << " can't repair itself because it has no energy or hit points left!" << std::endl;
        return;
    }
    this->_energyPoints--;
    std::cout << "ScavTrap " << getName() << " repairs itself for " << amount << " hit points!" << std::endl;
    this->_hitPoints += amount;
    std::cout << "ScavTrap " << getName() << " now has " << this->_hitPoints << " hit points." << std::endl;
}

void ScavTrap::guardGate() {
    std::cout << "ScavTrap " << getName() << " is now in Gate keeper mode" << std::endl;
}
