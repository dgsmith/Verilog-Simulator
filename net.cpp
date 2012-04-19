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