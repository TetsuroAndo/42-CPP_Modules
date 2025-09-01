/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: teando <teando@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 14:59:29 by teando            #+#    #+#             */
/*   Updated: 2025/09/01 15:07:44 by teando           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Data.hpp"

Data::Data(const std::string& s) : s(s) {}

Data::Data(const Data& other) : s(other.s) {}

Data& Data::operator=(const Data& other) {
	if (this != &other) {
		s = other.s;
	}
	return *this;
}

Data::~Data() {}
