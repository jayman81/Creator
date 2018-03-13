//============================================================================
// Name        : ItemCreator.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <vector>
#include <fstream>
#include <iomanip>
#include "Util.h"

using namespace std;

uint8_t createWeapon();
void createArmor();
void createShield();
void createPotion();
void createOther();

int main() {
	int choice, _ok, _ret;
	bool selected = false;

	while(!selected) {
		cout << "Item Creator" << endl; // prints !!!Hello World!!!
		cout << endl;
		cout << "\t1 \tWeapon" << endl;
		cout << "\t2 \tArmor" << endl;
		cout << "\t3 \tShield" << endl;
		cout << "\t4 \tPotion" << endl;
		cout << "\t5 \tother" << endl;
		cout << "\t0 \tExit" << endl;
		cout << endl;
		cout << "Select: ";
		cin >> choice;
		cin.clear();
		fflush(stdin);


		switch (choice) {
		case 1:
			selected = true;
			cout << "Weapon selecetd, ok(1/0)?" << endl;
			cin >> _ok;
			cin.clear();
			fflush(stdin);
			if (_ok == 1)
				_ret = createWeapon();
				if (_ret == 0) {
					cout << "Creating Item aborted! Again?" << endl;
					cin >> choice;
					cin.clear();
					fflush(stdin);
				} else {
					cout << "Creating Item successful! Again?" << endl;
					cin >> choice;
					cin.clear();
					fflush(stdin);
				}
				if (choice == 1) {
					selected = false;
				} else {
					selected = true;
				}


			break;
		case 2:
			selected = true;
			createArmor();
			break;
		case 3:
			selected = true;
			createShield();
			break;
		case 4:
			selected = true;
			createPotion();
			break;
		case 5:
			selected = true;
			createOther();
			break;
		case 0:
			cout << "Exiting" << endl;
			break;
		default:
			cout << "wrong selection, try again!" << endl;

		}

	}






	return 0;
}

/*
	uint16_t _id;
	uint8_t _type;
	uint8_t _subType;
	std::string _name;
	uint16_t _dmg;
	uint16_t _weight;
	float _speed;
	uint8_t _hands;
	uint8_t _ranged;
 *
 *SubType
-	sword1H = 0x00,
-	sword2H,
-	axe1H,
-	axe2H,
-	knife,
-	stick,
-	staff
-} meleeWeapon_t;
-
Type
-	melee = 0x00,
-	range,
-	wand,
-	mage
-}weaponType_t;
 */


uint8_t createWeapon(){

	int _numberOfLines=0;
	uint16_t _dmg, _weight, _nameLength;
	uint8_t _type, _subType, _hands, _range, _fileChoice ;
	float _speed;
	string _name, readBuf, _retVal;
	stringstream _ss;
	ifstream fRHandler;
	ofstream fWHandler;

	cout << "Type: (Melee(0), Ranged(1), Wand(2), Mage(3))";
	cin >> _type;

	switch (_type) {
	case '0':
		cout << "SubType: (1H-Sword(0), 2H-Sword(1), 1H-Axe(2), 2H-Axe(3), Knife(4), Stick(5))";
		cin >>  _subType;
		cout << "Hands: (0=1H, 1=2H)";
		cin >> _hands;
		break;
	case '1':
		cout << "SubType: (Bow(0), CrossBow(1), Throwing Knife(2))";
		cin >> _subType;
		cout << "2 handed!" << endl;
		_hands = '1';
		break;
	default:
		break;
	}

	cout << "Name: ";
	cin >> _name;
	cout << "Dmg: (0-65k)";
	cin >> _dmg;
	cout << "Weight: (0-65k)";
	cin >> _weight;
	cout << "Speed: (float xx.2)";
	cin >> _speed;
	cout << "Range: (0-254)";
	cin >> _range;
	cout << "Write to File? (1/0)";
	cin >> _fileChoice;
	if (_fileChoice == '0')
		return 0;
	fRHandler.open("weapons");
	if (fRHandler.fail()){
		cout << "Error while reading file!" << endl;
		EXIT_FAILURE;
	}

	while (getline(fRHandler,readBuf)) {
		++_numberOfLines;
	}
	fRHandler.close();
	cout << "Found " << _numberOfLines << " Weapons in File." << endl;



	_numberOfLines++;
	_retVal = (::util::string_to_hex(_name));
	_nameLength = _retVal.size();

	_ss.str("");
	_ss << std::hex <<_numberOfLines
		<< " "
		<< std::hex << _type
		<< " "
		<< std::hex << _subType
		<< " "
		<< std::hex << _nameLength
		<< " "
		<< _retVal
		<< " "
		<< std::hex << _dmg
		<< " "
		<< std::hex << _weight
		<< " "
		<< std::hex << _speed
		<< " "
		<< std::hex << _hands
		<< " "
		<< std::hex << _range;
	cout << "stringstream: " << _ss.str() << endl;

	fWHandler.open("weapons", ios::app);
	if(!fWHandler.is_open()) {
			cout << "Error while write to weapons-File!" << endl;
			EXIT_FAILURE;
	} else {
		cout << "File opend successfully! Writing...";
		fWHandler << _ss.str();
		fWHandler << "\n";
		fWHandler.close();
		cout << "Done" << endl;

	}


/*
 * 	cout << "Lines: " <<_numberOfLines << endl;
	cout << "Type: " << _type << endl;
	cout << "SubType:  " << _subType << endl;
	cout << "NameLength: " << _name.size() << endl;
	cout << "Name: " << _name << endl;
	cout << "Dmg: " << _dmg << endl;
	cout << "Weight: " << _weight << endl;
	cout << "Speed: " << _speed << endl;
	cout << "Hands: " << _hands << endl;
	cout << "Range: " << _range << endl;
*/

	return 1;

}

void createArmor(){
	cout << "Armor selecetd" << endl;
}


void createShield(){
	cout << "Shield selecetd" << endl;
}


void createPotion(){
	cout << "Potion selecetd" << endl;
}


void createOther(){
	cout << "Other selecetd" << endl;
}
