/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: teando <teando@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 02:37:50 by teando            #+#    #+#             */
/*   Updated: 2025/05/29 03:04:39 by teando           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
#define HUMANB_HPP

#include "Weapon.hpp"
#include <iostream>

class HumanB {
private:
	std::string _name;
	Weapon *_weapon;
public:
	explicit HumanB(std::string name);
	void setWeapon(Weapon &weapon);
	void attack() const;
};

#endif // HUMANB_HPP
