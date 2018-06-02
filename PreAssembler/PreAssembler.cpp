// PreAssembler.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "stdio.h"
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <locale>
#include <algorithm>

#define IFILE_PATH "A:/Documents/School/3rd Year/(3403) Computer Architecture/PreAssembler/input - easy.txt"
#define OFILE_PATH "A:/Documents/School/3rd Year/(3403) Computer Architecture/PreAssembler/output - easy.txt"
#define TABLE_SIZE 56

using namespace std;

class conversion
{
private:
	string instruction;
	string emulation;
	bool hasArgs;
	string argL;
	string argR;
public:
	conversion(string const & i, string const & e, bool const & a, string const & l, string const & r)
		: instruction(i), emulation(e), hasArgs(a), argL(l), argR(r) { }
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
	string argument;
	string comment;
public:
    record() { }
	string getLabel() { return label; }
	string getInstruction() { return instruction; }
	string getArgument() { return argument; }
	string getComment() { return comment; }
	void setLabel(string l) { this->label = l; }
	void setInstruction(string i) { this->instruction = i; }
    void setEmulation(string e) { this->emulation = e; }
	void setArgument(string a) { this->argument = a; }
	void setComment(string c) { this->comment = c; }
};

vector<string> get_input(string);
vector<string> format_record(char *);
int binary_search(conversion*, string);
void error(string);
conversion* generate_table();

