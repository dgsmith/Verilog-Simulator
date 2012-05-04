#ifndef DESIGN_H
#define DESIGN_H
#include <ostream>
#include <vector>
#include <map>
#include <string>
#include <deque>
#include "global.h"
#include "gate.h"
#include "net.h"

using namespace std;

class Design {
 public:
  Design();
  Design(string n);
  ~Design() {
    for(map<string, Net*>::iterator it=design_nets.begin(); it!=design_nets.end(); it++)
    {
      delete it->second;
    }
    for(map<string, Gate*>::iterator it=design_gates.begin(); it!=design_gates.end(); it++)
    {
      delete it->second;
    }
  }
	void make_name(string n);
  string name();
  void add_pi(string n);
  void add_po(string n);
  Net *find_net(string net_name);
  Gate *find_gate(string inst_name);
  Net* add_find_net(string n);
  Gate* add_find_gate(int gtype, string n, int d);
  vector<Net *> get_pi_nets();
  vector<Net *> get_po_nets();
  vector<Net *> get_wire_nets();
  vector<Net *> all_nets();
  vector<Gate *> all_gates();
  void dump(ostream &os);
	Net* DFSvisit(Net* currentNet, int depth = 0);
	void toposort();
	deque<Net *> get_toposortedList();
  map<string, Net*>* get_design_nets() { return &design_nets; }
 private:
  string desname;
  map<string, Net *> design_nets;
  map<string, Gate *> design_gates;
  vector<string> pis;
  vector<string> pos;
	deque<Net *> toposortedList;

};

#endif
