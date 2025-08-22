/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: teando <teando@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/21 13:28:20 by teando            #+#    #+#             */
/*   Updated: 2025/08/23 06:16:49 by teando           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include "Character.hpp"

void print_header(const std::string& title) {
	std::cout << "\n\n--- " << title << " ---\n" << std::endl;
}

int main() {
	IMateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());

	ICharacter* me = new Character("me");

	AMateria* tmp;
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);

	ICharacter* bob = new Character("bob");

	me->use(0, *bob);
	me->use(1, *bob);

	delete bob;
	delete me;
	delete src;

	// ========================================================================
	// 2. インベントリ管理の厳密なテスト
	// ========================================================================
	print_header("2. Inventory Management Test");
	{
		ICharacter* cloud = new Character("Cloud");
		IMateriaSource* src = new MateriaSource();
		src->learnMateria(new Ice());
		src->learnMateria(new Cure());

		// インベントリを一杯にする
		std::cout << "--> Filling inventory..." << std::endl;
		cloud->equip(src->createMateria("ice"));
		cloud->equip(src->createMateria("cure"));
		cloud->equip(src->createMateria("ice"));
		cloud->equip(src->createMateria("cure"));

		// 満杯のインベントリにさらに追加しようとする
		std::cout << "\n--> Trying to equip to a full inventory..." << std::endl;
		AMateria* extra = src->createMateria("ice");
		cloud->equip(extra);
		delete extra; // equipされなかったので手動で解放

		// 不正なインデックスを使用・装備解除
		std::cout << "\n--> Using/Unequipping with invalid index..." << std::endl;
		ICharacter* target = new Character("Sephiroth");
		cloud->use(4, *target);   // 範囲外
		cloud->use(-1, *target);  // 範囲外
		cloud->unequip(10);       // 範囲外

		// マテリアを装備解除し、そのスロットが空になることを確認
		std::cout << "\n--> Unequipping Materia from slot 1..." << std::endl;
		AMateria* unequipped = NULL;
		// Characterクラスはインベントリのポインタを返さないので、
		// unequipのテストは「そのスロットが空になり、再度equipできるか」で確認する
		cloud->unequip(1);

		std::cout << "\n--> Using slot 1 after unequipping (should do nothing)..." << std::endl;
		cloud->use(1, *target);

		std::cout << "\n--> Equipping a new Materia to the empty slot 1..." << std::endl;
		cloud->equip(src->createMateria("ice"));
		std::cout << "\n--> Using the new Materia in slot 1..." << std::endl;
		cloud->use(1, *target);

		// unequipしたマテリアはdeleteされない -> 手動でdeleteする必要がある
		// このテストコードではunequipしたポインタを受け取れないので、
		// メモリリークチェッカーでの確認が主目的となる
		// (意図的にリークさせる場合は unequipped を delete しない)
		delete unequipped;

		delete target;
		delete cloud;
		delete src;
	}

	// ========================================================================
	// 3. MateriaSourceの厳密なテスト
	// ========================================================================
	print_header("3. MateriaSource Test");
	{
		IMateriaSource* src = new MateriaSource();
		std::cout << "--> Learning 4 Materias..." << std::endl;
		src->learnMateria(new Ice());
		src->learnMateria(new Cure());
		src->learnMateria(new Ice());
		src->learnMateria(new Cure());

		std::cout << "\n--> Trying to learn a 5th Materia..." << std::endl;
		AMateria* extraMateria = new Ice();
		src->learnMateria(extraMateria);
		delete extraMateria; // learnされなかったので手動で解放

		std::cout << "\n--> Creating an unknown Materia type 'fire'..." << std::endl;
		AMateria* unknown = src->createMateria("fire");
		if (unknown == NULL) {
			std::cout << "Correctly returned NULL for unknown type." << std::endl;
		}

		delete src;
	}

	// ========================================================================
	// 4. ディープコピーの厳密なテスト (Character & MateriaSource)
	// ========================================================================
	print_header("4. Deep Copy Test");
	{
		// --- Characterのディープコピーテスト ---
		std::cout << "--> Testing Character deep copy..." << std::endl;
		Character* tifa = new Character("Tifa");
		IMateriaSource* src = new MateriaSource();
		src->learnMateria(new Ice());

		tifa->equip(src->createMateria("ice"));

		std::cout << "\n--> Creating a copy of Character 'Tifa'..." << std::endl;
		Character* tifa_copy = new Character(*tifa);
		
		std::cout << "\n--> Original Tifa uses Materia:" << std::endl;
		ICharacter* enemy = new Character("Enemy");
		tifa->use(0, *enemy);
		
		std::cout << "\n--> Copied Tifa uses Materia (should be independent):" << std::endl;
		tifa_copy->use(0, *enemy);

		std::cout << "\n--> Unequipping Materia from original Tifa..." << std::endl;
		tifa->unequip(0);
		
		std::cout << "\n--> Copied Tifa uses Materia again (should still work):" << std::endl;
		tifa_copy->use(0, *enemy);

		delete tifa;       // 元のtifaを削除
		std::cout << "\n--> Original Tifa deleted." << std::endl;
		
		std::cout << "\n--> Copied Tifa uses Materia one last time (proving deep copy):" << std::endl;
		tifa_copy->use(0, *enemy); // コピーがまだ使えることを確認

		delete tifa_copy;
		delete enemy;
		delete src;

		// --- MateriaSourceのディープコピーテスト ---
		std::cout << "\n\n--> Testing MateriaSource deep copy..." << std::endl;
		MateriaSource* base_src = new MateriaSource();
		base_src->learnMateria(new Cure());
		MateriaSource* copy_src = new MateriaSource(*base_src);

		delete base_src; // 元のソースを削除
		std::cout << "\n--> Original MateriaSource deleted." << std::endl;

		// コピーしたソースからマテリアを生成できるか確認
		std::cout << "\n--> Creating Materia from copied source..." << std::endl;
		AMateria* created = copy_src->createMateria("cure");
		if (created) {
			std::cout << "Successfully created '" << created->getType() << "' from copied source." << std::endl;
			delete created;
		} else {
			std::cout << "Failed to create Materia from copied source." << std::endl;
		}
		delete copy_src;
	}

	// ========================================================================
	// 5. エッジケースのテスト
	// ========================================================================
	print_header("5. Edge Case Test");
	{
		ICharacter* me = new Character("me");
		IMateriaSource* src = new MateriaSource();
		src->learnMateria(new Cure());

		AMateria* m = src->createMateria("cure");
		me->equip(m);
		
		std::cout << "--> Using Materia on self..." << std::endl;
		me->use(0, *me);

		std::cout << "\n--> Equipping NULL..." << std::endl;
		me->equip(NULL);
		// 何も起こらないはず

		delete me;
		delete src;
	}

	return 0;
}
