/*
	- Pre-assembler for the X-Makina Project 
	- ECED3403 Assignment 1
	- Headerfile for the pre-assembler mainline
	- Finlay Miller B00675696
	- 03 June 2018
*/

#ifndef PREASSEMBLER_H
#define PREASSEMBLER_H

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

/* required classes and functions */
#include "record.h"
#include "conversion.h"
#include "formatting.h"

/* global definitions */
#define IFILE_PATH "A:/Documents/GitHub/PreAssembler/input.txt"
#define OFILE_PATH "A:/Documents/GitHub/PreAssembler/output.txt"
#define TABLE_SIZE 56

#endif // !PREASSEMBLER_H