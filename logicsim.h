#ifndef LOGICSIM_H
#define LOGICSIM_H
#include "global.h"
#include <string>

using namespace std;

int defineLine(string identifier);

class LogicSim	{
	public:
		void parseSimFile(string file);
		void runSimulation(deque<Net *> *topolist);
		void outputTheFile(string file);
	private:
		
};

#endif