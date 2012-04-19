#ifndef DESIGN_H
#define DESIGN_H
#include <ostream>
#include <vector>
#include <map>
#include <string>
#include "global.h"
#include "gate.h"
#include "net.h"

using namespace std;

class Design {
 public:
  Design();
  Design(string n);
  ~Design();
	void make_name(string n);
  string name();
  void add_pi(string n);
  void add_po(string n);
  Net *find_net(string net_name);
  Gate *find_gate(string inst_name);
  Net* add_find_net(string n);
  Gate* add_find_gate(int gtype, string n, int d);
  vector<Net *> *get_pi_nets();
  vector<Net *> *get_po_nets();
  vector<Net *> *get_wire_nets();
  vector<Net *> *all_nets();
  vector<Gate *> *all_gates();
  void dump(ostream &os);
 private:
  string desname;
  map<string, Net *> design_nets;
  map<string, Gate *> design_gates;
  vector<string> pis;
  vector<string> pos;

};

#endif
