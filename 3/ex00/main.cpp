/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: teando <teando@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/31 11:51:55 by teando            #+#    #+#             */
/*   Updated: 2025/05/31 15:09:10 by teando           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main(void) {
	ClapTrap claptrap("Claptrap");
	claptrap.attack("Target");
	claptrap.takeDamage(15);
	claptrap.beRepaired(3);
	return 0;
}