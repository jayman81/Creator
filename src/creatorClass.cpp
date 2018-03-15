/*
 * creatorClass.cpp
 *
 *  Created on: Mar 13, 2018
 *      Author: jurgen
 */

#include <iostream>
#include "creatorClass.hpp"
#include "coutScreens.hpp"
#include "itemClass.hpp"

void cCreator::run() {
	try {
		switch (_state) {
		case INIT:
			_initDB();
			break;
		case MENU:
			_menu();
			break;
		case CREATE:
			_create();
			break;
		case CHOOSETYPE:
			_choosetype();
			break;
		case WRITE:
			// write to file
			break;
		case SUCCESS:
			// creating item and writing to file was ok
			// go back to main menu
			break;
		case QUIT:
			setRunning(false);
			break;
		case ERROR:
			// handle this, if something went wrong durring item creation
			break;
		default:
			std::cout << "Unexpected Creator State!" << std::endl;
		}
	} catch (const std::exception &e) {
		std::cout << "State Error caught: " << e.what() << std::endl;
		// set state to main menu
	}
}

void cCreator::_initDB() {
	// mit DB verbinden, wenn ok, dann weiter ansonsten abbruch
	_state = MENU;
}

void cCreator::_menu() {
	int selection;
	printMainMenu();
	std::cout << "Select: ";
	std::cin >> selection;

	switch (selection) {
	case 0:
		_state = QUIT;
		break;
	case 1:
		_state = CREATE;
		cCreator::setChoice(cCreator::Choice::WEAPON);
		break;
	case 2:
		_state = CREATE;
		cCreator::setChoice(cCreator::Choice::ARMOR);
		break;
	case 3:
		_state = CREATE;
		cCreator::setChoice(cCreator::Choice::JEWELR);
		break;
	case 4:
		_state = CREATE;
		cCreator::setChoice(cCreator::Choice::POTION);
		break;
	case 5:
		_state = CREATE;
		cCreator::setChoice(cCreator::Choice::OTHER);
		break;
	default:
		std::cout << "Undefined Selection!" << std::endl;
		_state = CREATE;
		break;
	}
}

void cCreator::_create() {
	int selection;
	switch (cCreator::getChoice()) {
	case cCreator::Choice::WEAPON:
		//cCreator::setChoice(cCreator::Choice::WEAPON);
		printWeaponType();
		break;
	case cCreator::Choice::ARMOR:
		//cCreator::setChoice(cCreator::Choice::ARMOR);
		printArmorType();
		break;
	case cCreator::Choice::JEWELR:
		//cCreator::setChoice(cCreator::Choice::JEWELR);
		std::cout << "WIP" << std::endl;
		_state = MENU; // only while WIP
		break;
	case cCreator::Choice::POTION:
		//cCreator::setChoice(cCreator::Choice::POTION);
		std::cout << "WIP" << std::endl;
		_state = MENU; // only while WIP
		break;
	case cCreator::Choice::OTHER:
		//cCreator::setChoice(cCreator::Choice::OTHER);
		std::cout << "WIP" << std::endl;
		_state = MENU; // only while WIP
		break;
	case cCreator::Choice::BACK:
		_state = MENU;
		break;
	}
	std::cout << "Select: ";
	std::cin >> selection;

	if (selection == 0) { // if going back
		_state = MENU;
	} else {
		_state = CHOOSETYPE;
	}
}

void cCreator::_choosetype() {
	int selection;
	switch (cCreator::getChoice()) { // Vorselectierung Obergruppe
	case cCreator::Choice::WEAPON:
		if (selection == 0) {
			_state = CREATE;
			break;
		} else if (selection == 1) {
			printWeaponOneHand();
			std::cout << "Select: ";
			std::cin >> selection;

			if (selection == 0) { // if going back
				_state = MENU;
			} else {
				cItem::setItemStates(cCreator::getChoice(), selection);

			}
		} else if (selection == 2) {
			printWeaponTwoHand();
			std::cout << "Select: ";
			std::cin >> selection;
		} else if (selection == 3) {
			printWeaponRanged();
			std::cout << "Select: ";
			std::cin >> selection;
		}
		break;
	case cCreator::Choice::ARMOR:
		std::cout << "Select: ";
		std::cin >> selection;
		if (selection == 0) {
			_state = CREATE;
		} else {

		}
		break;
	case cCreator::Choice::JEWELR:
		std::cout << "Select: ";
		std::cin >> selection;
		if (selection == 0) {
			_state = CREATE;
		} else {

		}
		break;
	case cCreator::Choice::POTION:
		std::cout << "Select: ";
		std::cin >> selection;
		if (selection == 0) {
			_state = CREATE;
		} else {

		}
		break;
	case cCreator::Choice::OTHER:
		std::cout << "Select: ";
		std::cin >> selection;
		if (selection == 0) {
			_state = CREATE;
		} else {

		}
		break;
	case cCreator::Choice::BACK:
		_state = MENU;
		break;
	}

	_state = WRITE;

}
