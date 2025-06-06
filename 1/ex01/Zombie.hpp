/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: teando <teando@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 06:54:23 by teando            #+#    #+#             */
/*   Updated: 2025/05/29 01:53:22 by teando           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <string>
# include <iostream>

class Zombie {
private:
	std::string _name;
public:
	Zombie();
	explicit Zombie(std::string name);
	~Zombie();
	void announce() const;
	void setName(const std::string &name);
};

Zombie* zombieHorde(int N, std::string name);

#endif // ZOMBIE_HPP
