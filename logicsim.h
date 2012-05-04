#ifndef LOGICSIM_H
#define LOGICSIM_H
#include "global.h"
#include "net.h"
#include "gate.h"
#include "design.h"
#include <string>
#include <deque>
#include <set>

using namespace std;

int defineLine(string identifier);

class LogicSim	{
	public:
		LogicSim(string file, Design *design);
		void runSimulation(deque<Net *> topolist);
		void outputTheFile(string file, Design* design);
  public:
    vector<string> pi_order;
    set<string> pi_set;
		vector<map<string,char> > values;
    vector<map<string,char> > results;
		
};

#endif