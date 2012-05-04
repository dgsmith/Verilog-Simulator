#include "global.h"
#include <iostream>
#include <cassert>
#include "design.h"
#include "parser.h"
#include "logicsim.h"

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

void test_delay()
{
  /*
  i1-\
      | g1 )---o1--\
  i2-/               - | g3 )---output
  i3-\               /
      | g2 )---o2--/
  i4-/
  */
  Net *i1 = new Net("i1");
  Net *i2 = new Net("i2");
  Net *i3 = new Net("i3");
  Net *i4 = new Net("i4");
  
  Net *o1 = new Net("o1");
  Net *o2 = new Net("o2");
  Net *output = new Net("output");
  
  Gate *g1 = new And("and", 5);
  Gate *g2 = new Or("or", 10);
  Gate *g3 = new Xor("xor", 3);
  
  i1->addLoad(g1);
  i2->addLoad(g1);
  i3->addLoad(g2);
  i4->addLoad(g2);
  
  o1->addLoad(g3);
  o1->addDriver(g1);
  
  o2->addLoad(g3);
  o2->addDriver(g2);
  
  output->addDriver(g3);
  
  g1->addInput(i1);
  g1->addInput(i2);
  g1->addOutput(o1);
  
  g2->addInput(i3);
  g2->addInput(i4);
  g2->addOutput(o2);
  
  g3->addInput(o1);
  g3->addInput(o2);
  g3->addOutput(output);
  
  cout << "o1 " << o1->computeDelay() << endl;
  cout << "o2 " << o2->computeDelay() << endl;
  cout << "output " << output->computeDelay() << endl;
}

void test_simulation()
{
  Design *design = parseThatShit("adder4.v");
  LogicSim sim("adder4.sim");
  
}

int main (int argc, char const *argv[])
{
  //test_net();
  // test_gates();
  // test_delay();
  test_simulation();
	

  cout << GREEN << "Tests completed." << RESET << endl;
  return 0;
}