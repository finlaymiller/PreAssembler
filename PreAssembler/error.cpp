/*
- Pre-assembler for the X-Makina Project
- ECED3403 Assignment 1
- This is the source file for the pre-assembler's very basic error handler
- Finlay Miller B00675696
- 3 June 2018
*/

#include "error.h"

void error(string instruction)
{
	/*
	Purpose:    Writes errors to screen
	Input:      Instruction being examined at time of error
	Output:     None
	*/

	if (instruction == "write") cout << "Error writing to file!\n";
	cout << "Error found due to record for instruction " << instruction << "\n";
	return;
}