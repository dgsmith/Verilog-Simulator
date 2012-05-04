#include "logicsim.h"
#include <iostream>
#include <fstream>
#include <ostream>
#include <sstream>
#include <stdexcept>
#include <vector>

using namespace std;

static unsigned int lineNum = 0;
enum{INPUTS, VALUES, BLANK};

void LogicSim::parseSimFile(string file)
{
	ifstream ifile(file.c_str(), ifstream::in);
	while(ifile.good())
	{
		lineNum++;
		
		vector<string> pos;
		vector<vector<int>> values;
		vector<vector<int>>::iterator tests = values.begin();
		
		string currentline;
		getline(ifile, currentline);
		stringstream ss(currentline);
		string firsttoken;
		ss >> firsttoken;
		try{
			switch(defineLine(firsttoken))
			{
				case INPUTS	:
				{
					pos.push_back(firsttoken);
					while(ss.good())
					{
						string temp;
						ss >> temp;
						pos.push_back(temp);
					}
				}
				case VALUES	:
				{
					values->push_back(firsttoken);
					while(ss.good())
					{
						int temp;
						ss >> temp;
						values->push_back(temp);
					}
					tests++;
				}
				case BLANK	:
				{
					// done reading
				}
				default	:
				{
					throw runtime_error("grammar error");
				}
			}
		} catch(runtime_error &ex)	{
			string line;
			stringstream ss;
			ss << lineNum;
			line = ss.str();
			throw runtime_error("On line " + line + " " + ex.what());
		}
	}
}

void LogicSim::runSimulation(deque<Net *> topolist)
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