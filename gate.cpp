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
	inst_name = "default name";
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

//===================================================================//
// AND CLASS
//
//
//
//===================================================================//
And::And()
{
	inst_name = "default AND";
	delay = 1;
}

And::And(string n, int d)
{
	
}

char And::eval()
{
	
}

void And::dump(ostream &os)
{
  LOG("Dump");
  os << "and #" << delay << " ";// << inst_name;// << "(" << output->name() << ", ";
  LOG("WHY");
  
  for(vector<Net*>::iterator i=inputs->begin(); i!=inputs->end(); i++)
  {
    // LOG(*i);
    // os << (*i)->name();
    // if(i+1 != inputs->end())
    //   os << ",";
  }
  LOG("Ok");
  
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
	
}

Or::Or(string n, int d)
{
	
}

char Or::eval()
{
	
}

void Or::dump(ostream &os)
{
	
}
//===================================================================//
// NOR CLASS
//
//
//
//===================================================================//
Nor::Nor()
{
	
}

Nor::Nor(string n, int d)
{
	
}

char Nor::eval()
{
	
}

void Nor::dump(ostream &os)
{
	
}
//===================================================================//
// NAND CLASS
//
//
//
//===================================================================//
Nand::Nand()
{
	
}

Nand::Nand(string n, int d)
{
	
}

char Nand::eval()
{
	
}

void Nand::dump(ostream &os)
{
	
}
//===================================================================//
// XOR CLASS
//
//
//
//===================================================================//
Xor::Xor()
{
	
}

Xor::Xor(string n, int d)
{
	
}

char Xor::eval()
{
	
}

void Xor::dump(ostream &os)
{
	
}
//===================================================================//
// NOT CLASS
//
//
//
//===================================================================//
Not::Not()
{
	
}

Not::Not(string n, int d)
{
	
}

char Not::eval()
{
	
}

void Not::dump(ostream &os)
{
	
}
