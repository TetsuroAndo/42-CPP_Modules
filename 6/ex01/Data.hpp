/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: teando <teando@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 14:59:32 by teando            #+#    #+#             */
/*   Updated: 2025/09/01 15:07:38 by teando           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

struct Data
{
	std::string s;

	Data(const std::string& s = "42.42f");
	Data(const Data& other);
	Data& operator=(const Data& other);
	~Data();
};
