/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: teando <teando@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/03 15:27:11 by teando            #+#    #+#             */
/*   Updated: 2025/09/03 23:39:34 by teando           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <algorithm>
#include <iostream>
#include <exception>

template <typename T>
typename T::iterator easyfind(T &cont, int n) {
	typename T::iterator it = std::find(cont.begin(), cont.end(), n);
	if (it == cont.end()) {
		throw std::out_of_range("Value not found in cont");
	}
	return it;
}

template <typename T>
typename T::const_iterator easyfind(const T &cont, int n) {
	typename T::const_iterator it = std::find(cont.begin(), cont.end(), n);
	if (it == cont.end()) {
		throw std::out_of_range("Value not found in cont");
	}
	return it;
}
