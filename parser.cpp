#include <iostream>
#include <ostream>
#include "design.h"
#include "gate.h"
#include "net.h"

using namespace std;

Design *parseThatShit(string ifile);

Design *parseThatShit(string ifile)
{
	ifstream ifile(ifile, ifstream::in);
	while(ifile.good())
	{
		string currentline;
		getline(ifile, currentline);
		stringstream ss(currentline);
		if(!ss.good())
		{
			// no text here yo
			continue;
		}
		string token;
		ss >> token;
		if(token == "//")
			// disregard comments
			continue;
		if(token == "module")
		{
			// start of design
			// get the name first
			string next_token;
			getline(ss, next_token, "(");
			string module_name;
			next_token >> module_name;
			// now get the list of ports
			string port_list;
			getline(ss, port_list, ")");
			// parse the list for inputs and outputs
			stringstream port_list(port_list);
			while(!port_list.fail()) // will run even if eof bit is set!!
			{
				string current_port;
				getline(port_list,current_port,",");
				
			}
		}
	}
}