/*
- Pre-assembler for the X-Makina Project
- ECED3403 Assignment 1
- This is the header file for the pre-assembler's string splitter function
- Finlay Miller B00675696
- 3 June 2018
*/

#ifndef SPLIT_H
#define SPLIT_H

#include "preassembler.h"
using namespace std;

vector<string> split(const string& input, const string& delims);

#endif // !SPLIT_H
