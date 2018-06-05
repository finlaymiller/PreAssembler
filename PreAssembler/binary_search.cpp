/*
- Pre-assembler for the X-Makina Project
- ECED3403 Assignment 1
- Sourcefile for the pre-assembler's binary search function
- Finlay Miller B00675696
- 03 June 2018
*/

#include "binary_search.h"

int binary_search(std::vector<conversion> vect, std::string s)
{
	/*
	Purpose:    Binary search function
	Input:      Table of values to search, string to search for
	Output:     Integer location of item in table
	*/

	int start = 0,
		end = TABLE_SIZE - 1,
		middle,
		curr_pos = -1;
	bool found = false;
	std::string inst = uppercaser(s);

	while (!found && start <= end)
	{
		middle = (start + end) / 2;
		//instruction is at the middle of the table 
		if (vect[middle].getInstruction() == inst)
		{
			found = true;
			curr_pos = middle;
		}
		// instruction is in bottom half of table 
		else if (vect[middle].getInstruction() > inst) end = middle - 1;
		// instruction is in upper half of table
		else start = middle + 1;
	};

	if (!found)
	{
		return -1;
	}

	return curr_pos;
}