#include "gate.h"
using namespace std;

//===================================================================//
// GATES CLASS
//
//
//
//===================================================================//
Gate::Gate()
{
	inst_name = "Gate";
	delay = 1;
}

Gate::Gate(string n, int d)
{
	inst_name = n;
	delay = d;
}

string Gate::name()
{
	return inst_name;
}

void Gate::addInput(Net *n)
{
	inputs->push_back(n);
}

void Gate::addOutput(Net *n)
{

	output = n;

}

vector<Net *> * Gate::getInputs()
{
	return inputs;
}

Net* Gate::getOutput()
{
	return output;
}

int Gate::getNumInputs()
{
	return (int) inputs->size();
}

int Gate::getDelay()
{
	return delay;
}

void Gate::dumpNetList(ostream& os)
{
  os << "(" << output->name() << ", ";
  for(vector<Net*>::iterator i=inputs->begin(); i!=inputs->end(); i++)
  {
    os << (*i)->name();
    if(i+1 != inputs->end())
      os << ", ";
  }
}

//===================================================================//
// AND CLASS
//
//
//
//===================================================================//
And::And()
{
	inst_name = "AND";
	delay = 1;
	inputs = new vector<Net *>;
	output = new Net;
}

And::And(string n, int d)
{
	inst_name = n;
	delay = d;
	inputs = new vector<Net *>;
	output = new Net;
}

char And::eval()
{
	
}

void And::dump(ostream &os)
{
  os << "and #" << delay << " " << inst_name;
  
  dumpNetList(os);
  
  cout << ");" << endl;
}
//===================================================================//
// OR CLASS
//
//
//
//===================================================================//
Or::Or()
{
	inst_name = "OR";
	delay = 1;
	inputs = new vector<Net *>;
	output = new Net;
}

Or::Or(string n, int d)
{
	inst_name = n;
	delay = d;
	inputs = new vector<Net *>;
	output = new Net;
}

char Or::eval()
{
	
}

void Or::dump(ostream &os)
{
  os << "or #" << delay << " " << inst_name;
  
  dumpNetList(os);
  
  cout << ");" << endl;
}
//===================================================================//
// NOR CLASS
//
//
//
//===================================================================//
Nor::Nor()
{
	inst_name = "NOR";
	delay = 1;
	inputs = new vector<Net *>;
	output = new Net;
}

Nor::Nor(string n, int d)
{
	inst_name = n;
	delay = d;
	inputs = new vector<Net *>;
	output = new Net;
}

char Nor::eval()
{
	
}

void Nor::dump(ostream &os)
{
  os << "nor #" << delay << " " << inst_name;
  
  dumpNetList(os);
  
  cout << ");" << endl;
}
//===================================================================//
// NAND CLASS
//
//
//
//===================================================================//
Nand::Nand()
{
	inst_name = "NAND";
	delay = 1;
	inputs = new vector<Net *>;
	output = new Net;
}

Nand::Nand(string n, int d)
{
	inst_name = n;
	delay = d;
	inputs = new vector<Net *>;
	output = new Net;
}

char Nand::eval()
{
	
}

void Nand::dump(ostream &os)
{
  os << "nand #" << delay << " " << inst_name;
  
  dumpNetList(os);
  
  cout << ");" << endl;
}
//===================================================================//
// XOR CLASS
//
//
//
//===================================================================//
Xor::Xor()
{
	inst_name = "XOR";
	delay = 1;
	inputs = new vector<Net *>;
	output = new Net;
}

Xor::Xor(string n, int d)
{
	inst_name = n;
	delay = d;
	inputs = new vector<Net *>;
	output = new Net;
}

char Xor::eval()
{
	
}

void Xor::dump(ostream &os)
{
  os << "xor #" << delay << " " << inst_name;
  
  dumpNetList(os);
  
  cout << ");" << endl;
}
//===================================================================//
// NOT CLASS
//
//
//
//===================================================================//
Not::Not()
{
	inst_name = "NOT";
	delay = 1;
	inputs = new vector<Net *>;
	output = new Net;
}

Not::Not(string n, int d)
{
	inst_name = n;
	delay = d;
	inputs = new vector<Net *>;
	output = new Net;
}

char Not::eval()
{
	
}

void Not::dump(ostream &os)
{
  os << "not #" << delay << " " << inst_name;
  
  dumpNetList(os);
  
  cout << ");" << endl;
}
