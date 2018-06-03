/*
- Pre-assembler for the X-Makina Project
- ECED3403 Assignment 1
- This is the header file for the pre-assembler's required libraries, constants, etc.
- Finlay Miller B00675696
- 3 June 2018
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

/* custom files */
#include "error.h"
#include "conversion.h"
#include "record.h"
#include "generate_table.h"

/* global definitions */
#define IFILE_PATH "A:/Documents/GitHub/PreAssembler/input - easy.txt"
#define OFILE_PATH "A:/Documents/GitHub/PreAssembler/output - easy.txt"
#define TABLE_SIZE 56

using namespace std;

#endif // !PREASSEMBLER_H
