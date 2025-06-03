/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: teando <teando@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 20:45:03 by teando            #+#    #+#             */
/*   Updated: 2025/06/02 22:36:16 by teando           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap() {
    _hitPoints = 100;
    _energyPoints = 100;
    _attackDamage = 30;
    std::cout << "[ FragTrap ] Default constructor called" << std::endl;
}

FragTrap::FragTrap(const std::string &name) : ClapTrap(name) {
    _hitPoints = 100;
    _energyPoints = 100;
    _attackDamage = 30;
    std::cout << "[ FragTrap ] Name constructor called" << std::endl;
}

FragTrap::FragTrap(const FragTrap &other) : ClapTrap(other) {
    std::cout << "[ FragTrap ] Copy constructor called" << std::endl;
}

FragTrap &FragTrap::operator=(const FragTrap &other) {
    std::cout << "[ FragTrap ] Copy assignment operator called" << std::endl;
    if (this != &other) {
        ClapTrap::operator=(other);
    }
    return *this;
}

FragTrap::~FragTrap() {
    std::cout << "[ FragTrap ] Destructor called" << std::endl;
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
