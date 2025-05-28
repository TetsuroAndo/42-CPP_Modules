/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: teando <teando@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 02:36:01 by teando            #+#    #+#             */
/*   Updated: 2025/05/29 02:45:49 by teando           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
#define WEAPON_HPP

#include <string>

class Weapon {
private:
	std::string _type;
public:
	explicit Weapon(std::string type);
	const std::string &getType() const;
	void			setType(const std::string type);
};

#endif // WEAPON_HPP
