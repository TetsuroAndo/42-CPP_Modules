/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: teando <teando@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/03 23:52:19 by teando            #+#    #+#             */
/*   Updated: 2025/09/04 04:56:35 by teando           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <vector>
#include <algorithm>
#include <exception>
#include <limits>

class Span {
private:
	unsigned int _n;
	std::vector<int> _vec;

public:
	Span();
	Span(unsigned int n);
	Span(const Span& other);
	Span& operator=(const Span& other);
	~Span();

	void addNumber(int n);
	unsigned int shortestSpan() const;
	unsigned int longestSpan() const;

	template <typename I>
	void addRange(I begin, I end) {
		if (static_cast<unsigned int>(std::distance(begin, end)) + _vec.size() > _n) {
			throw std::out_of_range("Cannot add range: not enough capacity.");
		}
		// 指定されたイテレータ範囲の要素をコンテナの末尾に挿入
		_vec.insert(_vec.end(), begin, end);
	}
};
