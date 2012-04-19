#include "global.h"
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
void parenParser(vector<string> *ports, string input);
void gateInfo(string type, string info, vector<string> *gate);

Design *parseThatShit(string ifilename)
{
	Design *theDesign = new Design;
	vector<string> port_list;
	//vector<string> inputs;
	//vector<string> outputs;
	//vector<string> wires;
	vector<string> gate;
	
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
				if(regex_match(possibleIDModule, ID))	{
					// was an id
					theDesign->make_name(possibleIDModule);
				}
				
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
				if(regex_match(possibleIDInput, ID))	{
					//inputs.push_back(possibleIDInput); // get id from selection and add it to the list of inputs
					//Net netfound(possibleIDInput);
					theDesign->add_pi(possibleIDInput);
					Net *netfound = theDesign->add_find_net(possibleIDInput);
				}
				
				break;
			}
			case OUTPUT :
			{
				// output line
				string possibleIDOutput;
				getline(ss,possibleIDOutput,';'); // get up to semicolon
				if(regex_match(possibleIDOutput, ID))	{
					//outputs.push_back(possibleIDOutput);
					//Net netfound(possibleIDOutput);
					theDesign->add_po(possibleIDOutput);
					Net *netfound = theDesign->add_find_net(possibleIDOutput);
				}
				
				break;
			}
			case WIRE :
			{
				// wire line
				string possibleIDWire;
				getline(ss,possibleIDWire,';'); // get up to semicolon
				if(regex_match(possibleIDWire, ID))	{
					//wires.push_back(possibleIDWire);
					//Net netfound(possibleIDWire);
					Net *netfound = theDesign->add_find_net(possibleIDWire);
				}
								
				break;
			}
			case GATE :
			{
				// gate line
				string possibleGateInfo;
				getline(ss,possibleGateInfo,'('); // get up to the port list stuff
				gateInfo(firsttoken, possibleGateInfo, &gate);
				
				vector<string> currentGatePuts;
				vector<string>::iterator it;
				string possiblePorts;
				getline(ss,possiblePorts, ')');
				parenParser(&currentGatePuts,possiblePorts);
				// create the gate here
				if(firsttoken == "and")	{
					Gate *gatefound = theDesign->add_find_gate(AND,gate.at(1), atoi(gate.at(2).c_str()));
					gatefound->addOutput(theDesign->find_net(currentGatePuts.back()));
					for(it=currentGatePuts.begin();it < currentGatePuts.end() -1; it++)
					{
						gatefound->addInput(theDesign->find_net(*it));
					}
				}
				else if(firsttoken == "or")	{
					Gate *gatefound = theDesign->add_find_gate(OR,gate.at(1), atoi(gate.at(2).c_str()));
					gatefound->addOutput(theDesign->find_net(currentGatePuts.back()));
					for(it=currentGatePuts.begin();it < currentGatePuts.end() -1; it++)
					{
						gatefound->addInput(theDesign->find_net(*it));
					}
				}
				else if(firsttoken == "nand")	{
					Gate *gatefound = theDesign->add_find_gate(NAND,gate.at(1), atoi(gate.at(2).c_str()));
					gatefound->addOutput(theDesign->find_net(currentGatePuts.back()));
					for(it=currentGatePuts.begin();it < currentGatePuts.end() -1; it++)
					{
						gatefound->addInput(theDesign->find_net(*it));
					}
				}
				else if(firsttoken == "mor")	{
					Gate *gatefound = theDesign->add_find_gate(NOR,gate.at(1), atoi(gate.at(2).c_str()));
					gatefound->addOutput(theDesign->find_net(currentGatePuts.back()));
					for(it=currentGatePuts.begin();it < currentGatePuts.end() -1; it++)
					{
						gatefound->addInput(theDesign->find_net(*it));
					}
				}
				else if(firsttoken == "xor")	{
					Gate *gatefound = theDesign->add_find_gate(XOR,gate.at(1), atoi(gate.at(2).c_str()));
					gatefound->addOutput(theDesign->find_net(currentGatePuts.back()));
					for(it=currentGatePuts.begin();it < currentGatePuts.end() -1; it++)
					{
						gatefound->addInput(theDesign->find_net(*it));
					}
				}
				else if(firsttoken == "not")	{
					Gate *gatefound = theDesign->add_find_gate(NOT,gate.at(1), atoi(gate.at(2).c_str()));
					gatefound->addOutput(theDesign->find_net(currentGatePuts.back()));
					for(it=currentGatePuts.begin();it < currentGatePuts.end() -1; it++)
					{
						gatefound->addInput(theDesign->find_net(*it));
					}
				}
				else	{
					//error
				}
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
	return theDesign;
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

void gateInfo(string type, string info, vector<string> *gate)
{
	// looking for type of gate and delay info (if there) and gate name
	stringstream ss(info);
	string delay, name;
	if(ss.peek() == '#')	{  // a gate delay is defined!!
		ss.seekg(ios::cur + 1);
		ss >> delay >> name;
		gate->push_back(type);
		gate->push_back(name);
		gate->push_back(delay);
	}
	else	{
		ss >> name;
		gate->push_back(type);
		gate->push_back(name);
		gate->push_back("1");
	}
}