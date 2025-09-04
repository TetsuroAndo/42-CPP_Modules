/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: teando <teando@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/03 23:52:15 by teando            #+#    #+#             */
/*   Updated: 2025/09/04 17:51:53 by teando           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span() : _n(0), _vec() {}
Span::Span(unsigned int n) : _n(n), _vec() {}
Span::Span(const Span& other) : _n(other._n), _vec(other._vec) {}
Span& Span::operator=(const Span& other) {
	if (this != &other) {
		_n = other._n;
		_vec = other._vec;
	}
	return *this;
}
Span::~Span() {}

void Span::addNumber(int n) {
	if (_vec.size() >= _n) {
		throw std::out_of_range("Span is full. Cannot add more numbers.");
	}
	_vec.push_back(n);
}

unsigned int Span::shortestSpan() const {
	if (_vec.size() <= 1) {
		throw std::logic_error("Not enough numbers to find a span.");
	}

	std::vector<int> sortedNumbers = _vec;
	std::sort(sortedNumbers.begin(), sortedNumbers.end());

	unsigned int minSpan = std::numeric_limits<unsigned int>::max();

	for (size_t i = 1; i < sortedNumbers.size(); ++i) {
		unsigned int span = sortedNumbers[i] - sortedNumbers[i - 1];
		if (span < minSpan) {
			minSpan = span;
		}
	}
	return minSpan;
}

unsigned int Span::longestSpan() const {
	if (_vec.size() <= 1) {
		throw std::logic_error("Not enough numbers to find a span.");
	}

	std::vector<int>::const_iterator minIt = std::min_element(_vec.begin(), _vec.end());
	std::vector<int>::const_iterator maxIt = std::max_element(_vec.begin(), _vec.end());
	return (*maxIt - *minIt);
}
