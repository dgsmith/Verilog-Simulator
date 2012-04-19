#include <iostream>
#include <ostream>
#include <fstream>
#include <sstream>
#include <string>
#include <regex.h>
#include "design.h"
#include "gate.h"
#include "net.h"

using namespace std;

bool regex_match(string target, string pattern)
{
    int status;
    regex_t re;
    	
    if (regcomp(&re, pattern.c_str(), REG_EXTENDED|REG_NOSUB) != 0) {
		return false;
    }
    status = regexec(&re, target.c_str(), (size_t) 0, NULL, 0);
    regfree(&re);
    if (status != 0) {
        return false;      /* no match */
    }
	
	// Matches
    return true;
}

enum {COMMENT, BLANK, MODULE, INPUT, OUTPUT, WIRE, GATE, END, ERROR};
	
#define ID "[A-Za-z_][A-Za-z0-9_]*"
#define NUM "[0-9]+"
#define GATE_TYPE ""and" | "or" | "nand" | "nor" | "xor" | "not""

int lineType(string currentline);
string getID(string characters);
void parenParser(vector<string> *ports, string input);
void gateInfo(string type, string info, map<string, vector<string> > *gates);

Design *parseThatShit(string ifilename)
{
	string designName;
	vector<string> port_list;
	vector<string> inputs;
	vector<string> outputs;
	vector<string> wires;
	map<string, vector<string> > gates;
	
	ifstream ifile(ifilename.c_str(), ifstream::in);
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
				break;
			case BLANK :
				
				break;
			case MODULE :
			{
				// line defining a module
				string possibleIDModule;
				getline(ss ,possibleIDModule, '(');
				designName = getID(possibleIDModule); // get name 
				
				string possiblePortsModule;
				getline(ss, possiblePortsModule, ')');
				parenParser(&port_list, possiblePortsModule);
				
				break;
			}
			case INPUT :
			{
				// input line
				string possibleIDInput;
				getline(ss,possibleIDInput,';'); // get up to semicolon
				inputs.push_back(getID(possibleIDInput)); // get id from selection and add it to the list of inputs
				
				break;
			}
			case OUTPUT :
			{
				// output line
				string possibleIDOutput;
				getline(ss,possibleIDOutput,';'); // get up to semicolon
				outputs.push_back(getID(possibleIDOutput)); // get id from selection and add it to the list of outputs
				
				break;
			}
			case WIRE :
			{
				// wire line
				string possibleIDWire;
				getline(ss,possibleIDWire,';'); // get up to semicolon
				wires.push_back(getID(possibleIDWire)); // get id from selection and add it to the list of wires
				
				break;
			}
			case GATE :
			{
				// gate line
				string possibleGateInfo;
				getline(ss,possibleGateInfo,'('); // get up to the port list stuff
				gateInfo(firsttoken, possibleGateInfo, &gates);
				
				vector<string> currentGatePuts;
				string possiblePorts;
				getline(ss,possiblePorts, ')');
				parenParser(&currentGatePuts,possiblePorts);
				// create the gate here
				
				break;
			}
			case END :
			{
				// done!
				break;
			}
			case ERROR :
			{
				// error...
				break;
			}
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
		string port;
		if(ss.eof())	{ // time to grab last num and leave!
			ss.unget();
			port = ss.get();
			ports->push_back(port);
			break;
		}
		getline(ss, port, ',');
		ports->push_back(port);
	}
}

void gateInfo(string type, string info, map<string, vector<string> > *gates)
{
	// looking for type of gate and delay info (if there) and gate name
	stringstream ss(info);
	string delay, name;
	if(ss.peek() == '#')	{  // a gate delay is defined!!
		ss.seekg(ios::cur + 1);
		ss >> delay >> name;
		(*gates)[name].push_back(type);
		(*gates)[name].push_back(delay);
	}
	else	{
		ss >> name;
		(*gates)[name].push_back(type);
		(*gates)[name].push_back("1");
	}
}