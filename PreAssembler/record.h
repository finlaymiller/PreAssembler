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
	std::string argumentL;
	std::string argumentR;
	std::string comment;
public:
	std::string getLabel() { return label; }
	std::string getInstruction() { return instruction; }
	std::string getEmulation() { return emulation; }
	std::string getArgumentL() { return argumentL; }
	std::string getArgumentR() { return argumentR; }
	std::string getComment() { return comment; }
	void setLabel(std::string l) { this->label = l; }
	void setInstruction(std::string i) { this->instruction = i; }
	void setEmulation(std::string e) { this->emulation = e; }
	void setArgumentL(std::string l) { this->argumentL = l; }
	void setArgumentR(std::string r) { this->argumentR = r; }
	void setComment(std::string c) { this->comment = c; }
	void write(std::ostream& out) const;
};

#endif // !RECORD_H
