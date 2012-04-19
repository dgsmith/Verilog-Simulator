#include "design.h"
#include <stdexcept>
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
				return newGate;
			}
			case OR		:
			{
				Or *newGate = new Or(n,d);
				return newGate;
			}
			case NAND	:
			{
				Nand *newGate = new Nand(n,d);
				return newGate;
			}
			case NOR	:
			{
				Nor *newGate = new Nor(n,d);
				return newGate;
			}
			case XOR	:
			{
				Xor *newGate = new Xor(n,d);
				return newGate;
			}
			case NOT	:
			{
				Not *newGate = new Not(n,d);
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
	
}

// same as get_pi_nets
vector<Net *> * Design::get_po_nets()
{
	
}

// same as get_pi_nets
vector<Net *> * Design::get_wire_nets()
{
	
}

// returns pointers to all net objects
vector<Net *> * Design::all_nets()
{
	
}

// similar to all_nets but for gates
vector<Gate *> * Design::all_gates()
{
	
}

// write out the design in Verilog format to the provided ostream
void Design::dump(ostream &os)
{
	
}
