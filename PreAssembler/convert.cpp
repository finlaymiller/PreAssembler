/*
- Pre-assembler for the X-Makina Project
- ECED3403 Assignment 1
- Sourcefile for the pre-assembler's convert function
- Finlay Miller B00675696
- 05 June 2018
*/

#include "convert.h"

using namespace std;

record convert(vector<string> v_rec, vector<conversion> conversion_table)
{
	/*
	Purpose:    Contains the logic flow for determining what each token of input string is
	Input:      The record currently being examined, the conversion table (as a vector)
	Output:     Record to be printed
	Process:	1.	For current token:
					a) Is first char ';'? If so, add all tokens to comment string and send to record
					b) If not, do binary search
						i. if match, add emulation and instruction to label
							1) if has args, add them
						ii. if no match, must be label
	*/

	record r;
	int bs_result = -1;
	unsigned int size = (int)v_rec.size();
	unsigned int h = 0;
	vector<string>::iterator i = v_rec.begin();
	string label, instruction, emulation, argumentL, argumentR, comment, unknown;
	unsigned int argType = 0;
	bool u_error = false;

	// Lasciate ogne speranza, voi ch'entrate

	while (v_rec.size() > 0)
	{
		if (v_rec.begin()[0] == ";")
		{
			comment = "	";
			// comment found
			for (unsigned int i = 0; i < v_rec.size(); i++)
			{
				comment = comment + " " + v_rec[i];
			} // i == v_rec.size()
			argType = 0;
			v_rec.clear();
		} // v_rec.begin()[0] != ";" --> token is not a comment
		else
		{
			bs_result = binary_search(conversion_table, v_rec[0]);

			if (bs_result >= 0)
			{
				// current token identified, and it requires arguments
				argType = conversion_table[bs_result].getArgType();

				if (r.getInstruction() == "")
				{
					instruction = (conversion_table[bs_result].getInstruction());
					emulation = (conversion_table[bs_result].getEmulation());
					v_rec.erase(v_rec.begin());
				}
				else
				{
					// If it already has an instruction and there's an
					// unidentified token pass it as an argument
					u_error = true;
					unknown = unknown + " " + v_rec[0];
					v_rec.erase(v_rec.begin());
				}

				if (v_rec.size() > 0)
				{
					switch (conversion_table[bs_result].getArgType())
					{
					case 0: break;
					case 1: argumentL = (v_rec[0]);
						argumentR = conversion_table[bs_result].getArgR();
						v_rec.erase(v_rec.begin());
						break;
					case 2:	argumentR = (v_rec[0]);
						argumentL = conversion_table[bs_result].getArgL();
						v_rec.erase(v_rec.begin());
						break;
					case 3:	argumentL = (v_rec[0]);
						argumentR = (v_rec[0]);
						v_rec.erase(v_rec.begin());
						break;
					}
				}
			} // bs_result <= 0	--> Match not found
			else
			{
				if (r.getLabel() != "")
				{
					label = (v_rec[0]);
					v_rec.erase(v_rec.begin());
				} // record already has label
				else
				{
					// If it already has a label and there's an
					// unidentified token pass it as an unknown
					u_error = true;
					unknown = unknown + " " + v_rec[0];
					v_rec.erase(v_rec.begin());
				}
			} // Match not found, must be a label
		}
	} // v_rec.size() <= 0 --> record vector is empty

	r = record(label, instruction, emulation, argType, argumentL, argumentR, comment, unknown);
	if (u_error)
	{
		error("u");
		r.write(cout);
	}
	v_rec.clear();
	return r;
}