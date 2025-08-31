/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: teando <teando@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/31 09:39:02 by teando            #+#    #+#             */
/*   Updated: 2025/08/31 20:54:12 by teando           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {
	std::cout << "[ ScalarConverter: " << this << " ] Default constructor called" << std::endl;
}
ScalarConverter::ScalarConverter(const ScalarConverter& other) {
	std::cout << "[ ScalarConverter: " << this << " ] Copy constructor called" << std::endl;
	(void)other;
}
ScalarConverter& ScalarConverter::operator=(const ScalarConverter& other) {
	std::cout << "[ ScalarConverter: " << this << " ] Copy assignment constructor called" << std::endl;
	(void)other;
	return *this;
}
ScalarConverter::~ScalarConverter() {
	std::cout << "[ ScalarConverter: " << this << " ] Destructor called" << std::endl;
}

namespace {

}

void ScalarConverter::convert(const std::string& literal) {

}
