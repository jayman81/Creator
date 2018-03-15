//============================================================================
// Name        : ItemCreator.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================


//#include <SFML/Graphics.hpp>
#include <iostream>
#include <iomanip>
#include <stdlib.h> // clearScreen

#include "main.hpp"
#include "Util.h"
#include "creatorClass.hpp"
#include "coutScreens.hpp"
#include "itemClass.hpp"

using namespace std;

int main() {
/*	sf::RenderWindow window(sf::VideoMode(640, 480), "Item Creator");
	sf::CircleShape shape(100.f);
	shape.setFillColor(sf::Color::Black);

	while (window.isOpen()) {
		sf::Event event;
		while (window.pollEvent(event)) {
			if (event.type == sf::Event::Closed)
				window.close();
		}
*/
		cCreator creator;

		while (creator.getRunning()) { // wenn getRunnung == False => Quit
			creator.run();
		}

		if (shutdown()) {
			cout << "done.  Bye" << endl;
		} else {
			cout << "error while shutting down!" << endl;
		}

/*
		window.clear();
		window.draw(shape);
		window.display();
	}
*/





		/*
		 * solange running == True ist wird
		 * 1: DB initialisieren
		 * 2: Menu anzeigen
		 * 2.1: waren auf Auswahl
		 * 2.2: wenn aus Wahl == 0, dann Quit
		 *
		 *
		 */

/*
		switch (creator.getChoice()) {
		case (cCreator::Choice::WEAPON):
			creator.setRunning(true);

			_retVal = item.createWeapon();
			if (_retVal == 0) { //_ret = createWeapon();
				cout << "Creating Item aborted!" << endl;
				printRetry();
				cin >> _selection;
				creator.setNext(_selection);
			} else {
				cout << "Creating Item successful!" << endl;
				printRetry();
				cin >> _selection;
				creator.setNext(_selection);
			}
			if (creator.getNext()) {
				creator.setRunning(true);
				creator.setNext(true);
			} else {
				creator.setRunning(false);
				creator.setNext(false);
			}
			break;
		case (cCreator::Choice::ARMOR):
			creator.setRunning(true);
			createArmor();
			break;
		case (cCreator::Choice::SHIELD):
			creator.setRunning(true);
			createShield();
			break;
		case (cCreator::Choice::POTION):
			creator.setRunning(true);
			createPotion();
			break;
		case (cCreator::Choice::OTHER):
			creator.setRunning(true);
			createOther();
			break;
		case (cCreator::Choice::BACK):
			creator.setRunning(false);
			break;
		default:
			cout << "wrong selection, try again!" << endl;

		}

	}
*/

	return 0;
}

bool shutdown() {
	cout << "exiting..." << endl;
	cout << "Closing File-Handler..." << endl;
	cout << "Closing DB-Handler..." << endl;
	return true;
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

void createArmor() {
	cout << "Armor selecetd" << endl;
}

void createShield() {
	cout << "Shield selecetd" << endl;
}

void createPotion() {
	cout << "Potion selecetd" << endl;
}

void createOther() {
	cout << "Other selecetd" << endl;
}
