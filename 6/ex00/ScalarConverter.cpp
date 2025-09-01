/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: teando <teando@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/31 09:39:02 by teando            #+#    #+#             */
/*   Updated: 2025/09/01 14:09:47 by teando           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {}
ScalarConverter::ScalarConverter(const ScalarConverter& src) { (void)src; }
ScalarConverter& ScalarConverter::operator=(const ScalarConverter& rhs) { (void)rhs; return *this; }
ScalarConverter::~ScalarConverter() {}

namespace {
	std::string trim(const std::string& str) {
		const size_t first = str.find_first_not_of(" \t\n\r");
		if (std::string::npos == first) {
			return "";
		}
		const size_t last = str.find_last_not_of(" \t\n\r");
		return str.substr(first, (last - first + 1));
	}

	bool isNan(double d) { return d != d; }
	bool isInf(double d) { return d == std::numeric_limits<double>::infinity() || d == -std::numeric_limits<double>::infinity();}

	void printChar(double d) {
		std::cout << "char: ";
		if (isNan(d) || isInf(d) || d < 0 || d > 127) {
			std::cout << "impossible" << std::endl;
		} else if (!std::isprint(static_cast<int>(d))) {
			std::cout << "Non displayable" << std::endl;
		} else {
			std::cout << "'" << static_cast<char>(d) << "'" << std::endl;
		}
	}
	void printInt(double d) {
		std::cout << "int: ";
		if (isNan(d) || isInf(d) || d < std::numeric_limits<int>::min() || d > std::numeric_limits<int>::max()) {
			std::cout << "impossible" << std::endl;
		} else {
			std::cout << static_cast<int>(d) << std::endl;
		}
	}
	void printFloat(double d) {
		std::cout << "float: ";
		float f = static_cast<float>(d);

		if (isInf(f) && !isInf(d)) {
			std::cout << "impossible" << std::endl;
			return;
		}
		std::cout << f;
		if (!isNan(d) && !isInf(d) && f == static_cast<long>(f)) {
			std::cout << ".0";
		}
		std::cout << "f" << std::endl;
	}
	void printDouble(double d) {
		std::cout << "double: ";
		std::cout << d;
		if (!isNan(d) && !isInf(d) && d == static_cast<long>(d)) {
			std::cout << ".0";
		}
		std::cout << std::endl;
	}


	bool parseInput(const std::string& in, double& out) {
		std::string l = trim(in);
		if (l.empty()) return false;

		if (l == "-inff" || l == "-inf") {
			out = -std::numeric_limits<double>::infinity();
			return true;
		}
		if (l == "+inff" || l == "+inf") {
			out = std::numeric_limits<double>::infinity();
			return true;
		}
		if (l == "nanf" || l == "nan") {
			out = std::numeric_limits<double>::quiet_NaN();
			return true;
		}

		if (l.length() == 1 && !std::isdigit(l[0])) {
			out = static_cast<double>(l[0]);
			return true;
		}

		char* endptr = NULL;
		out = std::strtod(l.c_str(), &endptr);
		if (endptr == l.c_str()) return false;

		if (*endptr == '\0' || (*endptr == 'f' && *(endptr + 1) == '\0')) {
			return true;
		}
		return false;
	}

}

void ScalarConverter::convert(const std::string& in) {
	double d;
	if (parseInput(in, d)) {
		printChar(d);
		printInt(d);
		printFloat(d);
		printDouble(d);
	} else {
	std::cout
		<< "char: impossible\n"
		<< "int: impossible\n"
		<< "float: impossible\n"
		<< "double: impossible"
		<< std::endl;
	}
}
