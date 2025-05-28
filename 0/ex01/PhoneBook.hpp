/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: teando <teando@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 06:58:37 by teando            #+#    #+#             */
/*   Updated: 2025/05/29 00:24:10 by teando           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include "Contact.hpp"

class PhoneBook {
private:
	Contact contacts[8];
	int     size;
	int     oldest;
public:
	PhoneBook();
	void    add();
	void    search() const;
};

#endif // PHONEBOOK_HPP