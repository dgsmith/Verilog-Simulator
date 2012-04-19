#include "design.h"
#include <stdexcept>
#include <set>
using namespace std;

Design::Design()
{
	desname = "design";
	
}

// contains name of the design
Design::Design(string n)
{
	desname = n;
}

Design::~Design()
{
	
}

// returns name of device
string Design::name()
{
	return desname;
}

void Design::make_name(string n)
{
	desname = n;
}

// add an input's name to the list of PIs
void Design::add_pi(string n)
{
	pis.push_back(n);
}

// add an output's name to list of POs
void Design::add_po(string n)
{
	pos.push_back(n);
}

// returns NULL or pointer to net object
Net* Design::find_net(string net_name)
{
	map<string, Net*>::iterator it;
	it = design_nets.find(net_name);
	if(it == design_nets.end())	{ // not found :/
		throw range_error("Net not found :(");
	}
	else	{ // found :D
		return it->second;
	}
}

// same as find_net, but with gates
Gate* Design::find_gate(string inst_name)
{
	map<string, Gate*>::iterator it;
	it = design_gates.find(inst_name);
	if(it == design_gates.end())	{ // not found :/
		throw range_error("Gate not found :(");
	}
	else	{ // found :D
		return it->second;
	}
}

// returns a pointer to the Net object with the given name
// OR if a net with the given name doesn't exist, 
// allocates a new one and returns a pointer to it.
Net* Design::add_find_net(string n)
{
	map<string, Net*>::iterator it;
	it = design_nets.find(n);
	if(it != design_nets.end())	{ // already exists!!
		return it->second;
	}
	else	{ // doesn't exist
		Net *newNet = new Net(n);
		design_nets[n] = newNet;
		return newNet;
	}
	
}

// same as add_find_net but for gates
// gtype is the enum value of the gate type
Gate* Design::add_find_gate(int gtype, string n, int d)
{
	map<string, Gate*>::iterator it;
	it = design_gates.find(n);
	if(it != design_gates.end())	{ // already exists!!
		return it->second;
	}
	else	{ // doesn't exist
		switch(gtype)	{
			case AND	:
			{
				And *newGate = new And(n,d);
				design_gates[n] = newGate;
				return newGate;
			}
			case OR		:
			{
				Or *newGate = new Or(n,d);
				design_gates[n] = newGate;
				return newGate;
			}
			case NAND	:
			{
				Nand *newGate = new Nand(n,d);
				design_gates[n] = newGate;
				return newGate;
			}
			case NOR	:
			{
				Nor *newGate = new Nor(n,d);
				design_gates[n] = newGate;
				return newGate;
			}
			case XOR	:
			{
				Xor *newGate = new Xor(n,d);
				design_gates[n] = newGate;
				return newGate;
			}
			case NOT	:
			{
				Not *newGate = new Not(n,d);
				design_gates[n] = newGate;
				return newGate;
			}
			default		:
			{
				ERROR("invalid gate type");
				break;
			}
		}
	}
}

// allocates and creates a new vector of pointers to the PI Nets
vector<Net *> * Design::get_pi_nets()
{
	vector<string>::iterator name;
	map<string, Net*>::iterator foundnet;
	vector<Net *> *PIs = new vector<Net *>;
	for(name = pis.begin();name != pis.end();name++)
	{
		foundnet = design_nets.find(*name);
		if(foundnet != design_nets.end())	{ // found pi!
			PIs->push_back(foundnet->second);
		}
		else	{
			//nothing to see here
		}
	}
	return PIs;
}

// same as get_pi_nets
vector<Net *> * Design::get_po_nets()
{
	vector<string>::iterator name;
	map<string, Net*>::iterator foundnet;
	vector<Net *> *POs = new vector<Net *>;
	for(name = pos.begin();name != pos.end();name++)
	{
		foundnet = design_nets.find(*name);
		if(foundnet != design_nets.end())	{ // found pi!
			POs->push_back(foundnet->second);
		}
		else	{
			//nothing to see here
		}
	}
	return POs;
}

vector<Net *> * Design::get_wire_nets()
{
  // Create a set of inputs and outputs so we can search faster
  set<string> pios;  
  for(vector<string>::iterator it=pos.begin(); it!=pos.end(); it++) {
    pios.insert(*it);
  }
  for(vector<string>::iterator it=pis.begin(); it!=pis.end(); it++) {
    pios.insert(*it);
  }
  
  // To return
  vector<Net *> *wire = new vector<Net *>;
  
  // Iterate through all nets in the map
  for(map<string, Net *>::iterator it=design_nets.begin(); it!=design_nets.end(); it++) {
    // If it is not an input or output
    if(pios.find(it->second->name()) == pios.end())
    {
      wire->push_back(it->second);
    } else {
      LOG("Skipping " << it->second->name());
    }
  }
  
	return wire;
}

// returns pointers to all net objects
vector<Net *> * Design::all_nets()
{
	map<string, Net*>::iterator it;
	vector<Net *> *all_nets = new vector<Net *>;
	for(it = design_nets.begin();it != design_nets.end(); it++)
	{
		all_nets->push_back(it->second);
	}
	return all_nets;
}

// similar to all_nets but for gates
vector<Gate *> * Design::all_gates()
{
	map<string, Gate*>::iterator it;
	vector<Gate *> *all_gates = new vector<Gate *>;
	for(it = design_gates.begin();it != design_gates.end(); it++)
	{
		all_gates->push_back(it->second);
	}
	return all_gates;
}

// write out the design in Verilog format to the provided ostream
void Design::dump(ostream &os)
{
  os << "module " << this->name() << "(";
  vector<Net*> *v = this->get_pi_nets();
  for(vector<Net*>::iterator it=v->begin(); it!=v->end(); it++) {
    os << (*it)->name() << ", ";
  }
  v = this->get_po_nets();
  for(vector<Net*>::iterator it=v->begin(); it!=v->end(); it++) {
    os << (*it)->name();
    if(it+1 != v->end()) os << ", ";
  }
  
  os << ");" << endl;
  
  v = this->get_pi_nets();
  for(vector<Net*>::iterator it=v->begin(); it!=v->end(); it++) {
    os << "\tinput " << (*it)->name() << ";" << endl;
  }
  
  v = this->get_po_nets();
  for(vector<Net*>::iterator it=v->begin(); it!=v->end(); it++) {
    os << "\toutput " << (*it)->name() << ";" << endl;
  }
  
  v = this->get_wire_nets();
  for(vector<Net*>::iterator it=v->begin(); it!=v->end(); it++) {
    os << "\twire " << (*it)->name() << ";" << endl;
  }
  
  os << endl;
  
  vector<Gate*> *g = this->all_gates();
  for(vector<Gate*>::iterator it=g->begin(); it!=g->end(); it++) {
    os << "\t";
    (*it)->dump(os);
  }
  
  os << "endmodule" << endl;
  
}
