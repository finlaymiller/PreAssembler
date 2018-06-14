/*
- Pre-assembler for the X-Makina Project
- ECED3403 Assignment 1
- Headerfile for the pre-assembler's record class
- Finlay Miller B00675696
- 03 June 2018
*/

#ifndef RECORD_H
#define RECORD_H

#include "stdio.h"
#include <iostream>
#include <string>

class record
{
private:
	std::string label;
	std::string instruction;
	std::string emulation;
	unsigned int argType;
	std::string argumentL;
	std::string argumentR;
	std::string comment;
	std::string unknown;
public:
	record() { }
	record(std::string b, std::string i, std::string e, unsigned int a, std::string l, std::string r, std::string c, std::string u);
	std::string getLabel() { return label; }
	std::string getInstruction() { return instruction; }
	std::string getEmulation() { return emulation; }
	unsigned int getArgType() { return argType; }
	std::string getArgumentL() { return argumentL; }
	std::string getArgumentR() { return argumentR; }
	std::string getComment() { return comment; }
	std::string getUnknown() { return unknown; }
	void setLabel(std::string l) { this->label = l; }
	void setInstruction(std::string i) { this->instruction = i; }
	void setEmulation(std::string e) { this->emulation = e; }
	void setArgType(unsigned int a) { this->argType = a; }
	void setArgumentL(std::string l) { this->argumentL = l; }
	void setArgumentR(std::string r) { this->argumentR = r; }
	void setComment(std::string c) { this->comment = c; }
	void setUnknown(std::string u) { this->unknown = u; }
	void write(std::ostream& out) const;
};

#endif // !RECORD_H
