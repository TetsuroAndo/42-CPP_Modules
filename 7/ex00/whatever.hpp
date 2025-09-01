/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: teando <teando@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 18:33:20 by teando            #+#    #+#             */
/*   Updated: 2025/09/01 21:29:32 by teando           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

template <class T>
void swap(T &a, T &b) {
	T tmp = a;
	a = b;
	b = tmp;
}

template<class T> T
max(const T &a, const T &b) {
	return (a > b) ? a : b;
}

template<class T>
T min(const T &a, const T &b) {
	return (a < b) ? a : b;
}
