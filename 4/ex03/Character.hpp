/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: teando <teando@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/22 17:26:52 by teando            #+#    #+#             */
/*   Updated: 2025/08/22 17:37:53 by teando           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "ICharacter.hpp"
#include "AMateria.hpp"

class Character : public ICharacter {
private:
	std::string _name;
	int _slots[4];
public:
	Character();
	Character(std::string name);
	Character(const Character &other);
	Character &operator=(const Character &other);
	~Character();

	std::string const & getName() const = 0;
	void equip(AMateria* m) = 0;
	void unequip(int idx) = 0;
	void use(int idx, ICharacter& target) = 0;
};
