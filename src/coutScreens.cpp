/*
 * coutScreens.cpp
 *
 *  Created on: Mar 13, 2018
 *      Author: jurgen
 */

#include <iostream>
#include <stdlib.h> // clearScreen


void printMainMenu() {
	//system("cls");
	std::cout << "Item Creator" << std::endl;
	std::cout << std::endl;
	std::cout << "\t1 \tWeapon" << std::endl;
	std::cout << "\t2 \tArmor" << std::endl;
	std::cout << "\t3 \tShield" << std::endl;
	std::cout << "\t4 \tPotion" << std::endl;
	std::cout << "\t5 \tother" << std::endl;
	std::cout << "\t0 \tBack" << std::endl;
}


void printWeaponType() {
	std::cout << "Weapon Type" << std::endl;
	std::cout << std::endl;
	std::cout << "\t1 \tMelee" << std::endl;
	std::cout << "\t2 \tRange" << std::endl;
	std::cout << "\t3 \tMage" << std::endl;
	std::cout << "\t0 \tBack" << std::endl;

}

void printWeaponSubType() {
	std::cout << "Melee Weapon Type" << std::endl;
	std::cout << std::endl;
	std::cout << "\t1 \t1H-Sword" << std::endl;
	std::cout << "\t2 \t2H-Sword" << std::endl;
	std::cout << "\t3 \t1H-Axe" << std::endl;
	std::cout << "\t3 \t2H-Axe" << std::endl;
	std::cout << "\t3 \tKnife" << std::endl;
	std::cout << "\t3 \tStaff" << std::endl;
	std::cout << "\t0 \tBack" << std::endl;
}

