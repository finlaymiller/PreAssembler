/*
- Pre-assembler for the X-Makina Project
- ECED3403 Assignment 1
- This is the source file for the pre-assembler's format record function
- Finlay Miller B00675696
- 3 June 2018
*/

#include "format_record.h"

vector<string> format_record(const char * p_rv)
{
	/*
	Purpose:    Uppercases and tokenizes raw record string
	Input:      Pointer to current raw record
	Output:     Vector of strings - formatted record
	*/

	string raw = p_rv;
	string uppercased;
	vector<string> result;
	unsigned int i;
	string comment;

	/* check to see if line is just a comment */
	if (raw[0] == ';')
	{
		result.push_back(raw);
		return result;
	}

	comment = raw.substr(raw.find(";"));

	/* uppercased */
	for (i = 0; i < raw.size(); i++)
	{
		if (raw[i] >= 'A' && raw[i] <= 'Z')
		{
			raw[i] -= ('Z' - 'z');
		}
	}

	/* tokenized */
	result = split(raw, "	 ");

	return result;
}