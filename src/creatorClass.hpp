/*
 * creatorClass.hpp
 *
 *  Created on: Mar 13, 2018
 *      Author: jurgen
 */

#ifndef CREATORCLASS_HPP_
#define CREATORCLASS_HPP_

#include "itemClass.hpp"

class cCreator {
public:
	//cCreator();

	enum  State {
		INIT = 1,
		MENU,
		CREATE,
		CHOOSETYPE,
		WRITE,
		SUCCESS,
		ERROR,
		QUIT = 0
	};

	enum class Choice : uint8_t {
		WEAPON = 1,
		ARMOR,
		JEWELR,
		POTION,
		OTHER,
		BACK = 0
	};

	void run();

	void setRunning(bool value){ _running = value;}
	void setNext(bool value){ _next = value;}
	void setChoice(Choice value) { _choice = value;	}
	void setSelectValue(char value) { _selectedValue = value;}

	bool getRunning() { return _running; }
	bool getNext() { return _next; }
	Choice getChoice() { return _choice; }
	char getSelectedValue() {  return _selectedValue;}



private:
	State _state{INIT};
	bool _running = true;  // is false, when program should exit
	bool _next = true; 		// is true if a second item should be created
	Choice _choice; 		// selechtion of item enum
	char _selectedValue;
	bool _writeFile = false; // is true, if writeToFile is ok

	void _initDB();
	void _menu();
	void _create();
	void _choosetype();

};






#endif /* CREATORCLASS_HPP_ */
