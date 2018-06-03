/*
- Pre-assembler for the X-Makina Project
- ECED3403 Assignment 1
- Record class methods
- Finlay Miller B00675696
- 03 June 2018
*/

#include "record.h"

void record::write(std::ostream& out) const
{
	/*
	Purpose:    Write method for record type
	Input:      output stream
	Output:     None
	*/
	out << "Label is: " << label << "\n";
	out << "Instruction is: " << instruction << "\n";
	out << "Emulation is: " << emulation << "\n";
	out << "Left argument is: " << argumentL << "\n";
	out << "Right argument is: " << argumentR << "\n";
	out << "Comment is: " << comment << "\n";
}