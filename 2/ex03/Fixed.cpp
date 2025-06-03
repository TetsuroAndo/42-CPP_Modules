/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: teando <teando@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 10:02:06 by teando            #+#    #+#             */
/*   Updated: 2025/06/03 16:10:02 by teando           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

// Constructor/Deconstructor
Fixed::Fixed() : _value(0) {
	std::cerr << "[ Fixed ] Default constructor called" << std::endl;
}

Fixed::Fixed(int v) : _value(v << _fractionalBits) {
	std::cerr << "[ Fixed ] Int constructor called" << std::endl;
}
Fixed::Fixed(float v) : _value(static_cast<int>(roundf(v * (1 << _fractionalBits)))) {
	std::cerr << "[ Fixed ] Float constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &other) : _value(other._value) {
	std::cerr << "[ Fixed ] Copy constructor called" << std::endl;
}

Fixed &Fixed::operator=(const Fixed &other) {
	std::cerr << "[ Fixed ] Copy assignment operator called" << std::endl;
	if (this != &other) {
		_value = other._value;
	}
	return *this;
}

Fixed::~Fixed() { std::cerr << "[ Fixed ] Destructor called" << std::endl; }

// Comparison operators
bool Fixed::operator>(const Fixed &rhs) const {
	return _value > rhs._value;
}

bool Fixed::operator<(const Fixed &rhs) const {
	return _value < rhs._value;
}

bool Fixed::operator>=(const Fixed &rhs) const {
	return _value >= rhs._value;
}

bool Fixed::operator<=(const Fixed &rhs) const {
	return _value <= rhs._value;
}

bool Fixed::operator==(const Fixed &rhs) const {
	return _value == rhs._value;
}

bool Fixed::operator!=(const Fixed &rhs) const {
	return _value != rhs._value;
}

// Arithmetic operators
Fixed Fixed::operator+(const Fixed &rhs) const {
	Fixed result;
	result.setRawBits(_value + rhs._value);
	return result;
}

Fixed Fixed::operator-(const Fixed &rhs) const {
	Fixed result;
	result.setRawBits(_value - rhs._value);
	return result;
}

Fixed Fixed::operator*(const Fixed &rhs) const {
	Fixed result;
	long long temp = static_cast<long long>(_value) * static_cast<long long>(rhs._value);
	result.setRawBits(static_cast<int>(temp >> _fractionalBits));
	return result;
}

Fixed Fixed::operator/(const Fixed &rhs) const {
	if (rhs._value == 0) {
		std::cerr << "Error: Division by zero" << std::endl;
		return Fixed();
	}
	Fixed result;
	long long temp = static_cast<long long>(_value) << _fractionalBits;
	result.setRawBits(static_cast<int>(temp / rhs._value));
	return result;
}

// Increment/decrement operators
Fixed &Fixed::operator++() {
	_value++;
	return *this;
}

Fixed Fixed::operator++(int) {
	Fixed old(*this);
	++(*this);
	return old;
}

Fixed &Fixed::operator--() {
	_value--;
	return *this;
}

Fixed Fixed::operator--(int) {
	Fixed old(*this);
	--(*this);
	return old;
}

// Static member functions
Fixed &Fixed::min(Fixed &a, Fixed &b) { return (a < b) ? a : b; }
const Fixed &Fixed::min(const Fixed &a, const Fixed &b) { return (a < b) ? a : b; }
Fixed &Fixed::max(Fixed &a, Fixed &b) { return (a > b) ? a : b; }
const Fixed &Fixed::max(const Fixed &a, const Fixed &b) { return (a > b) ? a : b; }

// Member functions
float Fixed::toFloat() const {
	return static_cast<float>(_value) / (1 << _fractionalBits);
}
int Fixed::toInt() const { return _value >> _fractionalBits; }
int Fixed::getRawBits() const { return _value; }
void Fixed::setRawBits(int const raw) { _value = raw; }

// Non-member functions
std::ostream &operator<<(std::ostream &os, const Fixed &fixed) {
	os << fixed.toFloat();
	return os;
}
