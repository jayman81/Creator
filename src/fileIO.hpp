/*
 * fileIO.hpp
 *
 *  Created on: Mar 14, 2018
 *      Author: jurgen
 */

#ifndef FILEIO_HPP_
#define FILEIO_HPP_

#include <iostream>
#include <sstream>
#include <fstream>


void writeToFile (std::stringstream data);
std::stringstream readFromFile(std::string fileName);



#endif /* FILEIO_HPP_ */
