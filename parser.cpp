#include <iostream>
#include <ostream>
//#include "design.h"

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
		string token;
		ss >> token;
		cout << token << endl;
	}
}