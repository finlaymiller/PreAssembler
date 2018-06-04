/*
- Pre-assembler for the X-Makina Project
- ECED3403 Assignment 1
- Formatting tools
- Finlay Miller B00675696
- 03 June 2018
*/

#include "formatting.h"

std::string uppercaser(std::string s)
{
	/*
	Purpose:    Converts string to uppercase
	Input:      String to convert
	Output:     Converted string
	*/
	for (unsigned int i = 0; i < s.size(); i++)
	{
		if ((s[i] > 96) && (s[i] < 123))
			s[i] = s[i] - 32;
	}

	return s;
}

std::vector<std::string> split(const std::string& input, const std::string& delims)
{
	/*
	Purpose:    Splits string based on delimiters
	Input:      String to split, string of delimiters
	Output:     Vector of string tokens
	*/

	std::vector<std::string> tokens;
	size_t start = input.find_first_not_of(delims), end = 0;

	while ((end = input.find_first_of(delims, start)) != std::string::npos)
	{
		tokens.push_back(input.substr(start, end - start));
		start = input.find_first_not_of(delims, end);
	}
	if (start != std::string::npos)
		tokens.push_back(input.substr(start));

	return tokens;
}


std::vector<std::string> format_record(std::string raw)
{
	/*
	Purpose:    Formats input record. Started out as a bigger function
				but now not much is left due to refactoring and changes
				that I made to program flow.
	Input:      Pointer to current raw record
	Output:     Vector of strings - formatted record
	*/

	std::vector<std::string> result;

	/* tokenized using spaces and tabs as delimiters*/
	result = split(raw, "	 ");

	return result;
}