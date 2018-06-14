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
		conversion("ADC", "ADDC ", 2, "#0,", ""),
		conversion("ADC.B", "ADDC.B ", 2, "#0,", ""),
		conversion("ADC.W", "ADDC.W ", 2, "#0,", ""),
		conversion("CALL", "BL ", 2, "", ""),
		conversion("CLR", "MOV ", 2, "#0,", ""),
		conversion("CLR.B", "MOV.B ", 2, "#0,", ""),
		conversion("CLR.W", "MOV.W ", 2, "#0,", ""),
		conversion("CLRC", "BIC #1,R6 ", 0, "", ""),
		conversion("CLRN", "BIC #4,R6 ", 0, "", ""),
		conversion("CLRZ", "BIC #2,R6 ", 0, "", ""),
		conversion("DADC", "DADD ", 2, "#0,", ""),
		conversion("DADC.B", "DADD.B ", 2, "#0,", ""),
		conversion("DADC.W", "DADD.W ", 2, "#0,", ""),
		conversion("DEC", "SUB ", 2, "#1,", ""),
		conversion("DEC.B", "SUB.B ", 2, "#1,", ""),
		conversion("DEC.W", "SUB.W ", 2, "#1,", ""),
		conversion("DECD", "SUB ", 2, "#2,", ""),
		conversion("DECD.B", "SUB.B ", 2, "#2,", ""),
		conversion("DEC.W", "SUB.W ", 2, "#2,", ""),
		conversion("INC", "ADD ", 2, "#1,", ""),
		conversion("INC.B", "ADD.B ", 2, "#1,", ""),
		conversion("INC.W", "ADD.W ", 2, "#1,", ""),
		conversion("INCD", "ADD ", 2, "#2,", ""),
		conversion("INCD.B", "ADD.B ", 2, "#2,", ""),
		conversion("INCD.W", "ADD.W ", 2, "#2,", ""),
		conversion("INV", "XOR ", 2, "#-1,", ""),
		conversion("INV.B", "XOR.B ", 2, "#-1,", ""),
		conversion("INV.W", "XOR.W ", 2, "#-1", ""),
		conversion("JUMP", "MOV ", 1, "", ",R7"),
		conversion("NOP", "MOV R6,R6", 0, "", ""),
		conversion("PULL", "LD ", 2, "R5+,", ""),
		conversion("PUSH", "ST ", 1, "", ",-R5"),
		conversion("RET", "MOV R4,R7", 0, "", ""),
		conversion("RLC", "ADDC ", 3, "", ""),
		conversion("RLC.B", "ADDC.B ", 3, "", ""),
		conversion("RLC.W", "ADDC.W ", 3, "", ""),
		conversion("SBC", "SUBC ", 2, "#0,", ""),
		conversion("SBC.B", "SUBC.B ", 2, "#0,", ""),
		conversion("SBC.W", "SUBC.W ", 2, "#0,", ""),
		conversion("SETC", "BIS #1,R6", 0, "", ""),
		conversion("SETN", "BIS #4,R6", 0, "", ""),
		conversion("SETZ", "BIS #2,R6", 0, "", ""),
		conversion("SLA", "ADD ", 3, "", ""),
		conversion("SLA.B", "ADD.B ", 3, "", ""),
		conversion("SLA.W", "ADD.W ", 3, "", ""),
		conversion("SPL0", "MOVLZ #$0,R6", 0, "", ""),
		conversion("SPL1", "MOVLZ #$20,R6", 0, "", ""),
		conversion("SPL2", "MOVLZ #$40,R6", 0, "", ""),
		conversion("SPL3", "MOVLZ #$60,R6", 0, "", ""),
		conversion("SPL4", "MOVLZ #$80,R6", 0, "", ""),
		conversion("SPL5", "MOVLZ #$A0,R6", 0, "", ""),
		conversion("SPL6", "MOVLZ #$C0,R6", 0, "", ""),
		conversion("SPL7", "MOVLZ #$E0,R6", 0, "", ""),
		conversion("TST", "CMP ", 2, "#0,", ""),
		conversion("TST.B", "CMP.B ", 2, "#0,", ""),
		conversion("TST.W", "CMP.W ", 2, "#0,", ""),
	};

	for (unsigned int i = 0; i < TABLE_SIZE; i++) v.push_back(c_t[i]);

	return v;
}