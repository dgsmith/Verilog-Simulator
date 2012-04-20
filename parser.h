#ifndef PARSER_H
#define PARSER_H

#include "global.h"
#include <iostream>
#include <ostream>
#include <fstream>
#include <sstream>
#include <string>
#include <regex.h>
#include <algorithm>
#include <stdexcept>
#include <stdio.h>
#include "design.h"
#include "gate.h"
#include "net.h"

using namespace std;

enum {COMMENT, BLANK, MODULE, INPUT, OUTPUT, WIRE, GATE, END, ERROR};
	
#define ID "[A-Za-z_][A-Za-z0-9_]*"
#define NUM "[0-9]+"
#define GATE_TYPE ""and" | "or" | "nand" | "nor" | "xor" | "not""

void semicolonCheck(string token);
string removeWhitespace(string input);
bool regex_match(string target, string pattern);
int lineType(string identifier, string lasttoken);
void parenParser(vector<string> *ports, string input);
void gateInfo(string type, string info, vector<string> *gate);
Design *parseThatShit(string ifilename);

#endif