int main()
{
	int current_record_index = 0;
    int size, bs_result, i = 0;
	char *p_tkn;
	vector<string> active_r;
    record final;
    
    conversion *conv_table =  generate_table();
    
	vector<string> record_vector_raw = get_input(IFILE_PATH);           /* input file is now stored as a vector of newline delimited strings */
    const char * p_recvec = record_vector_raw[current_record_index].data();  /* pointer to current record */
    
    //active_r = format_record(p_recvec);                                 /* tokenized, uppercased record */
    size = active_r.size();
    
    if (active_r[0][0] = ';')
    {
        final.setComment(active_r[i]);
        active_r.erase(active_r.begin());
        size = active_r.size();
    }
    else cout << "Attempted to add comment to line but one was already present.\n";
    if (size > 2)
    {
        /* if a comment has already been removed and the size of the vector is greater than two */
        /* then the record's first token must be a lable */
        final.setLabel(active_r[0]);
        active_r.erase(active_r.begin());
        size = active_r.size();
    }
    else
    {
        bs_result = binary_search(conv_table, active_r[0]);
        /* check to see if match was found */
        if (bs_result = -1)
        {
            /* match not found, must be label */
            final.setLabel(active_r[0]);
            active_r.erase(active_r.begin());
            size = active_r.size();
        }
        /* match found, has args */
        else if (conv_table[bs_result].doesHaveArgs())
        {
            if (size = 1)
            {
                error(conv_table[bs_result].getInstruction());
            }
            final.setInstruction(conv_table[bs_result].getInstruction());
            final.setEmulation(conv_table[bs_result].getEmulation());
            final.setArgument(active_r[1]);
        }
        /* match found but doesn't have args */
        else
        {
            if (size = 2)
            {
                error(conv_table[bs_result].getInstruction());
            }
            
            final.setInstruction(conv_table[bs_result].getInstruction());
            final.setEmulation(conv_table[bs_result].getEmulation());
        }
    }

	getchar();
	return 0;
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

vector<string> format_record(char * p_rv)
{
    /*
     Purpose:    Uppercases and tokenizes raw record string
     Input:      Pointer to current raw record
     Output:     Vector of strings - formatted record
     */
    
    string raw = p_rv;
    char uppercased[] = "";
    vector<string> result;
    char * p_tok;
    int i = 0;
    int j = 0;
    char c;
    char C;
    string comment;
    
    /* check to see if line is just a comment */
    if (raw[0] == ';')
    {
        result.push_back(raw);
        return result;
    }
    
    comment = raw.substr(raw.find(";"));
    
    
    /* uppercased */
	transform(raw.begin(), raw.end(), uppercased[0], ::toupper);
    
    /* tokenized */
    p_tok = strtok(uppercased, " ");
    while (p_tok != NULL)
    {
        result.push_back(p_tok);
        p_tok = strtok(uppercased, " ");
    }
    
    return result;
}

int binary_search(conversion table[], string inst)
{
    int start = 0,
        end = TABLE_SIZE - 1,
        middle,
        curr_pos = -1;
    bool found = false;

	for (start; start < end; start++) 
	{
		table[start].write(cout);
	};
    
    while (!found && start <= end)
    {
        middle = (start + end)/2;
        /* instruction is at the middle of the table */
        if (table[middle].getInstruction() == inst)
        {
            found = true;
            curr_pos = middle;
        }
        /*  instruction is in bottom half of table */
        else if ( table[middle].getInstruction() > inst) end = middle - 1;
        /* instruction is in upper half of table */
        else start = middle + 1;
	};
    
    if (!found)
    {
        return -1;
    }
    
    return curr_pos;
}
                          
void error(string instruction)
{
    cout << "Error found due to record for instruction " << instruction << "\n";
    return;
}

void conversion::write(ostream& out) const
{
	out << instruction << " ";
	out << emulation << " ";
	out << hasArgs << " ";
	out << argL << " ";
	out << argR << "\n";
}

conversion* generate_table() {

	/*
	Purpose:    Generates conversion table - array of conversions
	Input:      None
	Output:     Pointer to table
	*/

	conversion conversion_table[TABLE_SIZE] = 
	{
		{ "ADC", "ADDC ", true, "#0", NULL },
		{ "ADC.B", "ADDC.B ", true, "#0", NULL },
		{ "ADC.W", "ADDC.W ", true, "#0", NULL },
		{ "CALL", "BL ", true, NULL, NULL },
		{ "CLR", "MOV ", true, "#0", NULL },
		{ "CLR.B", "MOV.B ", true, "#0", NULL },
		{ "CLR.W", "MOV.W ", true, "#0", NULL },
		{ "CLRC", "BIC #1,R6 ", false, NULL, NULL },
		{ "CLRN", "BIC #4,R6 ", false, NULL, NULL },
		{ "CLRZ", "BIC #2,R6 ", false, NULL, NULL },
		{ "DADC", "DADD ", true, "#0", NULL },
		{ "DADC.B", "DADD.B ", true, "#0", NULL },
		{ "DADC.W", "DADD.W ", true, "#0", NULL },
		{ "DEC", "SUB ", true, "#1", NULL },
		{ "DEC.B", "SUB.B ", true, "#1", NULL },
		{ "DEC.W", "SUB.W ", true, "#1", NULL },
		{ "DECD", "SUB ", true, "#2", NULL },
		{ "DECD.B", "SUB.B ", true, "#2", NULL },
		{ "DEC.W", "SUB.W ", true, "#2", NULL },
		{ "INC", "ADD ", true, "#1", NULL },
		{ "INC.B", "ADD.B ", true, "#1", NULL },
		{ "INC.W", "ADD.W ", true, "#1", NULL },
		{ "INCD", "ADD ", true, "#2", NULL },
		{ "INCD.B", "ADD.B ", true, "#2", NULL },
		{ "INCD.W", "ADD.W ", true, "#2", NULL },
		{ "INV", "XOR ", true, "#-1", NULL },
		{ "INV.B", "XOR.B ", true, "#-1", NULL },
		{ "INV.W", "XOR.W ", true, "#-1", NULL },
		{ "JUMP", "MOV ", true, NULL, "R7" },
		{ "NOP", "MOV R6,R6", false, NULL, NULL },
		{ "PULL", "LD ", true, "R5+", NULL },
		{ "PUSH", "ST ", true, "-R5", NULL },
		{ "RET", "MOV R4,R7", false, NULL, NULL },
		{ "RLC", "ADDC ", true, NULL, NULL },
		{ "RLC.B", "ADDC.B ", true, NULL, NULL },
		{ "RLC.W", "ADDC.W ", true, NULL, NULL },
		{ "SBC", "SUBC ", true, "#0", NULL },
		{ "SBC.B", "SUBC.B ", true, "#0", NULL },
		{ "SBC.W", "SUBC.W ", true, "#0", NULL },
		{ "SETC", "BIS #1,R6", false, NULL, NULL },
		{ "SETN", "BIS #4,R6", false, NULL, NULL },
		{ "SETZ", "BIS #2,R6", false, NULL, NULL },
		{ "SLA", "ADD ", true, NULL, NULL },
		{ "SLA.B", "ADD.B ", true, NULL, NULL },
		{ "SLA.W", "ADD.W ", true, NULL, NULL },
		{ "SPL0", "MOVLZ #$0,R6", false, NULL, NULL },
		{ "SPL1", "MOVLZ #$20,R6", false, NULL, NULL },
		{ "SPL2", "MOVLZ #$40,R6", false, NULL, NULL },
		{ "SPL3", "MOVLZ #$60,R6", false, NULL, NULL },
		{ "SPL4", "MOVLZ #$80,R6", false, NULL, NULL },
		{ "SPL5", "MOVLZ #$A0,R6", false, NULL, NULL },
		{ "SPL6", "MOVLZ #$C0,R6", false, NULL, NULL },
		{ "SPL7", "MOVLZ #$E0,R6", false, NULL, NULL },
		{ "TST", "CMP ", true, "#0", NULL },
		{ "TST.B", "CMP.B ", true, "#0", NULL },
		{ "TST.W", "CMP.W ", true, "#0", NULL },
	};
	return conversion_table;
}
