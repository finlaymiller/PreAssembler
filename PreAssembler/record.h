/*
- Pre-assembler for the X-Makina Project
- ECED3403 Assignment 1
- This is the header file for the pre-assembler's record class
- Finlay Miller B00675696
- 3 June 2018
*/

#ifndef RECORD_H
#define RECORD_H

#include "preassembler.h"

using namespace std;

class record
{
private:
	string label;
	string instruction;
	string emulation;
	string argument;
	string comment;
public:
	string getLabel();
	string getInstruction();
	string getArgument();
	string getComment();
	void setLabel(string l);
	void setInstruction(string i);
	void setEmulation(string e);
	void setArgument(string a);
	void setComment(string c);
	void write(ostream& out) const;
};

#endif // !RECORD_H
