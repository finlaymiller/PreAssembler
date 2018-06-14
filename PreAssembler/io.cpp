/*
- Pre-assembler for the X-Makina Project
- ECED3403 Assignment 1
- Sourcefile for the pre-assembler's I/O functions
- Finlay Miller B00675696
- 05 June 2018
*/

#include "io.h"

std::vector<std::string> get_input(char* input_file)
{
	/*
	Purpose:    Reads records from input file
	Input:      Input file
	Output:     Vector of std::strings. One entry for each line in file
	*/

	std::ifstream ifile;
	ifile.open(input_file);
	std::string record;
	std::vector<std::string> rv;

	while (getline(ifile, record)) {
		rv.push_back(record);
	}

	ifile.close();
	return rv;
}

bool write_output(std::string filepath, std::vector<record> r)
{
	/*
	Purpose:    Writes record to output file
	Input:      Record
	Output:     Write status T|F
	*/

	std::ofstream ofile;
	ofile.open(filepath);

	if (ofile.is_open())
	{
		std::cout << "\nWriting " << r.size() << "  records to output file.";
		while (r.size() > 0)
		{
			//  file writes 
			ofile << r[0].getLabel();
			ofile << r[0].getEmulation();
			ofile << r[0].getArgumentL();
			ofile << r[0].getArgumentR();
			ofile << r[0].getUnknown();
			ofile << r[0].getComment();
			ofile << "\n";

			//  screen writes 
			/*std::cout << r[0].getLabel();
			std::cout << r[0].getEmulation();
			std::cout << r[0].getArgumentL();
			std::cout << r[0].getArgumentR();
			std::cout << r[0].getUnknown();
			std::cout << r[0].getComment();
			std::cout << "\n";*/

			r.erase(r.begin());
		}

		ofile.close();
		return true;
	}
	return false;
}

void error(std::string s)
{
	/*
	Purpose:    Writes errors to screen
	Input:      Instruction being examined at time of error
	Output:     None
	*/

	if (s == "write") std::cout << "\nError writing output to file.";
	if (s == "excess") std::cout << "\nExcess tokens detected ";
	if (s == "u") std::cout << "\nUnidentified tokens encountered during conversion of record:\n";
	
	else std::cout << "\nError encountered trying to convert instruction " << s;
	return;
}