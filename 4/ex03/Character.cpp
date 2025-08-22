/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: teando <teando@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/22 17:26:40 by teando            #+#    #+#             */
/*   Updated: 2025/08/23 05:54:17 by teando           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

Character::Character() : _name("undefined") {
	std::cerr << "[ Character ] Default constructor called" << std::endl;
	for (int i = 0; i < _inventorySize; i++) {
		_inventory[i] = NULL;
	}
}

Character::Character(std::string const & name) : _name(name) {
	std::cerr << "[ Character ] Name: " << name << " constructor called" << std::endl;
	for (int i = 0; i < _inventorySize; i++) {
		_inventory[i] = NULL;
	}
}

Character::Character(const Character &other) : _name(other._name) {
	std::cerr << "[ Character ] Copy constructor called" << std::endl;
	*this = other;
}

Character &Character::operator=(const Character &other) {
	std::cerr << "[ Character ] Copy assignment operator called" << std::endl;
	if(this != &other) {
		for (int i = 0; i < _inventorySize; i++) {
			if (_inventory[i])
				delete _inventory[i];
			if (other._inventory[i])
				_inventory[i] = other._inventory[i]->clone();
			else _inventory[i] = NULL;
		}
		_name = other._name;
	}
	return *this;
}

Character::~Character() {
	std::cerr << "[ Character ] Destructor called" << std::endl;
	for (int i = 0; i < _inventorySize; i++) {
		if (_inventory[i])
			delete _inventory[i];
	}
}

std::string const & Character::getName() const {
	return _name;
}

void Character::equip(AMateria* m) {
	if (!m) return;
	for (int i = 0; i < _inventorySize; i++) {
		if (!_inventory[i]) {
			_inventory[i] = m;
			return;
		}
	}
}

void Character::unequip(int idx) {
	if (idx < 0 || idx >= _inventorySize) return;
	if (_inventory[idx]) {
		delete _inventory[idx];
		_inventory[idx] = NULL;
	}
}

void Character::use(int idx, ICharacter& target) {
	if (idx < 0 || idx >= _inventorySize) return;
	if (_inventory[idx])
		_inventory[idx]->use(target);
}
