/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: teando <teando@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/03 15:27:11 by teando            #+#    #+#             */
/*   Updated: 2025/09/03 23:42:58 by teando           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <algorithm>
#include <exception>
#include <iostream>

template <typename T>
typename T::iterator easyfind(T &cont, int n) {
	typename T::iterator it = std::find(cont.begin(), cont.end(), n);
	if (it == cont.end()) {
		throw std::out_of_range("Value not found in cont");
	}
	return it;
}
