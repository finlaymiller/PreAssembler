/*
- Pre-assembler for the X-Makina Project
- ECED3403 Assignment 1
- Headerfile for the pre-assembler's convert function
- Finlay Miller B00675696
- 03 June 2018
*/


#ifndef CONVERT_H
#define CONVERT_H

#include "preassembler.h"
#include <string>
#include <vector>
#include <locale>
#include <algorithm>
#include <iterator>

record convert(std::vector<std::string>, std::vector<conversion>);

#endif // !CONVERT_H
