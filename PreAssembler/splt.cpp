/*
- Pre-assembler for the X-Makina Project
- ECED3403 Assignment 1
- This is the source file for the pre-assembler's string splitter function
- Finlay Miller B00675696
- 3 June 2018
*/

#include "split.h"

vector<string> split(const string& input, const string& delims)
{
	/*
	Purpose:    Splits string based on delimiters
	Input:      String to split, string of delimiters
	Output:     Vector of string tokens
	*/

	vector<string> tokens;
	size_t start = input.find_first_not_of(delims), end = 0;

	while ((end = input.find_first_of(delims, start)) != string::npos)
	{
		tokens.push_back(input.substr(start, end - start));
		start = input.find_first_not_of(delims, end);
	}
	if (start != string::npos)
		tokens.push_back(input.substr(start));

	return tokens;
}