/*
- Pre-assembler for the X-Makina Project
- ECED3403 Assignment 1
- Record class methods
- Finlay Miller B00675696
- 03 June 2018
*/

#include "record.h"

record::record(std::string b, std::string i, std::string e, unsigned int a, std::string l, std::string r, std::string c, std::string u)
{
	label = b;
	instruction = i;
	emulation = e;
	argType = a;
	argumentL = l;
	argumentR = r;
	comment = c;
	unknown = u;
}

void record::write(std::ostream& out) const
{
	/*
	Purpose:    Write method for record type
	Input:      output stream
	Output:     None
	*/
	out << "Label: " << label << std::endl;
	out << "Instruction: " << instruction << std::endl;
	out << "Emulation: " << emulation << std::endl;
	out << "ArgType: " << argType << std::endl;
	out << "ArgL: " << argumentL << std::endl;
	out << "ArgR: " << argumentR << std::endl;
	out << "Unknowns: " << unknown << std::endl;
	out << "Comment: " << comment << std::endl;
	out << std::endl;
}