/*
- Pre-assembler for the X-Makina Project
- ECED3403 Assignment 1
- This is the source file for the pre-assembler's record class
- Finlay Miller B00675696
- 3 June 2018
*/

#include "record.h"

string record::getLabel() 
{ 
	return label; 
}

string record::getInstruction() 
{ 
	return instruction; 
}

string record::getArgument() 
{ 
	return argument; 
}

string record::getComment() 
{ 
	return comment; 
}

void record::setLabel(string l) 
{ 
	this->label = l; 
}

void record::setInstruction(string i) 
{ 
	this->instruction = i; 
}

void record::setEmulation(string e) 
{
	this->emulation = e; 
}

void record::setArgument(string a) 
{ 
	this->argument = a; 
}

void record::setComment(string c) 
{ 
	this->comment = c; 
}

void record::write(ostream& out) const
{
	out << "Label is: " << label << "\n";
	out << "Instruction is: " << instruction << "\n";
	out << "Emulation is: " << emulation << "\n";
	out << "Argument is: " << argument << "\n";
	out << "Comment is: " << comment << "\n";
}