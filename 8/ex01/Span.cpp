/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: teando <teando@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/03 23:52:15 by teando            #+#    #+#             */
/*   Updated: 2025/09/04 00:57:59 by teando           ###   ########.fr       */
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

void Span::addNumber(int number) {
	if (_vec.size() >= _N) {
		throw std::out_of_range("Span is full. Cannot add more numbers.");
	}
	_vec.push_back(number);
}

int Span::shortestSpan() const {
	if (_vec.size() <= 1) {
		throw std::logic_error("Not enough numbers to find a span.");
	}

	// 元のコンテナを破壊しないようにコピーを作成
	std::vector<int> sorted = _vec;
	std::sort(sorted.begin(), sorted.end());

	long long minSpan = std::numeric_limits<long long>::max();

	// ソート済みのベクターで隣接する要素の差を比較
	for (size_t i = 1; i < sorted.size(); ++i) {
		long long diff = static_cast<long long>(sorted[i]) - sorted[i-1];
		if (diff < minSpan) {
			minSpan = diff;
		}
	}
	return static_cast<int>(minSpan);
}

int Span::longestSpan() const {
	if (_vec.size() <= 1) {
		throw std::logic_error("Not enough numbers to find a span.");
	}

	// std::minmax_element を使うと一度のスキャンで最小値と最大値を見つけられる
	std::pair<std::vector<int>::const_iterator, std::vector<int>::const_iterator> result;
	result = std::minmax_element(_vec.begin(), _vec.end());

	return (*result.second - *result.first);
}

template <typename I>
void addRange(I first, I last) {
	if (std::distance(first, last) + _vec.size() > _N) {
		throw std::out_of_range("Cannot add range: not enough capacity.");
	}
	// 指定されたイテレータ範囲の要素をコンテナの末尾に挿入
	_vec.insert(_vec.end(), first, last);
}
