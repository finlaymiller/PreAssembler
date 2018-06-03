/*
- Pre-assembler for the X-Makina Project
- ECED3403 Assignment 1
- This is the source file for the pre-assembler's conversion table generator
- Finlay Miller B00675696
- 3 June 2018
*/

#include "generate_table.h"

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
		conversion("ADC", "ADDC ", true, "#0", ""),
		conversion("ADC.B", "ADDC.B ", true, "#0", ""),
		conversion("ADC.W", "ADDC.W ", true, "#0", ""),
		conversion("CALL", "BL ", true, "", ""),
		conversion("CLR", "MOV ", true, "#0", ""),
		conversion("CLR.B", "MOV.B ", true, "#0", ""),
		conversion("CLR.W", "MOV.W ", true, "#0", ""),
		conversion("CLRC", "BIC #1,R6 ", false, "", ""),
		conversion("CLRN", "BIC #4,R6 ", false, "", ""),
		conversion("CLRZ", "BIC #2,R6 ", false, "", ""),
		conversion("DADC", "DADD ", true, "#0", ""),
		conversion("DADC.B", "DADD.B ", true, "#0", ""),
		conversion("DADC.W", "DADD.W ", true, "#0", ""),
		conversion("DEC", "SUB ", true, "#1", ""),
		conversion("DEC.B", "SUB.B ", true, "#1", ""),
		conversion("DEC.W", "SUB.W ", true, "#1", ""),
		conversion("DECD", "SUB ", true, "#2", ""),
		conversion("DECD.B", "SUB.B ", true, "#2", ""),
		conversion("DEC.W", "SUB.W ", true, "#2", ""),
		conversion("INC", "ADD ", true, "#1", ""),
		conversion("INC.B", "ADD.B ", true, "#1", ""),
		conversion("INC.W", "ADD.W ", true, "#1", ""),
		conversion("INCD", "ADD ", true, "#2", ""),
		conversion("INCD.B", "ADD.B ", true, "#2", ""),
		conversion("INCD.W", "ADD.W ", true, "#2", ""),
		conversion("INV", "XOR ", true, "#-1", ""),
		conversion("INV.B", "XOR.B ", true, "#-1", ""),
		conversion("INV.W", "XOR.W ", true, "#-1", ""),
		conversion("JUMP", "MOV ", true, "", "R7"),
		conversion("NOP", "MOV R6,R6", false, "", ""),
		conversion("PULL", "LD ", true, "R5+", ""),
		conversion("PUSH", "ST ", true, "-R5", ""),
		conversion("RET", "MOV R4,R7", false, "", ""),
		conversion("RLC", "ADDC ", true, "", ""),
		conversion("RLC.B", "ADDC.B ", true, "", ""),
		conversion("RLC.W", "ADDC.W ", true, "", ""),
		conversion("SBC", "SUBC ", true, "#0", ""),
		conversion("SBC.B", "SUBC.B ", true, "#0", ""),
		conversion("SBC.W", "SUBC.W ", true, "#0", ""),
		conversion("SETC", "BIS #1,R6", false, "", ""),
		conversion("SETN", "BIS #4,R6", false, "", ""),
		conversion("SETZ", "BIS #2,R6", false, "", ""),
		conversion("SLA", "ADD ", true, "", ""),
		conversion("SLA.B", "ADD.B ", true, "", ""),
		conversion("SLA.W", "ADD.W ", true, "", ""),
		conversion("SPL0", "MOVLZ #$0,R6", false, "", ""),
		conversion("SPL1", "MOVLZ #$20,R6", false, "", ""),
		conversion("SPL2", "MOVLZ #$40,R6", false, "", ""),
		conversion("SPL3", "MOVLZ #$60,R6", false, "", ""),
		conversion("SPL4", "MOVLZ #$80,R6", false, "", ""),
		conversion("SPL5", "MOVLZ #$A0,R6", false, "", ""),
		conversion("SPL6", "MOVLZ #$C0,R6", false, "", ""),
		conversion("SPL7", "MOVLZ #$E0,R6", false, "", ""),
		conversion("TST", "CMP ", true, "#0", ""),
		conversion("TST.B", "CMP.B ", true, "#0", ""),
		conversion("TST.W", "CMP.W ", true, "#0", ""),
	};

	for (unsigned int i = 0; i < TABLE_SIZE; i++) v.push_back(c_t[i]);

	return v;
}