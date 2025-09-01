/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: teando <teando@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 14:23:03 by teando            #+#    #+#             */
/*   Updated: 2025/09/01 15:39:07 by teando           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include "Data.hpp"

#if defined(__x86_64__) || defined(_M_X64)			/* x86-64 */ \
 || defined(__aarch64__) || defined(_M_ARM64)		/* ARM64  */ \
 || defined(__ppc64__) || defined(__powerpc64__)	/* PowerPC64 */ \
 || defined(__ia64__)								/* Itanium */ \
 || defined(__sparc64__)							/* SPARC64 */ \
 || defined(__LP64__)								/* LLP64 Data Model */ \
 || defined(_WIN64)									/* Windows LLP64 */
typedef unsigned long uintptr_t;
#else
typedef unsigned int uintptr_t;
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
