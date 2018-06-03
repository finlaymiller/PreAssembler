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

conversion::conversion(string i, string e, bool a, string l, string r)
{
	instruction = i;
	emulation = e;
	hasArgs = a;
	argL = l;
	argR = r;
}

string conversion::getInstruction(void)
{
	return instruction;
}

string conversion::getEmulation(void)
{
	return emulation;
}

bool conversion::doesHaveArgs(void)
{
	return hasArgs;
}

string conversion::getArgL(void)
{
	return argL;
}

string conversion::getArgR(void)
{
	return argR;
}

void conversion::write(ostream& out) const
{
	out << instruction << " ";
	out << emulation << " ";
	out << hasArgs << " ";
	out << argL << " ";
	out << argR << "\n";

	return;
}

#endif // !CONVERSION_H
