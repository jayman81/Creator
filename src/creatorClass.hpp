/*
 * creatorClass.hpp
 *
 *  Created on: Mar 13, 2018
 *      Author: jurgen
 */

#ifndef CREATORCLASS_HPP_
#define CREATORCLASS_HPP_

class cCreator {
public:
	//cCreator();

	enum  State {
		INIT,
		MENU,
		CREATE,
		WRITE,
		SUCCESS,
		QUIT,
		ERROR
	};

	enum class Choice : uint8_t {
		WEAPON = 1,
		ARMOR,
		SHIELD,
		POTION,
		OTHER,
		BACK = 0
	};

	void run();

	void setRunning(bool value){ _running = value;}
	void setChoice(Choice value) { _choice = value;	}
	void setSelectValue(char value) { _selectedValue = value;}

	bool getRunning() { return _running; }
	Choice getChoice() { return _choice; }
	char getSelectedValue() {  return _selectedValue;}



private:
	State _state{INIT};
	bool _running = false;
	Choice _choice;
	char _selectedValue;


	void _initDB();
	void _menu();
	void _create();


};






#endif /* CREATORCLASS_HPP_ */
