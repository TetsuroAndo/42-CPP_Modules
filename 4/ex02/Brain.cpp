/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: teando <teando@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/15 16:21:48 by teando            #+#    #+#             */
/*   Updated: 2025/08/15 17:14:25 by teando           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain() : ideas() {
	putLogLevel("Brain", LOG_LV_WIDTH);
	std::cerr << "Constructor called" << std::endl;
}

Brain::Brain(const Brain &other) {
	putLogLevel("Brain", LOG_LV_WIDTH);
	std::cerr << "Copy constructor called" << std::endl;
	for (int i = 0; i < 100; ++i) {
		ideas[i] = other.ideas[i];
	}
}

Brain &Brain::operator=(const Brain &other) {
	putLogLevel("Brain", LOG_LV_WIDTH);
	std::cerr << "Copy assignment operator called" << std::endl;
	if(this != &other) {
		for (int i = 0; i < 100; ++i) {
			ideas[i] = other.ideas[i];
		}
	}
	return *this;
}

Brain::~Brain() {
	putLogLevel("Brain", LOG_LV_WIDTH);
	std::cerr << "Destructor called" << std::endl;
}

const std::string &Brain::getIdea(const int idx) const {
	static const std::string emptyString = "";
	if (idx < 0 || idx >= 100) {
		putLogLevel("Brain", LOG_LV_WIDTH);
		std::cerr << "Index out of Bounds" << std::endl;
		return emptyString;
	}
	return ideas[idx];
}

void Brain::setIdea(const int idx, std::string idea) {
	putLogLevel("Brain", LOG_LV_WIDTH);
	if (idx < 0 || idx >= 100) {
		std::cerr << "Index out of Bounds" << std::endl;
		return;
	}
	ideas[idx] = idea;
	std::cerr << "Idea set at index " << idx << ": " << ideas[idx] << std::endl;
}
