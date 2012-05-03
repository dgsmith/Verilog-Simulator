#ifndef LOGICSIM_H
#define LOGICSIM_H
#include "global.h"
#include <string>

using namespace std;

class LogicSim	{
	public:
		void parseSimFile(string filename);
		void runSimulation();
		void outputFile(string filename);
	private:
		
};

#endif