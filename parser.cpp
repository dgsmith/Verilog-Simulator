#include <iostream>
#include <ostream>
#include <string>
#include <regex>
#include "design.h"
#include "gate.h"
#include "net.h"

using namespace std;

enum {COMMENT, BLANK, MODULE, INPUT, OUTPUT, WIRE, GATE, END, ERROR};
	
#define ID "[A-Za-z_][A-Za-z0-9_]*"
#define NUM "[0-9]+"
#define GATE_TYPE ""and" | "or" | "nand" | "nor" | "xor" | "not""

int lineType(string currentline);
string getID(string characters);
void parenParser(vector<string> *ports, string input);

Design *parseThatShit(string ifile)
{
	string designName;
	vector<string> port_list;
	
	ifstream ifile(ifile, ifstream::in);
	while(ifile.good())
	{
		string currentline;
		getline(ifile, currentline);
		stringstream ss(currentline);
		string firsttoken;
		ss >> firsttoken;
		switch(lineType(firsttoken))
		{
			case COMMENT :
				// comment line
				continue;
			case BLANK :
				
				continue;
			case MODULE :
				// line defining a module
				string possibleID;
				getline(ss ,possibleID, "(");
				designName = getID(possibleID); // get name 
				
				string possiblePorts;
				getline(ss, possiblePorts, ")");
				parenParser(port_list, possiblePorts);
				
				continue;
			case INPUT :
				// input line
			case OUTPUT :
				
			case WIRE :
				
			case GATE :
				
			case END :
				
			case ERROR:
				
		}
	}
}

int lineType(string identifier) // going line by line, so decide what kind of line this is
{

	if(identifier == "//")
	{
		return COMMENT;
	}
	else if(identifier == "module")
	{
		return MODULE;
	}
	else if(identifier == "input")
	{
		return INPUT;
	}
	else if(identifier == "output")
	{
		return OUTPUT;
	}
	else if(identifier == "wire")
	{
		return WIRE;
	}
	else if((identifier == "and") | (identifier == "or") | (identifier == "nand") | (identifier == "nor") | (identifier == "xor") | (identifier == "not"))
	{
		return GATE;
	}
	else if(identifier == "endmodule")
	{
		return END;
	}
	else
	{
		return ERROR;
	}
}

string getID(string input)
{
	regex rgx(ID);
	smatch result;
	regex_search(input, result, rgx);
	return result.str();
}

void parenParser(vector<string>* ports, string input)
{
	stringstream ss(input);
	while(!ss.fail()) // runs last time when eof bit is set!
	{
		if(ss.eof())	{ // time to grab last num and leave!
			ss.unget();
			ports.push_back(ss.get());
			break;
		}
		string port;
		getline(ss, port, ",");
		ports.push_back(port);
	}
}