/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: teando <teando@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/03 14:59:02 by teando            #+#    #+#             */
/*   Updated: 2025/09/03 15:09:07 by teando           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstdlib>
#include <iostream>
#include "Array.hpp"

#define MAX_VAL 750

int main() {
	// === 1. 基本的なテスト: int型 ===
	std::cout << "1. Basic Tests with <int>" << std::endl;

	// デフォルトコンストラクタ
	Array<int> empty_array;
	std::cout << "Size of default-constructed array: " << empty_array.size() << std::endl;

	// サイズ指定コンストラクタ
	unsigned int n = 5;
	Array<int> sized_array(n);
	std::cout << "Size of sized array: " << sized_array.size() << std::endl;
	std::cout << "Initial values (should be 0):" << std::endl;
	for (unsigned int i = 0; i < sized_array.size(); i++) {
		std::cout << "  arr[" << i << "] = " << sized_array[i] << std::endl;
	}

	// === 2. 書き込みと読み込みのテスト ===
	std::cout << "\n2. Writing and Reading Test" << std::endl;
	for (unsigned int i = 0; i < sized_array.size(); i++) {
		sized_array[i] = i * 10;
	}
	std::cout << "Values after writing:" << std::endl;
	for (unsigned int i = 0; i < sized_array.size(); i++) {
		std::cout << "  arr[" << i << "] = " << sized_array[i] << std::endl;
	}

	// === 3. コピーコンストラクタと代入演算子（ディープコピーの確認） ===
	std::cout << "\n3. Deep Copy Tests" << std::endl;

	// コピーコンストラクタのテスト
	std::cout << "[Copy Constructor]" << std::endl;
	Array<int> copied_array(sized_array);
	std::cout << "Original[0] = " << sized_array[0] << ", Copied[0] = " << copied_array[0] << std::endl;
	
	std::cout << "-> Modifying original array's first element to 999" << std::endl;
	sized_array[0] = 999; // 元の配列を変更

	std::cout << "Original[0] = " << sized_array[0] << std::endl;
	std::cout << "Copied[0] should remain unchanged: " << copied_array[0] << std::endl;

	// 代入演算子のテスト
	std::cout << "\n[Assignment Operator]" << std::endl;
	std::cout << "Assigning sized_array to assigned_array (which has different initial size)" << std::endl;
	Array<int> assigned_array;
	assigned_array = sized_array;
	std::cout << "Original[1] = " << sized_array[1] << ", Assigned[1] = " << assigned_array[1] << std::endl;
	
	std::cout << "-> Modifying original array's second element to 777" << std::endl;
	sized_array[1] = 777; // 元の配列を変更

	std::cout << "Original[1] = " << sized_array[1] << std::endl;
	std::cout << "Assigned[1] (should remain unchanged) = " << assigned_array[1] << std::endl;

	// size check after assignment
	std::cout << "Size of original array: " << sized_array.size() << std::endl;
	std::cout << "Size of assigned array (should be 5): " << assigned_array.size() << std::endl;

	// === 4. 範囲外アクセスの例外テスト ===
	std::cout << "\n4. Out-of-Bounds Exception Test" << std::endl;

	try {
		std::cout << "Trying to access sized_array[10] (size is 5)..." << std::endl;
		sized_array[10] = 123; // 範囲外アクセス
	} catch (const std::exception& e) {
		std::cout << "-> Caught expected exception: " << e.what() << std::endl;
	}

	try {
		std::cout << "Trying to access empty_array[0] (size is 0)..." << std::endl;
		empty_array[0] = 456; // 範囲外アクセス
	} catch (const std::exception& e) {
		std::cout << "-> Caught expected exception: " << e.what() << std::endl;
	}
	

	// === 5. テンプレートのテスト: std::string型 ===
	std::cout << "\n5. Template Test with <std::string>" << std::endl;
	
	Array<std::string> string_array(3);
	string_array[0] = "Hello";
	string_array[1] = "C++";
	string_array[2] = "World!";

	std::cout << "String array values:" << std::endl;
	for (unsigned int i = 0; i < string_array.size(); i++) {
		std::cout << "  " << string_array[i];
	}
	std::cout << std::endl;
	
	// const修飾された配列のテスト
	const Array<std::string> const_string_array(string_array);
	std::cout << "Const array value at index 1: " << const_string_array[1] << std::endl;

	std::cout << "All tests completed successfully!" << std::endl;
	return 0;
}

// #include <iostream>
// #include <Array.hpp>

// #define MAX_VAL 750
// int main(int, char**)
// {
// 	Array<int> numbers(MAX_VAL);
// 	int* mirror = new int[MAX_VAL];
// 	srand(time(NULL));
// 	for (int i = 0; i < MAX_VAL; i++)
// 	{
// 		const int value = rand();
// 		numbers[i] = value;
// 		mirror[i] = value;
// 	}
// 	//SCOPE
// 	{
// 		Array<int> tmp = numbers;
// 		Array<int> test(tmp);
// 	}

// 	for (int i = 0; i < MAX_VAL; i++)
// 	{
// 		if (mirror[i] != numbers[i])
// 		{
// 			std::cerr << "didn't save the same value!!" << std::endl;
// 			return 1;
// 		}
// 	}
// 	try
// 	{
// 		numbers[-2] = 0;
// 	}
// 	catch(const std::exception& e)
// 	{
// 		std::cerr << e.what() << '\n';
// 	}
// 	try
// 	{
// 		numbers[MAX_VAL] = 0;
// 	}
// 	catch(const std::exception& e)
// 	{
// 		std::cerr << e.what() << '\n';
// 	}

// 	for (int i = 0; i < MAX_VAL; i++)
// 	{
// 		numbers[i] = rand();
// 	}
// 	delete [] mirror;//
// 	return 0;
// }
