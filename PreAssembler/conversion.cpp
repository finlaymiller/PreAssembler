/*
- Pre-assembler for the X-Makina Project
- ECED3403 Assignment 1
- Conversion class methods
- Finlay Miller B00675696
- 03 June 2018
*/

#include "conversion.h"

conversion::conversion(std::string i, std::string e, bool a, std::string l, std::string r)
{
	instruction = i;
	emulation = e;
	hasArgs = a;
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
	out << hasArgs << " ";
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
		conversion("ADC", "ADDC ", true, "#0", "N/A"),
		conversion("ADC.B", "ADDC.B ", true, "#0", "N/A"),
		conversion("ADC.W", "ADDC.W ", true, "#0", "N/A"),
		conversion("CALL", "BL ", true, "N/A", "N/A"),
		conversion("CLR", "MOV ", true, "#0", "N/A"),
		conversion("CLR.B", "MOV.B ", true, "#0", "N/A"),
		conversion("CLR.W", "MOV.W ", true, "#0", "N/A"),
		conversion("CLRC", "BIC #1,R6 ", false, "N/A", "N/A"),
		conversion("CLRN", "BIC #4,R6 ", false, "N/A", "N/A"),
		conversion("CLRZ", "BIC #2,R6 ", false, "N/A", "N/A"),
		conversion("DADC", "DADD ", true, "#0", "N/A"),
		conversion("DADC.B", "DADD.B ", true, "#0", "N/A"),
		conversion("DADC.W", "DADD.W ", true, "#0", "N/A"),
		conversion("DEC", "SUB ", true, "#1", "N/A"),
		conversion("DEC.B", "SUB.B ", true, "#1", "N/A"),
		conversion("DEC.W", "SUB.W ", true, "#1", "N/A"),
		conversion("DECD", "SUB ", true, "#2", "N/A"),
		conversion("DECD.B", "SUB.B ", true, "#2", "N/A"),
		conversion("DEC.W", "SUB.W ", true, "#2", "N/A"),
		conversion("INC", "ADD ", true, "#1", "N/A"),
		conversion("INC.B", "ADD.B ", true, "#1", "N/A"),
		conversion("INC.W", "ADD.W ", true, "#1", "N/A"),
		conversion("INCD", "ADD ", true, "#2", "N/A"),
		conversion("INCD.B", "ADD.B ", true, "#2", "N/A"),
		conversion("INCD.W", "ADD.W ", true, "#2", "N/A"),
		conversion("INV", "XOR ", true, "#-1", "N/A"),
		conversion("INV.B", "XOR.B ", true, "#-1", "N/A"),
		conversion("INV.W", "XOR.W ", true, "#-1", "N/A"),
		conversion("JUMP", "MOV ", true, "N/A", "R7"),
		conversion("NOP", "MOV R6,R6", false, "N/A", "N/A"),
		conversion("PULL", "LD ", true, "R5+", "N/A"),
		conversion("PUSH", "ST ", true, "-R5", "N/A"),
		conversion("RET", "MOV R4,R7", false, "N/A", "N/A"),
		conversion("RLC", "ADDC ", true, "N/A", "N/A"),
		conversion("RLC.B", "ADDC.B ", true, "N/A", "N/A"),
		conversion("RLC.W", "ADDC.W ", true, "N/A", "N/A"),
		conversion("SBC", "SUBC ", true, "#0", "N/A"),
		conversion("SBC.B", "SUBC.B ", true, "#0", "N/A"),
		conversion("SBC.W", "SUBC.W ", true, "#0", "N/A"),
		conversion("SETC", "BIS #1,R6", false, "N/A", "N/A"),
		conversion("SETN", "BIS #4,R6", false, "N/A", "N/A"),
		conversion("SETZ", "BIS #2,R6", false, "N/A", "N/A"),
		conversion("SLA", "ADD ", true, "N/A", "N/A"),
		conversion("SLA.B", "ADD.B ", true, "N/A", "N/A"),
		conversion("SLA.W", "ADD.W ", true, "N/A", "N/A"),
		conversion("SPL0", "MOVLZ #$0,R6", false, "N/A", "N/A"),
		conversion("SPL1", "MOVLZ #$20,R6", false, "N/A", "N/A"),
		conversion("SPL2", "MOVLZ #$40,R6", false, "N/A", "N/A"),
		conversion("SPL3", "MOVLZ #$60,R6", false, "N/A", "N/A"),
		conversion("SPL4", "MOVLZ #$80,R6", false, "N/A", "N/A"),
		conversion("SPL5", "MOVLZ #$A0,R6", false, "N/A", "N/A"),
		conversion("SPL6", "MOVLZ #$C0,R6", false, "N/A", "N/A"),
		conversion("SPL7", "MOVLZ #$E0,R6", false, "N/A", "N/A"),
		conversion("TST", "CMP ", true, "#0", "N/A"),
		conversion("TST.B", "CMP.B ", true, "#0", "N/A"),
		conversion("TST.W", "CMP.W ", true, "#0", "N/A"),
	};

	for (unsigned int i = 0; i < TABLE_SIZE; i++) v.push_back(c_t[i]);

	return v;
}