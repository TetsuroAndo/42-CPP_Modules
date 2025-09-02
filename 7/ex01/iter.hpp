/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: teando <teando@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 21:30:35 by teando            #+#    #+#             */
/*   Updated: 2025/09/02 23:33:53 by teando           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <cstddef>

template <typename T, typename F>
void iter(T *arr, size_t len, F f) {
	for (size_t i = 0; i < len; ++i) {
		f(arr[i]);
	}
}

template <typename T, typename F>
void iter(const T *arr, size_t len, F f) {
	for (size_t i = 0; i < len; ++i) {
		f(arr[i]);
	}
}
