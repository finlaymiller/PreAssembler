/*
- Pre-assembler for the X-Makina Project
- ECED3403 Assignment 1
- Headerfile for the pre-assembler's conversion class
- Finlay Miller B00675696
- 03 June 2018
*/

#ifndef CONVERSION_H
#define CONVERSION_H

#include "stdio.h"
#include <iostream>
#include <string>

class conversion
{
private:
	std::string instruction;
	std::string emulation;
	bool hasArgs;
	std::string argL;
	std::string argR;
public:
	conversion(std::string i, std::string e, bool a, std::string l, std::string r);
	std::string getInstruction() { return instruction; }
	std::string getEmulation() { return emulation; }
	bool doesHaveArgs() { return hasArgs; }
	std::string getArgL() { return argL; }
	std::string getArgR() { return argR; }
	void write(std::ostream& out) const;
};

#endif // !CONVERSION_H

