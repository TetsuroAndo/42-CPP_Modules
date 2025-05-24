/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: teando <teando@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/24 21:43:15 by teando            #+#    #+#             */
/*   Updated: 2025/05/24 21:45:51 by teando           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cctype>

int main(int ac, char **av) {
	if (ac == 1) {
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
		return 0;
	}

	for (int i = 1; i < ac; ++i) {
		for (char *p = av[i]; *p; ++p)
			std::cout << static_cast<char>(std::toupper(static_cast<unsigned char>(*p)));
		if (i + 1 < ac)
			std::cout << ' ';
	}
	std::cout << std::endl;
	return 0;
}
