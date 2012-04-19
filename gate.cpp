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
	inputs = new vector<Net *>;
	output = new Net;
}

Gate::Gate(string n, int d)
{
	inst_name = n;
	delay = d;
	inputs = new vector<Net *>;
	output = new Net;
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
	if(delay == 0)	{
		return 1;
	}
	else {
		return delay;
	}
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
	delay = 0;
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
  if(delay == 0)	{
		os << "and " << inst_name;
	}
	else {
		os << "and #" << delay << " " << inst_name;
	}
	
  dumpNetList(os);
  
  os << ");" << endl;
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
	delay = 0;
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
  if(delay == 0)	{
		os << "or " << inst_name;
	}
	else {
		os << "or #" << delay << " " << inst_name;
	}
  
  dumpNetList(os);
  
  os << ");" << endl;
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
	delay = 0;
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
  if(delay == 0)	{
		os << "nor " << inst_name;
	}
	else {
		os << "nor #" << delay << " " << inst_name;
	}
  
  dumpNetList(os);
  
  os << ");" << endl;
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
	delay = 0;
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
  if(delay == 0)	{
		os << "nand " << inst_name;
	}
	else {
		os << "nand #" << delay << " " << inst_name;
	}
  
  dumpNetList(os);
  
  os << ");" << endl;
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
	delay = 0;
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
  if(delay == 0)	{
		os << "xor " << inst_name;
	}
	else {
		os << "xor #" << delay << " " << inst_name;
	}
  
  dumpNetList(os);
  
  os << ");" << endl;
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
	delay = 0;
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
  if(delay == 0)	{
		os << "not " << inst_name;
	}
	else {
		os << "not #" << delay << " " << inst_name;
	}
  
  dumpNetList(os);
  
  os << ");" << endl;
}
