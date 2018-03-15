/*
 * coutScreens.cpp
 *
 *  Created on: Mar 13, 2018
 *      Author: jurgen
 */

#include <iostream>
#include <stdlib.h> // clearScreen

#include "itemClass.hpp"

void printMainMenu() {
	//system("cls");
	std::cout << "Item Creator" << std::endl;
	std::cout << std::endl;
	std::cout << "\t1. Weapon" << std::endl;
	std::cout << "\t2. Armor" << std::endl;
	std::cout << "\t3. Jewelry" << std::endl;
	std::cout << "\t4. Potion" << std::endl;
	std::cout << "\t5. Other" << std::endl;
	std::cout << "\t0. Exit" << std::endl;
}

void printWeaponType() {
	std::cout << "Weapon Type" << std::endl;
	std::cout << std::endl;
	std::cout << "\t1. One-Handed" << std::endl;
	std::cout << "\t2. Two-Handed" << std::endl;
	std::cout << "\t3. Ranged" << std::endl;
	std::cout << "\t0. Back" << std::endl;
}

void printWeaponOneHand() {
	std::cout << "One-Handed Weapon Type" << std::endl;
	std::cout << std::endl;
	std::cout << "\t1. Sword" << std::endl;
	std::cout << "\t2. Mace" << std::endl;
	std::cout << "\t3. Axe" << std::endl;
	std::cout << "\t4. Dagger" << std::endl;
	std::cout << "\t5. Knife" << std::endl;
	std::cout << "\t6. Staff" << std::endl;
	std::cout << "\t0. Back" << std::endl;
}

void printWeaponTwoHand() {
	std::cout << "Two-Handed Weapon Type" << std::endl;
	std::cout << std::endl;
	std::cout << "\t1. Sword" << std::endl;
	std::cout << "\t2. Mace" << std::endl;
	std::cout << "\t3. Axe" << std::endl;
	std::cout << "\t4. Stave" << std::endl;
	std::cout << "\t5. Polearm" << std::endl;
	std::cout << "\t0. Back" << std::endl;
}

void printWeaponRanged() {
	std::cout << "Ranged Weapon Type" << std::endl;
	std::cout << std::endl;
	std::cout << "\t1. Bow" << std::endl;
	std::cout << "\t2. Crossbow" << std::endl;
	std::cout << "\t3. Gun" << std::endl;
	std::cout << "\t0. Back" << std::endl;
}

void printArmorType() {
	std::cout << "Armor Type" << std::endl;
	std::cout << std::endl;
	std::cout << "\t1. Cloth" << std::endl;
	std::cout << "\t2. Leather" << std::endl;
	std::cout << "\t3. Mail" << std::endl;
	std::cout << "\t4. Plate" << std::endl;
	std::cout << "\t0. Back" << std::endl;
}

void printArmorSlot() {
	std::cout << "Armor Slot" << std::endl;
	std::cout << std::endl;
	std::cout << "\t1. Chest" << std::endl;
	std::cout << "\t2. Feet" << std::endl;
	std::cout << "\t3. Hands" << std::endl;
	std::cout << "\t4. Head" << std::endl;
	std::cout << "\t5. Legs" << std::endl;
	std::cout << "\t6. Shoulders" << std::endl;
	std::cout << "\t7. Waist" << std::endl;
	std::cout << "\t8. Wrist" << std::endl;
	std::cout << "\t0. Back" << std::endl;
}

void printRetry() {
	std::cout << "Retry? 1 = Yes, 0 = No" << std::endl;
}

