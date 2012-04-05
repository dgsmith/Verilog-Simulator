#include "gates.h"
using namespace std;

//===================================================================//
// GATES CLASS
//
//
//
//===================================================================//
Gates::Gate()
{
	inst_name = "default name";
	delay = 1;
	output = NULL;
}

Gates::Gate(string n, int d)
{
	inst_name = n;
	delay = d;
	output = NULL;
}

string Gates::name()
{
	return inst_name;
}

void Gates::addInput(Net *n)
{
	Net *newNet = new Net(n);
	inputs.push(newNet);
}

void Gates::addOutput(Net *n)
{
	if(output == NULL)
	{
		Net newOut = new Net(n);
		output = newOut;
	}
	else // trying to assign more than one input!
		
}

vector<Net *> * Gates::getInputs()
{
	return inputs;
}

Net* Gates::getOutput()
{
	return output;
}

int Gates::getNumInputs()
{
	return (int) inputs.size();
}

int Gates::getDelay()
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
	output = NULL;
}

And::And(string n, int d);
{
	
}

char And::eval()
{
	
}

void And::dump(ostream &os)
{
	
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

Or::Or(string n, int d);
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

Nor::Nor(string n, int d);
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

Nand::Nand(string n, int d);
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

Xor::Xor(string n, int d);
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

Not::Not(string n, int d);
{
	
}

char Not::eval()
{
	
}

void Not::dump(ostream &os)
{
	
}
