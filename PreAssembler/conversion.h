/*
- Pre-assembler for the X-Makina Project
- ECED3403 Assignment 1
- This is the header file for the pre-assembler's conversion class
- Finlay Miller B00675696
- 3 June 2018
*/

#ifndef CONVERSION_H
#define CONVERSION_H

#include "preassembler.h"

using namespace std;

class conversion
{
private:
	string instruction;
	string emulation;
	bool hasArgs;
	string argL;
	string argR;
public:
	conversion(string i, string e, bool a, string l, string r);
	string getInstruction(void);
	string getEmulation(void);
	bool doesHaveArgs(void);
	string getArgL(void);
	string getArgR(void);
	void write(ostream& out) const;
};

#endif // !CONVERSION_H
