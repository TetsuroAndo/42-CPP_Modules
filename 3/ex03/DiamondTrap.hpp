/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: teando <teando@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 21:45:00 by teando            #+#    #+#             */
/*   Updated: 2025/06/02 21:45:00 by teando           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DIAMONDTRAP_HPP
#define DIAMONDTRAP_HPP

#include "FragTrap.hpp"
#include "ScavTrap.hpp"

// 多重継承を使用して、FragTrapとScavTrapの両方から継承
class DiamondTrap : public FragTrap, public ScavTrap {
private:
    std::string _name; // ClapTrapと同じ名前の変数

public:
    DiamondTrap();
    DiamondTrap(std::string name);
    DiamondTrap(const DiamondTrap &other);
    DiamondTrap &operator=(const DiamondTrap &other);
    virtual ~DiamondTrap();

    void attack(const std::string &target);
    void whoAmI();
};

#endif // DIAMONDTRAP_HPP
