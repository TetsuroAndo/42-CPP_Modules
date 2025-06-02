/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: teando <teando@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 21:45:00 by teando            #+#    #+#             */
/*   Updated: 2025/06/02 22:12:17 by teando           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap() : ClapTrap("default_clap_name"), FragTrap(), ScavTrap() {
    this->_name = "default";
    ClapTrap::_hitPoints = 100;      // FragTrapから継承（100）
    ClapTrap::_energyPoints = 50;    // ScavTrapから継承（50）
    ClapTrap::_attackDamage = 30;    // FragTrapから継承（30）
    std::cout << "[ DiamondTrap ] Default constructor called" << std::endl;
}

DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name + "_clap_name"), FragTrap(name), ScavTrap(name) {
    this->_name = name;
    ClapTrap::_hitPoints = 100;      // FragTrapから継承（100）
    ClapTrap::_energyPoints = 50;    // ScavTrapから継承（50）
    ClapTrap::_attackDamage = 30;    // FragTrapから継承（30）
    std::cout << "[ DiamondTrap ] Name constructor called" << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap &other) : ClapTrap(other), FragTrap(other), ScavTrap(other) {
    this->_name = other._name;
    std::cout << "[ DiamondTrap ] Copy constructor called" << std::endl;
}

DiamondTrap &DiamondTrap::operator=(const DiamondTrap &other) {
    std::cout << "[ DiamondTrap ] Copy assignment operator called" << std::endl;
    if (this != &other) {
        ClapTrap::operator=(other);
        this->_name = other._name;
    }
    return *this;
}

DiamondTrap::~DiamondTrap() {
    std::cout << "[ DiamondTrap ] Destructor called" << std::endl;
}

const std::string& DiamondTrap::getName() const {
    return _name;
}

// ScavTrapのattackメソッドを使用
void DiamondTrap::attack(const std::string &target) {
    ScavTrap::attack(target);
}

// 自分の名前とClapTrapの名前を表示
void DiamondTrap::whoAmI() {
    std::cout << "I am DiamondTrap " << getName() << ", also known as ClapTrap " << ClapTrap::getName() << std::endl;
}
