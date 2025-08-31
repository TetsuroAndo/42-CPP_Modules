/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: teando <teando@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/31 09:41:17 by teando            #+#    #+#             */
/*   Updated: 2025/08/31 20:52:14 by teando           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

int main (int ac, char **av) {
	if (ac != 2) {
		std::cerr << "Usage: " << av[0] << " <literal>" << std::endl;
		return 1;
	}
	ScalarConverter::convert(av[1]);
	return 0;
}
