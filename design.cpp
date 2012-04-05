#include "design.h"
using namespace std;

Design::Design()
{
	
}

// contains name of the design
Design::Design(string n)
{
	
}

Design::~Design()
{
	
}

// returns name of device
string Design::name()
{
	
}

// add an input's name to the list of PIs
void Design::add_pi(string n)
{
	
}

// add an output's name to list of POs
void Design::add_po(string n)
{
	
}

// returns NULL or pointer to net object
Net* Design::find_net(string net_name)
{
	
}

// same as find_net, but with gates
Gate* Deisgn::find_gate(string inst_name)
{
	
}

// returns a pointer to the Net object with the given name
// OR if a net with the given name doesn't exist, 
// allocates a new one and returns a pointer to it.
Net* Design::add_find_net(string n)
{
	
}

// same as add_find_net but for gates
// gtype is the enum value of the gate type
Gate* Design::add_find_gate(int gtype, string n)
{
	
}

// allocates and creates a new vector of pointers to the PI Nets
vector<Net *> * Deisgn::get_pi_nets()
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
