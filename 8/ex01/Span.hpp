/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: teando <teando@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/03 23:52:19 by teando            #+#    #+#             */
/*   Updated: 2025/09/04 00:02:58 by teando           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <vector>

class Span {
private:
	unsigned int _N;
	std::vector<int> _vec;

public:
	Span();
	Span(unsigned int N);
	Span(const Span& other);
	Span& operator=(const Span& other);
	~Span();
	
	void addNumber(int n);
	int shortestSpan() const;
	int longestSpan() const;
};

template <typename T>
void addNumber(T begin, T end) {
	for (T it = begin; it != end; ++it) {
		if (_vec.size() >= _N) {
			throw std::out_of_range("Span is full");
		}
		_vec.push_back(*it);
	}
}
