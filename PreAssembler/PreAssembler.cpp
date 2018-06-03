// PreAssembler.cpp : Defines the entry point for the console application.
//

/* required libraries */
#include "stdafx.h"
#include "stdio.h"
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <locale>
#include <algorithm>
#include <iterator>

/* global definitions */
#define IFILE_PATH "A:/Documents/GitHub/PreAssembler/input test.txt"
#define OFILE_PATH "A:/Documents/GitHub/PreAssembler/output test.txt"
#define TABLE_SIZE 56

using namespace std;

/* class definitions*/
class conversion
{
private:
	string instruction;
	string emulation;
	bool hasArgs;
	string argL;
	string argR;
public:
	conversion(string i, string e, bool a, string l, string r)
	{
		instruction = i;
		emulation = e;
		hasArgs = a;
		argL = l;
		argR = r;
	}
	string getInstruction() { return instruction; }
	string getEmulation() { return emulation; }
	bool doesHaveArgs() { return hasArgs; }
	string getArgL() { return argL; }
	string getArgR() { return argR; }
	void write(ostream& out) const;
};

class record
{
private:
	string label;
	string instruction;
    string emulation;
	string argumentL;
	string argumentR;
	string comment;
public:
	string getLabel() { return label; }
	string getInstruction() { return instruction; }
	string getEmulation() { return emulation; }
	string getArgumentL() { return argumentL; }
	string getArgumentR() { return argumentR; }
	string getComment() { return comment; }
	void setLabel(string l) { this->label = l; }
	void setInstruction(string i) { this->instruction = i; }
    void setEmulation(string e) { this->emulation = e; }
	void setArgumentL(string l) { this->argumentL = l; }
	void setArgumentR(string r) { this->argumentR = r; }
	void setComment(string c) { this->comment = c; }
	void write(ostream& out) const;
};

/* function definitions */
vector<string> get_input(string);
vector<string> format_record(string);
int binary_search(vector<conversion>, string);
void error(string);
vector<conversion> generate_table(void);
vector<string> split(const string&, const string&);
record convert(vector<string>, vector<conversion>);
string uppercaser(string);
bool write_output(string, vector<record>);

int main(void)
{
	vector<string> active_r, record_vector_raw;
	vector<conversion> conversion_table = generate_table();
	vector<record> converted_records;
	record rec;
	const char * p_recvec;
	bool written = false;

	record_vector_raw = get_input(IFILE_PATH);
	size_t s = record_vector_raw.size();
	cout << "Input file has " << s << " lines.\n";

	for (unsigned int current_record_index = 0; current_record_index < s; current_record_index++)
	{
		cout << "Record #" << current_record_index + 1 << "\n";
		p_recvec = record_vector_raw[current_record_index].data();
		cout << "Raw data is : " << p_recvec << "\n";
		active_r = format_record(p_recvec);
		cout << "Formatted record is: \n";
		for (unsigned int i = 0; i < active_r.size(); i++) cout << active_r[i] << "	";
		cout << "\n";
		rec = convert(active_r, conversion_table);
		rec.write(cout);
		cout << "\n";
		converted_records.push_back(rec);
	}

	written = write_output(OFILE_PATH, converted_records);
	if (!written) error("write");

	getchar();
	return 0;
}

record convert(vector<string> v_rec, vector<conversion> v_conv)
{
	/*
	Purpose:    Contains the logic flow for determining what each token of input string is
	Input:      The record currently being examined, the conversion table (as a vector)
	Output:     Record to be printed
	*/

	record r;
	int bs_result = -1;
	string temp, cmt;
	__int64 j = 0, cmt_found = -1;

	/* Search record for comment */
	for (vector<string>::iterator i = v_rec.begin(); i != v_rec.end(); i++)
	{
		temp = *i;
		if (temp[0] == ';')
		{
			j = i - v_rec.begin();
			cmt_found = j;
			if (&i == 0) cout << "\nLine found to be entirely comment.\n";
			cout << "Comment Found \n";
			while (j != v_rec.size())
			{
				cmt += v_rec[j] + " ";
				j++;
			}
			r.setComment(cmt);
		}
	}
	if (cmt_found >= 0)
	{
		while (cmt_found < (signed) v_rec.size())
		{
			v_rec.pop_back();
		}
		cout << "Size after comment removal is : " << v_rec.size() << "\n";
	}

