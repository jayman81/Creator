/*
 * itemClass.hpp
 *
 *  Created on: Mar 14, 2018
 *      Author: jurgen
 *
 *      Item Database:
 *      1. Weapon
 *      1.1.	One-Handed
 *      1.1.1.	Daggers
 *      1.1.2.	Fist Weapons
 *      1.1.3.	One-Handed Axes
 *      1.1.4.	One-Handed Maces
 *      1.1.5.	One-Handed Swords
 *      1.1.6.	Warglaives
 *      1.2. 	Two-Handed
 *      1.2.1.	Polearms
 *      1.2.2.	Staves
 *      1.2.3.	Two-Handed Axes
 *      1.2.4.	Two-Handed Maces
 *      1.2.5.	Two-Handed Swords
 *      1.3.	Ranged
 *      1.3.1	Bows
 *      1.3.2.	Crossbows
 *      1.3.3.	Guns
 *      1.3.4.	Wands
 *      1.4.	Other
 *      1.4.1.	Fishing Poles
 *      1.4.2.	Miscellaneous
 *
 *      2. Armor
 *		2.1.	Types
 *		2.1.1.	Cloth
 *		2.1.2.	Leather
 *		2.1.3.	Mail
 *		2.1.4.	Plate
 *		2.2.	Jewelry
 *		2.2.1.	Amulets
 *		2.2.2.	Rings
 *		2.2.3.	Trinkets
 *		2.3.	Other
 *		2.3.1.	Cloaks
 *		2.3.2.	Off-hand Frills
 *		2.3.3.	Shields
 *		2.3.4.	Shirts
 *		2.3.5.	Tabards
 *		2.3.6.	Cosmetic
 *		2.3.7.	Miscellaneous
 *      3. Containers
 *      3.1.	Bags
 *      3.2.	Cooking Bags
 *      3.3.	Enchanting Bags
 *      3.4.	Engineering Bags
 *      3.5.	Gem Bag
 *      3.6.	Herb Bag
 *      3.7.	Inscription Bag
 *      3.8.	Leatherworking Bag
 *      3.9.	Mining Bag
 *      3.10.	Soul Bag
 *      3.11.	Tackle Boxes
 *      4. Consumable
 *      4.1.	Bandages
 *      4.2.	Consumables
 *      4.3.	Elixirs
 *      4.4.	Flasks
 *      4.5.	Food & Drinks
 *      4.6.	Item Enhancements (Permanent)
 *      4.7.	Item Enhancements (Temporary)
 *      4.8.	Potions
 *      4.9.	Scrolls
 *      4.10.	Other
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
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
	} weapons_s;

	enum class ArmorTypes
		: uint8_t {
			CLOTH = 1, LEATHER, MAIL, PLATE
	};

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

	void setSubChoiceWpn(weapon value) {
		_subChoiceWpn = value;
	} //1hand or 2Hand...
	void setSubChoiceArmr(ArmorTypes value) {
		_subChoiceArmor = value;
	}
	void setSubChoiceJewl(Jewelry value) {
		_subChoiceJewl = value;
	}

	weapon getSubChoiceWpn() {
		return _subChoiceWpn;
	}
	ArmorTypes getSubChoiceArmr() {
		return _subChoiceArmor;
	}
	Jewelry getSubChoiceJewl() {
		return _subChoiceJewl;
	}

	void setItemStates(uint8_t item, int selection);

private:
	weapon _subChoiceWpn;
	ArmorTypes _subChoiceArmor;
	Jewelry _subChoiceJewl;

};

#endif /* ITEMCLASS_HPP_ */
