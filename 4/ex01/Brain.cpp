/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: teando <teando@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/15 16:21:48 by teando            #+#    #+#             */
/*   Updated: 2025/08/15 16:46:13 by teando           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain() : ideas() {
	putLogLevel("Brain", LOG_LV_WIDTH);
	std::cerr << "Constructor called" << std::endl;
}

Brain::~Brain() {
	putLogLevel("Brain", LOG_LV_WIDTH);
	std::cerr << "Destructor called" << std::endl;
}

const std::string &Brain::getIdeas(const int idx) const {
	if (idx < 0 || idx >= 100) {
		putLogLevel("Brain", LOG_LV_WIDTH);
		std::cerr << "Index out of Bounds" << std::endl;
		return;
	}
	return ideas[idx];
}

void Brain::setIdea(const int idx, std::string idea) {
	putLogLevel("Brain", LOG_LV_WIDTH);
	if (idx < 0 || idx >= 100) {
		std::cerr << "Index out of Bounds" << std::endl;
		return;
	}
	ideas[idx] = std::move(idea);
	std::cerr << "Idea set at index " << idx << ": " << ideas[idx] << std::endl;
}
