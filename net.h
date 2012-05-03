#ifndef NET_H
#define NET_H
#include <vector>
#include <string>
#include "global.h"
using namespace std;

enum {WHITE, GREY, BLACK};

class Gate;

class Net {
 public:
  Net();
  Net(string n);
  ~Net() {
		delete drivers;
		delete loads;
	}
  void addDriver(Gate *g);
  void addLoad(Gate *g);
  vector<Gate *> *getLoads();
  vector<Gate *> *getDrivers();
  string name();
  void setVal(char v);
  char computeVal();
	char computeDelay();
  char getVal();
  void printDriversLoads();
	int color;
 private:
  vector<Gate *> *drivers;
  vector<Gate *> *loads;
  char val;
  string netname;
};
#endif
