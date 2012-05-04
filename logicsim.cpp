#include "logicsim.h"
#include <iostream>

using namespace std;

static unsigned int lineNum = 0;
enum{INPUTS, VALUES, BLANK};

LogicSim::LogicSim()
{
	
}

void LogicSim::parseSimFile(string file)
{
	ifstream ifile(file.c_str(), ifstream::in);
	while(ifile.good())
	{
		lineNum++;
		
		string currentline;
		getline(ifile, currentline);
		stringstream ss(currentline);
		string firsttoken;
		ss >> firsttoken;
		try{
			switch
		}
	}
}

void LogicSim::runSimulation(deque<Net *> *topolist)
{
	
}

void LogicSim::outputTheFile(string file)
{
	
}

int defineLine(string identifier)
{
	if((identifier == "0") | (identifier == "1"))
	{
		return VALUES;
	}
	else if((identifier == " ") | (identifier == "\n") | (identifier == "\t") | (identifier == ""))
	{
		return BLANK;
	}
	else if(isalpha(identifier.c_str()[0]))
	{
		return INPUTS;
	}
}