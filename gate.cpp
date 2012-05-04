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
  delay = 0;
}

Gate::Gate(string n, int d)
{
  inputs = new vector<Net*>();
  output = NULL;
  
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
}

And::And(string n, int d) : Gate(n,d)
{
	inst_name = n;
	delay = d;
}

char And::eval()
{
	char val;
	if((int) inputs->size() == 1)	{
		switch(inputs->front()->getVal())
		{
			case 'X':
			{
				val = inputs->front()->getVal();
        break;
			}
			case '0':
			{
				val = inputs->front()->getVal();
        break;
			}
			case '1':
			{
				val = inputs->front()->getVal();
        break;
			}
		}
	}
	else	{
		vector<Net*>::iterator it = inputs->begin();
		val = (*it)->getVal();
		it++;
		for(;it != inputs->end(); it++)
		{
			switch((*it)->getVal())
			{
				case 'X':
				{
					if((val == 'X') | (val == '1'))	{
						val = 'X';
					}
					else if(val == '0')	{
						val = '0';
					}
					else {
						//error in val
					}
					break;
				}
				case '0':
				{
					val = '0';
					break;
				}
				case '1':
				{
					// nothing needed to do
					break;
				}
				default:
				{
					// something wrong...
					break;
				}
			}
		}
	}
	return val;
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
}

Or::Or(string n, int d)  : Gate(n,d)
{
	inst_name = n;
	delay = d;
}

char Or::eval()
{
	char val;
	if((int) inputs->size() == 1)	{
		switch(inputs->front()->getVal())
		{
			case 'X':
			{
				val = inputs->front()->getVal();
        break;
			}
			case '0':
			{
				val = inputs->front()->getVal();
        break;
			}
			case '1':
			{
				val = inputs->front()->getVal();
        break;
			}
		}
	}
	else	{
		vector<Net*>::iterator it = inputs->begin();
		val = (*it)->getVal();
		it++;
		for(;it != inputs->end(); it++)
		{
			switch((*it)->getVal())
			{
				case 'X':
				{
					if((val == 'X') | (val == '0'))	{
						val = 'X';
					}
					else if(val == '1')	{
						val = '1';
					}
					else {
						//error in val
					}
					break;
				}
				case '0':
				{
					// nothing needed to do
					break;
				}
				case '1':
				{
					val = '1';
					break;
				}
				default:
				{
					// something wrong...
					break;
				}
			}
		}
	}
	return val;
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
}

Nor::Nor(string n, int d) : Gate(n,d)
{
	inst_name = n;
	delay = d;
}

char Nor::eval()
{
	char val;
	if((int) inputs->size() == 1)	{
		switch(inputs->front()->getVal())
		{
			case 'X':
			{
				val = inputs->front()->getVal();
        break;
			}
			case '0':
			{
				val = inputs->front()->getVal();
        break;
			}
			case '1':
			{
				val = inputs->front()->getVal();
        break;
			}
		}
	}
	else	{
		vector<Net*>::iterator it = inputs->begin();
		val = (*it)->getVal();
		it++;
		for(;it != inputs->end(); it++)
		{
			switch((*it)->getVal())
			{
				case 'X':
				{
					if((val == 'X') | (val == '0'))	{
						val = 'X';
					}
					else if(val == '1')	{
						val = '1';
					}
					else {
						//error in val
					}
					break;
				}
				case '0':
				{
					// nothing needed to do
					break;
				}
				case '1':
				{
					val = '1';
					break;
				}
				default:
				{
					// something wrong...
					break;
				}
			}
		}
	}
	return val;
  
  // Now invert
  if(val == '1')
    return '0';
  else if(val == '0')
    return '1';
  else
  	return val;
  
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
}

Nand::Nand(string n, int d) : Gate(n,d)
{
	inst_name = n;
	delay = d;
}

char Nand::eval()
{
	char val;
	if((int) inputs->size() == 1)	{
		switch(inputs->front()->getVal())
		{
			case 'X':
			{
				val = inputs->front()->getVal();
        break;
			}
			case '0':
			{
				val = inputs->front()->getVal();
        break;
			}
			case '1':
			{
				val = inputs->front()->getVal();
        break;
			}
		}
	}
	else	{
		vector<Net*>::iterator it = inputs->begin();
		val = (*it)->getVal();
		it++;
		for(;it != inputs->end(); it++)
		{
			switch((*it)->getVal())
			{
				case 'X':
				{
					if((val == 'X') | (val == '1'))	{
						val = 'X';
					}
					else if(val == '0')	{
						val = '0';
					}
					else {
						//error in val
					}
					break;
				}
				case '0':
				{
					val = '0';
					break;
				}
				case '1':
				{
					// nothing needed to do
					break;
				}
				default:
				{
					// something wrong...
					break;
				}
			}
		}
	}
  
  // Now invert
  if(val == '1')
    return '0';
  else if(val == '0')
    return '1';
  else
  	return val;
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
}

Xor::Xor(string n, int d) : Gate(n,d)
{
	inst_name = n;
	delay = d;
}

char Xor::eval()
{
	char val;
	if((int) inputs->size() == 1)	{
		switch(inputs->front()->getVal())
		{
			case 'X':
			{
				val = inputs->front()->getVal();
        break;
			}
			case '0':
			{
				val = inputs->front()->getVal();
        break;
			}
			case '1':
			{
				val = '0';
        break;
			}
		}
	}
	else	{
		vector<Net*>::iterator it = inputs->begin();
		val = (*it)->getVal();
		it++;
		for(;it != inputs->end(); it++)
		{
			switch((*it)->getVal())
			{
				case 'X':
				{
					val = 'X';
					break;
				}
				case '0':
				{
					// nothing to do here
					break;
				}
				case '1':
				{
					if (val == 'X')	{
						// do nothing
					}
					else if(val == '0')	{
						val = '1';
					}
					else if(val == '1')	{
						val = '0';
					}
					break;
				}
				default:
				{
					// something wrong...
					break;
				}
			}
		}
	}
	return val;
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
}

Not::Not(string n, int d) : Gate(n,d)
{
	inst_name = n;
	delay = d;
}

char Not::eval()
{
	char val;
	if((int) inputs->size() == 1)	{
		switch(inputs->front()->getVal())
		{
			case 'X':
			{
				val = inputs->front()->getVal();
        break;
			}
			case '0':
			{
				val = '1';
        break;
			}
			case '1':
			{
				val = '0';
        break;
			}
		}
	}
	else	{
		vector<Net*>::iterator it = inputs->begin();
		val = (*it)->getVal();
		it++;
		for(;it != inputs->end(); it++)
		{
			switch((*it)->getVal())
			{
				case 'X':
				{
					val = 'X';
					break;
				}
				case '0':
				{
					if((val == 'X') | (val == '1'))	{
						val = 'X';
					}
					else if(val == '0')	{
						val = '1';
					}
					break;
				}
				case '1':
				{
					if((val == 'X') | (val == '0'))	{
						val = 'X';
					}
					else if(val == '1')	{
						val = '0';
					}
					break;
				}
				default:
				{
					// something wrong...
					break;
				}
			}
		}
	}
	return val;
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
