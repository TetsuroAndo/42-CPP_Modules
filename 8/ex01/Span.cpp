/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: teando <teando@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/03 23:52:15 by teando            #+#    #+#             */
/*   Updated: 2025/09/04 00:03:00 by teando           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span() : _N(0), _vec() {}
Span::Span(unsigned int N) : _N(N), _vec() {}
Span::Span(const Span& other) : _N(other._N), _vec(other._vec) {}
Span& Span::operator=(const Span& other) {
	if (this != &other) {
		_N = other._N;
		_vec = other._vec;
	}
	return *this;
}
Span::~Span() {}

void Span::addNumber(int n) {
	
}

int Span::shortestSpan() const {
	
}

int Span::longestSpan() const {
	
}
