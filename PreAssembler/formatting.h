/*
- Pre-assembler for the X-Makina Project
- ECED3403 Assignment 1
- Headerfile for the pre-assembler's formatting tools
- Finlay Miller B00675696
- 03 June 2018
*/


#ifndef FORMATTING_H
#define FORMATTING_H

#include "stdafx.h"
#include "stdio.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <iterator>

std::string uppercaser(std::string s);
std::vector<std::string> split(const std::string& input, const std::string& delims);
std::vector<std::string> format_record(std::string raw);

#endif // !FORMATTING_H
