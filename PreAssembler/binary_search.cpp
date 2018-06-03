/*
- Pre-assembler for the X-Makina Project
- ECED3403 Assignment 1
- This is the source file for the pre-assembler's binary search function
- Finlay Miller B00675696
- 3 June 2018
*/

#include "binary_search.h"

int binary_search(vector<conversion> vect, string inst)
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

	for (start; start < end; start++)
	{
		vect[start].write(cout);
	};

	while (!found && start <= end)
	{
		middle = (start + end) / 2;
		/* instruction is at the middle of the table */
		if (vect[middle].getInstruction() == inst)
		{
			found = true;
			curr_pos = middle;
		}
		/*  instruction is in bottom half of table */
		else if (vect[middle].getInstruction() > inst) end = middle - 1;
		/* instruction is in upper half of table */
		else start = middle + 1;
	};

	if (!found)
	{
		return -1;
	}

	cout << "Match found at position %i of table.", curr_pos;

	return curr_pos;
}