	if (v_rec.size() > 2)
	{
		/* if a comment has already been removed and the size of the vector is greater than two */
		/* then the record's first token must be a label */
		r.setLabel(v_rec[0]);
		v_rec.erase(v_rec.begin());
	}
	else
	{
		bs_result = binary_search(v_conv, v_rec[0]);

		/* check to see if match was found */
		if (bs_result == -1)
		{
			/* match not found, must be label or unidentified command */
			r.setLabel(v_rec[0]);
			v_rec.erase(v_rec.begin());
		}
		/* match found, has args */
		else if (v_conv[bs_result].doesHaveArgs())
		{
			/* if the instruction has arguments but there is only 1 token (the instruction) */
			if (v_rec.size() == 1) error(v_conv[bs_result].getInstruction());

			r.setInstruction(v_conv[bs_result].getInstruction());
			r.setEmulation(v_conv[bs_result].getEmulation());
			
			if (v_conv[bs_result].getArgL() != "N/A") r.setArgumentL(v_rec[1]);
			if (v_conv[bs_result].getArgR() != "N/A") r.setArgumentR(v_rec[1]);
		}
		/* match found but doesn't have args */
		else
		{
			if (v_rec.size() == 2)
			{
				error(v_conv[bs_result].getInstruction());
			}

			r.setInstruction(v_conv[bs_result].getInstruction());
			r.setEmulation(v_conv[bs_result].getEmulation());
		}
	}

	/* check to ensure that all tokens have been identified. */
	/* print them if not identified */
	if (v_rec.size() > 0 && bs_result == -1)
	{
		cout << "Record conversion ended with " << v_rec.size() << " tokens still in conversion vector.\n";
		/* reuse variables */
		j = 0;
		temp = "";
		while (j != v_rec.size())
		{
			temp += v_rec[j] + " ";
			v_rec.erase(v_rec.begin());
		}
		r.setArgumentL(temp);
	}

	return r;
}

vector<string> get_input(string filepath)
{
	/*
	Purpose:    Reads records from input file
	Input:      Input file
	Output:     Vector of strings. One entry for each line in file
	*/

	ifstream ifile(filepath);
	string record;
	vector<string> rv;

	while (getline(ifile, record)) {
		rv.push_back(record);
	}
	
	ifile.close();

	return rv;
}

bool write_output(string filepath, vector<record> r)
{
	/*
	Purpose:    Writes record to output file
	Input:      Record
	Output:     Write status T|F
	*/

	ofstream ofile(filepath);

	if (ofile.is_open())
	{
		cout << "Writing " << r.size() << "  records to output file.\n";
		while (r.size() > 0)
		{
			
			cout << r.size() << ' ';
			ofile << r[0].getLabel();
			ofile << r[0].getEmulation();
			ofile << r[0].getArgumentL();
			if (r[0].getArgumentL() != "") ofile << ",";
			ofile << r[0].getArgumentR();
			if (r[0].getComment() != "") ofile << "	";
			ofile << r[0].getComment();
			ofile << "\n";
			r.erase(r.begin());
		}


		ofile.close();
		return true;
	}
	return false;
}

vector<string> format_record(string raw)
{
    /*
     Purpose:    Tokenizes raw record string
     Input:      Pointer to current raw record
     Output:     Vector of strings - formatted record
     */
    
    vector<string> result;
    
    /* tokenized using spaces and tabs as delimiters*/
	result = split(raw, "	 ");
    
    return result;
}

int binary_search(vector<conversion> vect, string s)
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
	string inst = uppercaser(s);

	cout << "Searching conversion table...\n";
    
    while (!found && start <= end)
    {
        middle = (start + end)/2;
        /* instruction is at the middle of the table */
        if (vect[middle].getInstruction() == inst)
        {
            found = true;
            curr_pos = middle;
        }
        /*  instruction is in bottom half of table */
        else if ( vect[middle].getInstruction() > inst) end = middle - 1;
        /* instruction is in upper half of table */
        else start = middle + 1;
	};
    
    if (!found)
    {
        return -1;
    }

	cout << "Match found at position " << curr_pos <<" of table.\n";
    
    return curr_pos;
}
                          
void error(string s)
{
	/*
	Purpose:    Writes errors to screen
	Input:      Instruction being examined at time of error
	Output:     None
	*/

	if (s == "write") cout << "Error writing output to file.\n";
	else cout << "Error found due to record for instruction " << s << "\n";
    return;
}

string uppercaser(string s)
{
	for (unsigned int i = 0; i < s.size(); i++)
	{
		if ((s[i] > 96) && (s[i] < 123))
			s[i] = s[i] - 32;
	}

	return s;
}

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

void conversion::write(ostream& out) const
{
	/*
	Purpose:    Write method for conversion type
	Input:      output stream
	Output:     None
	*/

	out << instruction << " ";
	out << emulation << " ";
	out << hasArgs << " ";
	out << argL << " ";
	out << argR << "\n";
}

void record::write(ostream& out) const
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

