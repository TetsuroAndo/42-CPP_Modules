/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: teando <teando@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/03 05:07:50 by teando            #+#    #+#             */
/*   Updated: 2025/09/03 14:54:44 by teando           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

template <class T>
Array<T>::Array() : _arr(NULL), _size(0) {}

template <class T>
Array<T>::Array(unsigned int n) : _arr(new T[n]()), _size(n) {}

template <class T>
Array<T>::Array(Array const &other) {
	_arr = new T[other._size];
	_size = other._size;
	for (unsigned int i = 0; i < _size; i++) {
		_arr[i] = other._arr[i];
	}
}

template <class T>
Array<T> &Array<T>::operator=(Array const &other) {
	if (this != &other) {
		T* new_arr = new T[other._size];
		for (unsigned int i = 0; i < other._size; i++) {
			new_arr[i] = other._arr[i];
		}
		delete[] _arr;
		_arr = new_arr;
		_size = other._size;
	}
	return *this;
}

template <class T>
Array<T>::~Array() {
	delete[] _arr;
}

template <class T>
T &Array<T>::operator[](unsigned int i) {
	if (i >= _size) {
		throw std::out_of_range("Index out of range");
	}
	return _arr[i];
}

template <class T>
const T &Array<T>::operator[](unsigned int i) const {
	if (i >= _size) {
		throw std::out_of_range("Index out of range");
	}
	return _arr[i];
}

template <class T>
unsigned int Array<T>::size() const {
	return _size;
}
