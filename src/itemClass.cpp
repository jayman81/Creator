/*
 * weaponClass.cpp
 *
 *  Created on: Mar 14, 2018
 *      Author: jurgen
 */





#include "itemClass.hpp"
#include "Util.h"
#include "coutScreens.hpp"
#include "fileIO.hpp"



uint8_t createWeapon() {

	int _numberOfLines = 0;
	uint16_t _dmg, _weight, _nameLength;
	uint8_t _type, _subType, _hands, _range, _fileChoice;
	float _speed;
	std::string _name, readBuf;
	std::stringstream _ss;
	std::ifstream fRHandler;
	std::ofstream fWHandler;

	printWeaponType();
	std::cin >> _type;
	std::cin.clear();
	fflush(stdin);

	switch (_type) {
	case 0:
		//printWeaponSubType();
		std::cin >> _subType;
		std::cin.clear();
		fflush(stdin);
		std::cout << "Hands: (0=1H, 1=2H)";
		break;
	case 1:
		std::cout << "SubType: (Bow(0), CrossBow(1), Throwing Knife(2))";
		std::cin >> _subType;
		std::cout << "2 handed!";
		_hands = 1;
		break;
	default:
		break;
	}

	std::cout << "Name: ";
	std::cin >> _name;
	std::cout << "Dmg: (0-65k)";
	std::cin >> _dmg;
	std::cout << "Weight: (0-65k)";
	std::cin >> _weight;
	std::cout << "Speed: (float xx.2)";
	std::cin >> _speed;

	std::cout << "Range: (0-254)";
	std::cin >> _range;

	std::cout << "Write to File? (1/0)";
	std::cin >> _fileChoice;
	if (_fileChoice == 0)
		return 0;
	fRHandler.open("weapons");
	while (getline(fRHandler, readBuf)) {
		++_numberOfLines;
	}
	fRHandler.close();
	std::cout << "Found " << _numberOfLines << " Weapons" << std::endl;

	_nameLength = _name.size();

	_numberOfLines++;
	_ss.str("");
	_ss << _numberOfLines << " " << ::util::uint8_to_hex(_type) << " "
			<< ::util::uint8_to_hex(_subType) << " "
			<< ::util::uint16_to_hex(_nameLength) << " "
			<< ::util::bytes_to_hex(_name) << " " << ::util::uint16_to_hex(_dmg)
			<< " " << ::util::uint16_to_hex(_weight) << " "
			<< ::util::uint8_to_hex(_speed) << " "
			<< ::util::uint8_to_hex(_hands) << " "
			<< ::util::uint8_to_hex(_range);

	fWHandler.open("weapons", std::ios_base::app);
	fWHandler << _ss.str();
	fWHandler.close();

	std::cout << _numberOfLines << " " << ::util::uint8_to_hex(_type) << " "
			<< ::util::uint8_to_hex(_subType) << " " << _name.size() << " "
			<< ::util::bytes_to_hex(_name) << " " << ::util::uint16_to_hex(_dmg)
			<< " " << ::util::uint16_to_hex(_weight) << " " << _speed << " "
			<< ::util::uint8_to_hex(_hands) << " "
			<< ::util::uint8_to_hex(_range) << std::endl;

	return 1;

}
