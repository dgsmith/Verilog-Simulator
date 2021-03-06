#include "net.h"
#include "gate.h"
#include <iostream>
using namespace std;

Net::Net()
{
}

Net::Net(string n)
{
  drivers = new vector<Gate*>();
  loads = new vector<Gate*>();
  
	netname = n;
  val = 'X';
  color = WHITE;
}

void Net::addDriver(Gate *g)
{
  drivers->push_back(g);
}

void Net::addLoad(Gate *g)
{
  loads->push_back(g);
}

vector<Gate *> * Net::getLoads()
{
	return loads;
}

vector<Gate *> * Net::getDrivers()
{
	return drivers;
}

string Net::name()
{
	return netname;
}

void Net::setVal(char v)
{
	val = v;
}

char Net::computeVal()
{
	if(drivers->size() != 1) // more than one driver, need to check if value is saaamme!!
	{
		vector<char> values;
		char temp;
		for(vector<Gate*>::iterator it=drivers->begin();it != drivers->end(); it++)
		{
			values.push_back((*it)->eval());
		}
		temp = values[0];
		for(vector<char>::iterator it=values.begin() + 1;it != values.end(); it++)
		{
			if(*it == temp)
			{
				// it's all good, drivers driving same value...
				val = temp;
			}
			else
			{
				// not good!
				val = 'X';
			}
		}
	}
	else // just one driver
	{
		val = drivers->front()->eval();
	}
	return val;
}

char Net::getVal()
{
	return val;
}

void Net::printDriversLoads()
{
  cout << MAGENTA << "Drivers: " << RESET;
	for(vector<Gate*>::iterator it=drivers->begin(); it!=drivers->end(); it++){
    cout << (*it)->name() << " ";
	}

  cout << TEAL << "Loads: " << RESET;
	for(vector<Gate*>::iterator it=loads->begin(); it!=loads->end(); it++){
	  cout << (*it)->name() << " ";
	}
  
  cout << endl;
  
}

int Net::computeDelay()
{
  if(drivers->size() == 0) {
    return 0; // Input gate
  }
  int cumulativeMaxVal = 0;
  for(vector<Gate*>::iterator it=drivers->begin(); it!=drivers->end(); it++) {
    Gate *g = *it;
    
    // Find max values of the gate's nets
    int maxVal = 0;
    for(vector<Net*>::iterator jt=g->getInputs()->begin(); jt!=g->getInputs()->end(); jt++) {
      maxVal = max(maxVal, (*jt)->computeDelay());
    }
    
    cumulativeMaxVal = max(cumulativeMaxVal, maxVal + g->getDelay());
  }
	return cumulativeMaxVal;
}