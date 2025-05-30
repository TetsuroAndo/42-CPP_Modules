/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: teando <teando@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 06:56:55 by teando            #+#    #+#             */
/*   Updated: 2025/05/30 17:11:03 by teando           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include <iostream>

int main() {
	Zombie* horde = zombieHorde(5, "Horde");
	for (int i = 0; i < 5; i++)
		horde[i].announce();
	delete[] horde;
	return 0;
}
