/*
- Pre-assembler for the X-Makina Project
- ECED3403 Assignment 1
- Conversion class methods
- Finlay Miller B00675696
- 03 June 2018
*/

#include "conversion.h"

conversion::conversion(std::string i, std::string e, bool a, std::string l, std::string r)
{
	instruction = i;
	emulation = e;
	hasArgs = a;
	argL = l;
	argR = r;
}

void conversion::write(std::ostream& out) const
{
	/*
	Purpose:    Write method for conversion type
	Input:      output stream
	Output:     None
	*/

	out << instruction << " ";
	out << emulation << " ";
	out << hasArgs << " ";
	out << argL << " ";
	out << argR << "\n";
}