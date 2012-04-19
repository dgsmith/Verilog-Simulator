#include "global.h"
#include <iostream>
#include <cassert>
#include "design.h"
#include "parser.h"

using namespace std;

void test_design()
{
	Design *aDesign;
	aDesign = parseThatShit("test.v");
}

void test_gates()
{
  Net *i1 = new Net("i1");
  Net *i2 = new Net("i2");
  Net *o = new Net("output");
  
  Gate *g = new And("uut", 5);
  
  i1->addLoad(g);
  i2->addLoad(g);
  o->addDriver(g);
  
  i1->printDriversLoads();
  i2->printDriversLoads();
  o->printDriversLoads();
  
  g->addInput(i1);
  g->addInput(i2);
  g->addOutput(o);
  
  g->dump(cout);
}

void test_net()
{
  Net n("test");
  assert(n.name() == "test");
  assert(n.getVal() == 'X');
  
  n.setVal('0');
  assert(n.getVal() == '0');
  n.setVal('X');
  
  
}

void test_parser()
{
  
}

int main (int argc, char const *argv[])
{
  //test_net();
  test_gates();
  
	

  cout << GREEN << "Tests completed." << RESET << endl;
  return 0;
}