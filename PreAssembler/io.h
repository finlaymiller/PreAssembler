/*
- Pre-assembler for the X-Makina Project
- ECED3403 Assignment 1
- Headerfile for the pre-assembler's io functions
- Finlay Miller B00675696
- 03 June 2018
*/

#ifndef IO_H
#define IO_H

#include "preassembler.h"
#include "stdio.h"
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>

std::vector<std::string> get_input(std::string);
void error(std::string);
bool write_output(std::string, std::vector<record>);

#endif // !IO_H
