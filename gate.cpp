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
	
}
