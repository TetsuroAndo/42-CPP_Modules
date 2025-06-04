/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: teando <teando@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/31 15:20:05 by teando            #+#    #+#             */
/*   Updated: 2025/06/04 23:54:54 by teando           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include <iostream>

int main() {
    const size_t N = 4;
    Animal* zoo[N];
    for(size_t i=0;i<N;++i) zoo[i] = (i%2)? static_cast<Animal*>(new Dog) : static_cast<Animal*>(new Cat);
    for(size_t i=0;i<N;++i) zoo[i]->makeSound();
    for(size_t i=0;i<N;++i) delete zoo[i];

    Dog basic;
    {
        Dog tmp=basic; // deep copy テスト
    }
}
