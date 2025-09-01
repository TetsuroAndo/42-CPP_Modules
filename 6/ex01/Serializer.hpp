/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: teando <teando@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 14:23:03 by teando            #+#    #+#             */
/*   Updated: 2025/09/01 15:01:10 by teando           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include "Data.hpp"

#if defined(__x86_64__) || defined(_M_X64) || defined(__aarch64__)
typedef unsigned long uintptr_t; // 64bit
#else
typedef unsigned int uintptr_t;  // 32bit
#endif

class Serializer {
	Serializer();
	Serializer(const Serializer& other);
	Serializer& operator=(const Serializer& other);
	~Serializer();
public:
	static Data* deserialize(uintptr_t raw);
	static uintptr_t serialize(Data* ptr);
};
