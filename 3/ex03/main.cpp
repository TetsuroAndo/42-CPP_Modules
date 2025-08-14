/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: teando <teando@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/31 11:51:55 by teando            #+#    #+#             */
/*   Updated: 2025/08/14 14:37:45 by teando           ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"

int main(void) {
std::cout << "--- 💎 DiamondTrap Construction 💎 ---\n" << std::endl;
	DiamondTrap diamond("HERO");

	std::cout << "\n--- 📝 Initial Status Check 📝 ---\n" << std::endl;
	// whoAmIで2つの名前を確認
	diamond.whoAmI();

	// 継承したステータスを確認
	// Hit Points: 100 (FragTrap)
	// Energy Points: 50 (ScavTrap)
	// Attack Damage: 30 (FragTrap)
	std::cout << "Initial HP: " << diamond.getHitPoints() << std::endl;      // (getHitPoints()のようなゲッターが必要)
	std::cout << "Initial EP: " << diamond.getEnergyPoints() << std::endl;  // (getEnergyPoints()のようなゲッターが必要)
	std::cout << "Initial AD: " << diamond.getAttackDamage() << std::endl;  // (getAttackDamage()のようなゲッターが必要)
	// ※ゲッターがない場合は、beRepaired(0)などでEP消費後の値から逆算して確認します。

	std::cout << "\n--- 💥 Testing Abilities 💥 ---\n" << std::endl;
	// ScavTrapのattack()が呼ばれるか確認
	diamond.attack("Villain");
	diamond.takeDamage(20);
	diamond.beRepaired(10);

	std::cout << std::endl;

	// ScavTrapとFragTrapから継承した固有能力を確認
	diamond.guardGate();
	diamond.highFivesGuys();

	std::cout << "\n--- 📜 Orthodox Canonical Form Test 📜 ---\n" << std::endl;
	DiamondTrap diamond_copy(diamond);
	std::cout << "--- Copied Diamond ---\n";
	diamond_copy.whoAmI();
	diamond_copy.attack("Another Villain");

	DiamondTrap diamond_assign("Dummy");
	diamond_assign = diamond;
	std::cout << "--- Assigned Diamond ---\n";
	diamond_assign.whoAmI();


	std::cout << "\n--- 💥 No Energy/HP Test 💥 ---\n" << std::endl;
	diamond.takeDamage(1000); // HPを0にする
	diamond.attack("Ghost"); // HPがないので失敗するはず
	diamond.beRepaired(10);  // 修復はできる

	std::cout << "\n--- 💣 Destruction 💣 ---\n" << std::endl;
	return 0;
}
