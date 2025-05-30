/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: teando <teando@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 10:02:08 by teando            #+#    #+#             */
/*   Updated: 2025/05/30 23:12:17 by teando           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

class Fixed {
private:
	int _value;
	static const int _fractionalBits = 8;
public:
	Fixed();
	Fixed(int v);
	Fixed(float v);
	Fixed(const Fixed &other);
	Fixed &operator=(const Fixed &other);
	~Fixed();

	float toFloat() const;
	int toInt() const;

	int getRawBits() const;
	void setRawBits(int const raw);
};

std::ostream &operator<<(std::ostream &os, const Fixed &Fixed);

#endif // FIXED_HPP
