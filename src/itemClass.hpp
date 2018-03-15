/*
 * itemClass.hpp
 *
 *  Created on: Mar 14, 2018
 *      Author: jurgen
 */

#ifndef ITEMCLASS_HPP_
#define ITEMCLASS_HPP_

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include "creatorClass.hpp"

class cItem {
public:

	enum class oneHanded
		: uint8_t {
			SWORD = 1, MACE, AXE, DAGGER
	};

	enum class twoHanded
		: uint8_t {
			SWORD = 1, MACE, AXE, STAVE, POLEARM
	};

	enum class Range
		: uint8_t {
			BOW = 1, CROSSBOW, GUN, WAND
	};

	enum class weapon
		: uint8_t {
			ONEHANDED = 1, TWOHANDED, RANGED, BACK = 0
	};

	struct sWeapon {
	 oneHanded oneHand;
	 twoHanded twoHand;
	 Range ranged;
	 }weapons_s;

	/*enum class ArmorTypes : uint8_t {
	 CLOTH,
	 LEATHER,
	 MAIL,
	 PLATE
	 };*/

	enum class ArmorSlot
		: uint8_t {
			CHEST = 1, FEET, HANDS, HEAD, LEGS, SHOUDLER, WAIST, WRIST
	};

	enum class Jewelry
		: uint8_t {
			AMULET = 1, RING, TRINKET
	};

	enum class Other
		: uint8_t {
			CLOAK = 1, OFFHAND, SHIELD, SHIRT, TABARD
	};

	struct sArmor {
		ArmorSlot Cloth;
		ArmorSlot Leather;
		ArmorSlot Mail;
		ArmorSlot Plate;
	};

	uint8_t createWeapon();
	uint8_t createArmor();
	uint8_t createJewelery();
	uint8_t createOther();
	void setItemStates(uint8_t item, int selection);

private:

};

#endif /* ITEMCLASS_HPP_ */
