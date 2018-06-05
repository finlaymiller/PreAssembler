/*
- Pre-assembler for the X-Makina Project
- ECED3403 Assignment 1
- Conversion class methods
- Finlay Miller B00675696
- 03 June 2018
*/

#include "conversion.h"

conversion::conversion(std::string i, std::string e, unsigned int a, std::string l, std::string r)
{
	instruction = i;
	emulation = e;
	argType = a;
	argL = l;
	argR = r;
}

void conversion::write(std::ostream& out) const
{
	/*
	Purpose:    Write method for conversion type
	Input:      output stream
	Output:     None
	*/

	out << instruction << " ";
	out << emulation << " ";
	out << argType << " ";
	out << argL << " ";
	out << argR << "\n";
}

std::vector<conversion> generate_table(void)
{
	/*
	Purpose:    Generates conversion table - array of conversions
	Input:      None
	Output:     Pointer to table
	*/

	std::vector<conversion> v;

	conversion c_t[TABLE_SIZE] =
	{
		conversion("ADC", "ADDC ", 2, "#0", "N/A"),
		conversion("ADC.B", "ADDC.B ", 2, "#0", "N/A"),
		conversion("ADC.W", "ADDC.W ", 2, "#0", "N/A"),
		conversion("CALL", "BL ", 2, "N/A", "N/A"),
		conversion("CLR", "MOV ", 2, "#0", "N/A"),
		conversion("CLR.B", "MOV.B ", 2, "#0", "N/A"),
		conversion("CLR.W", "MOV.W ", 2, "#0", "N/A"),
		conversion("CLRC", "BIC #1,R6 ", 0, "N/A", "N/A"),
		conversion("CLRN", "BIC #4,R6 ", 0, "N/A", "N/A"),
		conversion("CLRZ", "BIC #2,R6 ", 0, "N/A", "N/A"),
		conversion("DADC", "DADD ", 2, "#0", "N/A"),
		conversion("DADC.B", "DADD.B ", 2, "#0", "N/A"),
		conversion("DADC.W", "DADD.W ", 2, "#0", "N/A"),
		conversion("DEC", "SUB ", 2, "#1", "N/A"),
		conversion("DEC.B", "SUB.B ", 2, "#1", "N/A"),
		conversion("DEC.W", "SUB.W ", 2, "#1", "N/A"),
		conversion("DECD", "SUB ", 2, "#2", "N/A"),
		conversion("DECD.B", "SUB.B ", 2, "#2", "N/A"),
		conversion("DEC.W", "SUB.W ", 2, "#2", "N/A"),
		conversion("INC", "ADD ", 2, "#1", "N/A"),
		conversion("INC.B", "ADD.B ", 2, "#1", "N/A"),
		conversion("INC.W", "ADD.W ", 2, "#1", "N/A"),
		conversion("INCD", "ADD ", 2, "#2", "N/A"),
		conversion("INCD.B", "ADD.B ", 2, "#2", "N/A"),
		conversion("INCD.W", "ADD.W ", 2, "#2", "N/A"),
		conversion("INV", "XOR ", 2, "#-1", "N/A"),
		conversion("INV.B", "XOR.B ", 2, "#-1", "N/A"),
		conversion("INV.W", "XOR.W ", 2, "#-1", "N/A"),
		conversion("JUMP", "MOV ", 1, "N/A", "R7"),
		conversion("NOP", "MOV R6,R6", 0, "N/A", "N/A"),
		conversion("PULL", "LD ", 2, "R5+", "N/A"),
		conversion("PUSH", "ST ", 2, "-R5", "N/A"),
		conversion("RET", "MOV R4,R7", 0, "N/A", "N/A"),
		conversion("RLC", "ADDC ", 3, "N/A", "N/A"),
		conversion("RLC.B", "ADDC.B ", 3, "N/A", "N/A"),
		conversion("RLC.W", "ADDC.W ", 3, "N/A", "N/A"),
		conversion("SBC", "SUBC ", 2, "#0", "N/A"),
		conversion("SBC.B", "SUBC.B ", 2, "#0", "N/A"),
		conversion("SBC.W", "SUBC.W ", 2, "#0", "N/A"),
		conversion("SETC", "BIS #1,R6", 0, "N/A", "N/A"),
		conversion("SETN", "BIS #4,R6", 0, "N/A", "N/A"),
		conversion("SETZ", "BIS #2,R6", 0, "N/A", "N/A"),
		conversion("SLA", "ADD ", 3, "N/A", "N/A"),
		conversion("SLA.B", "ADD.B ", 3, "N/A", "N/A"),
		conversion("SLA.W", "ADD.W ", 3, "N/A", "N/A"),
		conversion("SPL0", "MOVLZ #$0,R6", 0, "N/A", "N/A"),
		conversion("SPL1", "MOVLZ #$20,R6", 0, "N/A", "N/A"),
		conversion("SPL2", "MOVLZ #$40,R6", 0, "N/A", "N/A"),
		conversion("SPL3", "MOVLZ #$60,R6", 0, "N/A", "N/A"),
		conversion("SPL4", "MOVLZ #$80,R6", 0, "N/A", "N/A"),
		conversion("SPL5", "MOVLZ #$A0,R6", 0, "N/A", "N/A"),
		conversion("SPL6", "MOVLZ #$C0,R6", 0, "N/A", "N/A"),
		conversion("SPL7", "MOVLZ #$E0,R6", 0, "N/A", "N/A"),
		conversion("TST", "CMP ", 2, "#0", "N/A"),
		conversion("TST.B", "CMP.B ", 2, "#0", "N/A"),
		conversion("TST.W", "CMP.W ", 2, "#0", "N/A"),
	};

	for (unsigned int i = 0; i < TABLE_SIZE; i++) v.push_back(c_t[i]);

	return v;
}