/*
 * creatorClass.cpp
 *
 *  Created on: Mar 13, 2018
 *      Author: jurgen
 */

#include <iostream>
#include "creatorClass.hpp"
#include "coutScreens.hpp"

void cCreator::run() {
	try {
		switch(_state) {
		case INIT:
			_initDB();
			break;
		case MENU:
			_menu();
			break;
		case CREATE:
			// do create item
			break;
		case WRITE:
			// write to file
			break;
		case SUCCESS:
			// creating item and writing to file was ok
			// go back to main menu
			break;
		case QUIT:
			// exiting
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
	std::cout << "bin im init" << std::endl;
	_state = MENU;
}

void cCreator::_menu() {
	std::cout << "bin im menu" << std::endl;
	int selection;
	printMainMenu();
	std::cout << "Select: ";
	std::cin >> selection;
	setChoice((Choice)selection);

	std::cin.clear();
	fflush(stdin);
	_state = CREATE;
}

void cCreator::_create() {
	std::cout << "bin im create" << std::endl;
	int selection;
	printMainMenu();
	std::cout << "Select: ";
	std::cin >> selection;
	setChoice((Choice)selection);

	std::cin.clear();
	fflush(stdin);
	_state = WRITE;
}
