/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PutLogLv.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: teando <teando@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/15 15:35:28 by teando            #+#    #+#             */
/*   Updated: 2025/08/15 15:45:47 by teando           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PutLogLv.h"

void putLogLevel(const std::string& text, int width) {
	int padding = width - text.length();
	int leftPadding = padding / 2;
	int rightPadding = padding - leftPadding;

	std::cerr << "["
			  << std::setw(leftPadding + text.length()) << std::right
			  << text
			  << std::setw(rightPadding) << ""
			  << "] ";
}
