#include "net.h"
#include "gate.h"
#include <iostream>
using namespace std;

Net::Net()
{
	
}

Net::Net(string n)
{
	netname = n;
  val = 'X';
}

void Net::addDriver(Gate *g)
{
	
}

void Net::addLoad(Gate *g)
{
	
}

vector<Gate *> * Net::getLoads()
{
	
}

vector<Gate *> * Net::getDrivers()
{
	
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
  
}