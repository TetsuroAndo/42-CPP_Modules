/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: teando <teando@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 06:56:55 by teando            #+#    #+#             */
/*   Updated: 2025/05/30 19:10:41 by teando           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>


int main() {
	std::string string = "HI THIS IS BRAIN";
	std::string *stringPTR = &string;
	std::string &stringREF = string;

	// string = "hello1";
	// *stringPTR = "hello2";
	// stringREF = "hello3";

	std::cout << "Address of &string    : " << &string		<< '\n';
	std::cout << "Address of stringPTR  : " << stringPTR	<< '\n';
	std::cout << "Address of &stringREF : " << &stringREF	<< '\n';

	std::cout << "Value of string       : " << string 		<< '\n';
	std::cout << "Value of *stringPTR   : " << *stringPTR 	<< '\n';
	std::cout << "Value of stringREF    : " << stringREF	<< std::endl;
	return 0;
}
