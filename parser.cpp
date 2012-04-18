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

enum {COMMENT, BLANK, MODULE, INPUT, OUTPUT, WIRE, GATE, END, ERROR};
	
#define ID "[A-Za-z_][A-Za-z0-9_]*"
#define NUM "[0-9]+"
#define GATE_TYPE ""and" | "or" | "nand" | "nor" | "xor" | "not""

int lineType(string currentline);
string getID(string characters);
void parenParser(vector<string> *ports, string input);
void gateInfo(string name, string info, map<string, vector<string> > *gates);

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
				continue;
			case BLANK :
				
				continue;
			case MODULE :
				// line defining a module
				string possibleID;
				getline(ss ,possibleID, '(');
				designName = getID(possibleID); // get name 
				
				string possiblePorts;
				getline(ss, possiblePorts, ')');
				parenParser(&port_list, possiblePorts);
				
				continue;
			case INPUT :
				// input line
				string possibleID;
				getline(ss,possibleID,';'); // get up to semicolon
				inputs.push_back(getID(possibleID)); // get id from selection and add it to the list of inputs
				
				continue;
			case OUTPUT :
				// output line
				string possibleID;
				getline(ss,possibleID,';'); // get up to semicolon
				outputs.push_back(getID(possibleID)); // get id from selection and add it to the list of outputs
				
				continue;
			case WIRE :
				// wire line
				string possibleID;
				getline(ss,possibleID,';'); // get up to semicolon
				wires.push_back(getID(possibleID)); // get id from selection and add it to the list of wires
				
				continue;
			case GATE :
				// gate line
				string gateInfo;
				getline(ss,gateInfo,'(') // get up to the port list stuff
				gateInfo(firsttoken, gateInfo, gates);
				
				vector<string> currentGatePuts;
				string possiblePorts;
				getline(ss,possiblePorts, ')');
				parentParser(&currentGatePuts,possiblePorts);
				// create the gate here
				
				continue;
			case END :
				// done!
				continue;
			case ERROR :
				// error...
				continue;
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

void gateInfo(string type, string info, map<string, vector<string>> *gates)
{
	// looking for type of gate and delay info (if there) and gate name
	stringstream ss(info);
	if(ss.peek() == '#')	{  // a gate delay is defined!!
		ss.seekg(ios::cur + 1);
		string delay, name;
		ss >> delay >> name;
		gates[name] = {type, delay};
	}
	else	{
		ss >> name;
		gates[name] = {type, '1'};
	}
}