/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: teando <teando@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/31 09:39:02 by teando            #+#    #+#             */
/*   Updated: 2025/09/01 13:28:03 by teando           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {
	std::cout << "[ ScalarConverter: " << this << " ] Default constructor called" << std::endl;
}
ScalarConverter::ScalarConverter(const ScalarConverter& other) {
	std::cout << "[ ScalarConverter: " << this << " ] Copy constructor called" << std::endl;
	(void)other;
}
ScalarConverter& ScalarConverter::operator=(const ScalarConverter& other) {
	std::cout << "[ ScalarConverter: " << this << " ] Copy assignment constructor called" << std::endl;
	(void)other;
	return *this;
}
ScalarConverter::~ScalarConverter() {
	std::cout << "[ ScalarConverter: " << this << " ] Destructor called" << std::endl;
}

namespace {
	std::string strTrim(const std::string& s) {
		size_t start = 0;
		while (start < s.length() && std::isspace(s[start]))
			++start;
		size_t end = s.length();
		while (end > start && std::isspace(s[end - 1]))
			--end;
		return s.substr(start, end - start);
	}

	bool isNan(double d) { return d != d; }
	bool isInf(double d) { return d == std::numeric_limits<double>::infinity() || d == -std::numeric_limits<double>::infinity(); }

	void printChar(double d) {
		std::cout << "char: ";
		if (isNan(d) || isInf(d) || d < 0 || d > 127)
			std::cout << "impossible" << std::endl;
		else if (!std::isprint(static_cast<char>(d)))
			std::cout << "Non displayable" << std::endl;
		else
			std::cout << "'" << static_cast<char>(d) << "'" << std::endl;
	}
	void printInt(double d) {
		std::cout << "int: ";
		if (isNan(d) || isInf(d) || d < std::numeric_limits<int>::min() || d > std::numeric_limits<int>::max())
			std::cout << "impossible" << std::endl;
		else
			std::cout << static_cast<int>(d) << std::endl;
	}
	void printFloat(double d) {
		std::cout << "float: ";
		if (isNan(d))
			std::cout << "nanf" << std::endl;
		else if (isInf(d))
			std::cout << (d > 0 ? "+inff" : "-inff") << std::endl;
		else {
			float f = static_cast<float>(d);
			if (isInf(f) && !isInf(d))
				std::cout << "impossible" << std::endl;
			else {
				if (f - static_cast<long>(f) == 0)
					std::cout << std::fixed << std::setprecision(1) << f << "f" << std::endl;
				else
					std::cout << f << "f" << std::endl;
			}
		}
	}
	void printDouble(double d) {
		std::cout << "double: ";
		if (isNan(d))
			std::cout << "nan" << std::endl;
		else if (isInf(d))
			std::cout << (d > 0 ? "+inf" : "-inf") << std::endl;
		else {
			if (d == static_cast<long>(d))
				std::cout << std::fixed << std::setprecision(1) << d << std::endl;
			else
				std::cout << d << std::endl;
		}
	}
}

void ScalarConverter::convert(const std::string& in) {
	std::string l = strTrim(in);

	if (l == "-inff" || l == "-inf") {
		printChar(-std::numeric_limits<double>::infinity());
		printInt(-std::numeric_limits<double>::infinity());
		printFloat(-std::numeric_limits<double>::infinity());
		printDouble(-std::numeric_limits<double>::infinity());
		return;
	}
	if (l == "+inff" || l == "+inf") {
		printChar(std::numeric_limits<double>::infinity());
		printInt(std::numeric_limits<double>::infinity());
		printFloat(std::numeric_limits<double>::infinity());
		printDouble(std::numeric_limits<double>::infinity());
		return;
	}
	if (l == "nanf" || l == "nan") {
		printChar(std::numeric_limits<double>::quiet_NaN());
		printInt(std::numeric_limits<double>::quiet_NaN());
		printFloat(std::numeric_limits<double>::quiet_NaN());
		printDouble(std::numeric_limits<double>::quiet_NaN());
		return;
	}

	double d;
	bool validNum = false;
	
	if (l.length() == 1 && !std::isdigit(l[0])) {
		d = static_cast<double>(l[0]);
		validNum = true;
	} else {
		char* endptr = NULL;
		d = std::strtod(l.c_str(), &endptr);
		validNum = (
			endptr != l.c_str() &&
			(*endptr == '\0' || (*endptr == 'f' && *(endptr + 1) == '\0'))
		);
	}

	if (validNum) {
		printChar(d);
		printInt(d);
		printFloat(d);
		printDouble(d);
		return;
	}
	std::cout << "char: impossible\n";
	std::cout << "int: impossible\n";
	std::cout << "float: impossible\n";
	std::cout << "double: impossible" << std::endl;
}
