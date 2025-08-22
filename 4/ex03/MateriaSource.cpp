/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: teando <teando@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/23 05:43:12 by teando            #+#    #+#             */
/*   Updated: 2025/08/23 06:08:04 by teando           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"
#include "PutLogLv.h"

MateriaSource::MateriaSource() {
	putLogLevel("MateriaSource", LOG_LV_WIDTH);
	std::cerr << "Default Constructor called" << std::endl;
	for (int i = 0; i < _learnedNum; i++) _learned[i] = NULL;
}

MateriaSource::MateriaSource(const MateriaSource &other) {
	putLogLevel("MateriaSource", LOG_LV_WIDTH);
	std::cerr << "Copy Constructor called" << std::endl;
	for (int i = 0; i < _learnedNum; i++) {
		if (other._learned[i])
			_learned[i] = other._learned[i]->clone();
	}
}

MateriaSource &MateriaSource::operator=(const MateriaSource &other) {
	putLogLevel("MateriaSource", LOG_LV_WIDTH);
	std::cerr << "Copy assignment operator called" << std::endl;
	if (this != &other) {
		for (int i = 0; i < _learnedNum; i++) {
			if (_learned[i])
				delete _learned[i];
			if (other._learned[i])
				_learned[i] = other._learned[i]->clone();
			else _learned[i] = NULL;
		}
	}
	return *this;
}

MateriaSource::~MateriaSource() {
	putLogLevel("MateriaSource", LOG_LV_WIDTH);
	std::cerr << "Destructor called" << std::endl;
	for (int i = 0; i < _learnedNum; i++) {
		if (_learned[i])
			delete _learned[i];
	}
}

void MateriaSource::learnMateria(AMateria* m) {
	if (!m) return;
	for (int i = 0; i < _learnedNum; i++) {
		if (!_learned[i]) {
			_learned[i] = m;
			return;
		}
	}
}

AMateria* MateriaSource::createMateria(std::string const & type) {
	for (int i = 0; i < _learnedNum; i++) {
		if (_learned[i] && _learned[i]->getType() == type)
			return _learned[i]->clone();
	}
	return NULL;
}

