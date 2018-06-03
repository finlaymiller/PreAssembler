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
#include <algorithm>
#include <fstream>
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <locale>
#include <iterator>

/* custom files */
#include "binary_search.h"
#include "conversion.h"
#include "convert.h"
#include "error.h"
#include "format_record.h"
#include "get_input.h"
#include "record.h"
#include "split.h"
#include "stdafx.h"
#include "stdio.h"

/* global definitions */
#define IFILE_PATH "A:/Documents/GitHub/PreAssembler/input - easy.txt"
#define OFILE_PATH "A:/Documents/GitHub/PreAssembler/output - easy.txt"
#define TABLE_SIZE 56

using namespace std;

#endif // !PREASSEMBLER_H