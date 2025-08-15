/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: teando <teando@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/14 10:18:30 by teando            #+#    #+#             */
/*   Updated: 2025/08/15 16:17:06 by teando           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap("default") {
	std::cerr << "[ FragTrap ] Default constructor called" << std::endl;
	this->_hitPoints = 100;
	this->_energyPoints = 100;
	this->_attackDamage = 30;
}

FragTrap::FragTrap(const std::string &name) : ClapTrap(name) {
	std::cerr << "[ FragTrap ] Name: " << name <<" constructor called" << std::endl;
	this->_hitPoints = 100;
	this->_energyPoints = 100;
	this->_attackDamage = 30;
}

FragTrap::FragTrap(const FragTrap &other) : ClapTrap(other) {
	std::cerr << "[ FragTrap ] Copy Constructor called" << std::endl;
}

FragTrap &FragTrap::operator=(const FragTrap &other) {
	std::cerr << "[ FragTrap ] Copy assignment operator called" << std::endl;
	if (this != &other) {
		ClapTrap::operator=(other);
	}
	return *this;
}

FragTrap::~FragTrap() {
	std::cerr << "[ FragTrap ] Destructor called" << std::endl;
}

void FragTrap::highFivesGuys() {
	std::cout << "FragTrap " << _name << " is requesting a high five!" << std::endl;
}

void FragTrap::attack(const std::string &target) {
	std::cout << "FragTrap " << _name << " attack to " << target << "!\n";
	if (_energyPoints <= 0 || _hitPoints <= 0) {
		std::cout << "FragTrap " << _name << " has no energy or hit points!" << std::endl;
		return;
	}
	_energyPoints--;
	std::cout << "FragTrap " << _name << " attacks " << target << ", causing " << _attackDamage << " points of damage!" << std::endl;
}
