/*
- Pre-assembler for the X-Makina Project
- ECED3403 Assignment 1
- This is the source file for the pre-assembler's function to convert records
- Finlay Miller B00675696
- 3 June 2018
*/

#include "convert.h"

record convert(vector<string> v_rec, vector<conversion> v_conv)
{
	/*
	Purpose:    Contains the logic flow for determining what each token of input string is
	Input:      The record currently being examined, the conversion table (as a vector)
	Output:     Record to be printed
	*/
	record r;
	int bs_result, i = 0;
	size_t sz = v_rec.size();


	if (v_rec[0][0] = ';')
	{
		cout << v_rec[0][0];
		cout << "\nLine found to be entirely comment.\n";
		r.setComment(v_rec[i]);
		v_rec.erase(v_rec.begin());
		sz = v_rec.size();
	}
	else cout << "Attempted to add comment to line but one was already present.\n";

	if (sz > 2)
	{
		/* if a comment has already been removed and the size of the vector is greater than two */
		/* then the record's first token must be a lable */
		r.setLabel(v_rec[0]);
		v_rec.erase(v_rec.begin());
		sz = v_rec.size();
	}
	else
	{
		bs_result = binary_search(v_conv, v_rec[0]);
		/* check to see if match was found */
		if (bs_result = -1)
		{
			/* match not found, must be label */
			r.setLabel(v_rec[0]);
			v_rec.erase(v_rec.begin());
			sz = v_rec.size();
		}
		/* match found, has args */
		else if (v_conv[bs_result].doesHaveArgs())
		{
			if (sz = 1)
			{
				error(v_conv[bs_result].getInstruction());
			}
			r.setInstruction(v_conv[bs_result].getInstruction());
			r.setEmulation(v_conv[bs_result].getEmulation());
			r.setArgument(v_rec[1]);
		}
		/* match found but doesn't have args */
		else
		{
			if (sz = 2)
			{
				error(v_conv[bs_result].getInstruction());
			}

			r.setInstruction(v_conv[bs_result].getInstruction());
			r.setEmulation(v_conv[bs_result].getEmulation());
		}
	}

	return r;
}