vector<conversion> generate_table(void) 
{
	/*
	Purpose:    Generates conversion table - array of conversions
	Input:      None
	Output:     Pointer to table
	*/
	
	vector<conversion> v;

	conversion c_t[TABLE_SIZE] =
	{
		conversion( "ADC", "ADDC ", true, "#0", "N/A" ),
		conversion( "ADC.B", "ADDC.B ", true, "#0", "N/A" ),
		conversion( "ADC.W", "ADDC.W ", true, "#0", "N/A" ),
		conversion( "CALL", "BL ", true, "N/A", "N/A" ),
		conversion( "CLR", "MOV ", true, "#0", "N/A" ),
		conversion( "CLR.B", "MOV.B ", true, "#0", "N/A" ),
		conversion( "CLR.W", "MOV.W ", true, "#0", "N/A" ),
		conversion( "CLRC", "BIC #1,R6 ", false, "N/A", "N/A" ),
		conversion( "CLRN", "BIC #4,R6 ", false, "N/A", "N/A" ),
		conversion( "CLRZ", "BIC #2,R6 ", false, "N/A", "N/A" ),
		conversion( "DADC", "DADD ", true, "#0", "N/A" ),
		conversion( "DADC.B", "DADD.B ", true, "#0", "N/A" ),
		conversion( "DADC.W", "DADD.W ", true, "#0", "N/A" ),
		conversion( "DEC", "SUB ", true, "#1", "N/A" ),
		conversion( "DEC.B", "SUB.B ", true, "#1", "N/A" ),
		conversion( "DEC.W", "SUB.W ", true, "#1", "N/A" ),
		conversion( "DECD", "SUB ", true, "#2", "N/A" ),
		conversion( "DECD.B", "SUB.B ", true, "#2", "N/A" ),
		conversion( "DEC.W", "SUB.W ", true, "#2", "N/A" ),
		conversion( "INC", "ADD ", true, "#1", "N/A" ),
		conversion( "INC.B", "ADD.B ", true, "#1", "N/A" ),
		conversion( "INC.W", "ADD.W ", true, "#1", "N/A" ),
		conversion( "INCD", "ADD ", true, "#2", "N/A" ),
		conversion( "INCD.B", "ADD.B ", true, "#2", "N/A" ),
		conversion( "INCD.W", "ADD.W ", true, "#2", "N/A" ),
		conversion( "INV", "XOR ", true, "#-1", "N/A" ),
		conversion( "INV.B", "XOR.B ", true, "#-1", "N/A" ),
		conversion( "INV.W", "XOR.W ", true, "#-1", "N/A" ),
		conversion( "JUMP", "MOV ", true, "N/A", "R7" ),
		conversion( "NOP", "MOV R6,R6", false, "N/A", "N/A" ),
		conversion( "PULL", "LD ", true, "R5+", "N/A" ),
		conversion( "PUSH", "ST ", true, "-R5", "N/A" ),
		conversion( "RET", "MOV R4,R7", false, "N/A", "N/A" ),
		conversion( "RLC", "ADDC ", true, "N/A", "N/A" ),
		conversion( "RLC.B", "ADDC.B ", true, "N/A", "N/A" ),
		conversion( "RLC.W", "ADDC.W ", true, "N/A", "N/A" ),
		conversion( "SBC", "SUBC ", true, "#0", "N/A" ),
		conversion( "SBC.B", "SUBC.B ", true, "#0", "N/A" ),
		conversion( "SBC.W", "SUBC.W ", true, "#0", "N/A" ),
		conversion( "SETC", "BIS #1,R6", false, "N/A", "N/A" ),
		conversion( "SETN", "BIS #4,R6", false, "N/A", "N/A" ),
		conversion( "SETZ", "BIS #2,R6", false, "N/A", "N/A" ),
		conversion( "SLA", "ADD ", true, "N/A", "N/A" ),
		conversion( "SLA.B", "ADD.B ", true, "N/A", "N/A" ),
		conversion( "SLA.W", "ADD.W ", true, "N/A", "N/A" ),
		conversion( "SPL0", "MOVLZ #$0,R6", false, "N/A", "N/A" ),
		conversion( "SPL1", "MOVLZ #$20,R6", false, "N/A", "N/A" ),
		conversion( "SPL2", "MOVLZ #$40,R6", false, "N/A", "N/A" ),
		conversion( "SPL3", "MOVLZ #$60,R6", false, "N/A", "N/A" ),
		conversion( "SPL4", "MOVLZ #$80,R6", false, "N/A", "N/A" ),
		conversion( "SPL5", "MOVLZ #$A0,R6", false, "N/A", "N/A" ),
		conversion( "SPL6", "MOVLZ #$C0,R6", false, "N/A", "N/A" ),
		conversion( "SPL7", "MOVLZ #$E0,R6", false, "N/A", "N/A" ),
		conversion( "TST", "CMP ", true, "#0", "N/A" ),
		conversion( "TST.B", "CMP.B ", true, "#0", "N/A" ),
		conversion( "TST.W", "CMP.W ", true, "#0", "N/A" ),
	};

	for (unsigned int i = 0; i < TABLE_SIZE; i++) v.push_back(c_t[i]);

	return v;
}