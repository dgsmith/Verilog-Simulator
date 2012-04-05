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
	
}

Gates::Gate(string n, int d)
{
	
}

string Gates::name()
{
	
}

void Gates::addInput(Net *n)
{
	
}

void Gates::addOutput(Net *n)
{
	
}

vector<Net *> * Gates::getInputs()
{
	
}

Net* Gates::getOutput()
{
	
}

int Gates::getNumInputs()
{
	
}

int Gates::getDelay()
{
	
}

//===================================================================//
// AND CLASS
//
//
//
//===================================================================//
And::And()
{
	
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
