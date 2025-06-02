/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: teando <teando@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 20:45:03 by teando            #+#    #+#             */
/*   Updated: 2025/06/02 20:45:03 by teando           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap() {
    this->_hitPoints = 100;
    this->_energyPoints = 100;
    this->_attackDamage = 30;
    std::cout << "FragTrap default constructor called" << std::endl;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name) {
    this->_hitPoints = 100;
    this->_energyPoints = 100;
    this->_attackDamage = 30;
    std::cout << "FragTrap name constructor called" << std::endl;
}

FragTrap::FragTrap(const FragTrap &other) : ClapTrap(other) {
    std::cout << "FragTrap copy constructor called" << std::endl;
}

FragTrap &FragTrap::operator=(const FragTrap &other) {
    std::cout << "FragTrap copy assignment operator called" << std::endl;
    if (this != &other) {
        ClapTrap::operator=(other);
    }
    return *this;
}

FragTrap::~FragTrap() {
    std::cout << "FragTrap destructor called" << std::endl;
}

void FragTrap::highFivesGuys(void) {
    std::cout << "FragTrap " << this->_name << " requests a positive high five!" << std::endl;
}

void FragTrap::attack(const std::string &target) {
    if (this->_energyPoints <= 0 || this->_hitPoints <= 0) {
        std::cout << "FragTrap " << this->_name << " can't attack because it has no energy or hit points left!" << std::endl;
        return;
    }
    this->_energyPoints--;
    std::cout << "FragTrap " << this->_name << " attacks " << target << ", causing " << this->_attackDamage << " points of damage!" << std::endl;
}

void FragTrap::takeDamage(unsigned int amount) {
    std::cout << "FragTrap " << this->_name << " takes " << amount << " points of damage!" << std::endl;
    if (this->_hitPoints > static_cast<int>(amount)) {
        this->_hitPoints -= static_cast<int>(amount);
    } else {
        this->_hitPoints = 0;
    }
    std::cout << "FragTrap " << this->_name << " has " << this->_hitPoints << " hit points left." << std::endl;
}

void FragTrap::beRepaired(unsigned int amount) {
    if (this->_energyPoints <= 0 || this->_hitPoints <= 0) {
        std::cout << "FragTrap " << this->_name << " can't repair itself because it has no energy or hit points left!" << std::endl;
        return;
    }
    this->_energyPoints--;
    std::cout << "FragTrap " << this->_name << " repairs itself for " << amount << " hit points!" << std::endl;
    this->_hitPoints += amount;
    std::cout << "FragTrap " << this->_name << " now has " << this->_hitPoints << " hit points." << std::endl;
}
