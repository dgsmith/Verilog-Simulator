#include "global.h"
#include <iostream>
#include <cassert>
#include "design.h"
#include "parser.cpp"
using namespace std;

void test_design()
{
  
}

void test_gates()
{
  
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
	Design *aDesign;
	aDesign = parseThatShit("test.v");
	

  cout << GREEN << "Tests completed." << RESET << endl;
  return 0;
}