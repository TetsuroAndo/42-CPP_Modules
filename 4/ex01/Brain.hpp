/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: teando <teando@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/15 16:21:40 by teando            #+#    #+#             */
/*   Updated: 2025/08/15 16:45:58 by teando           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <iostream>
#include "PutLogLv.h"

class Brain {
private:
	std::string ideas[100];
public:
	Brain();
	~Brain();

	const std::string &getIdeas(const int idx) const;
	void setIdea(const int idx, std::string idea);
};

#endif // BRAIN_HPP