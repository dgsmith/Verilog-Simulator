/**
* PA5 Part 1
* Chris Li, Grayson Smith
*/
#include "global.h"
#include <iostream>
#include <fstream>
#include "parser.h"

using namespace std;

void dumpToFile(string filename, Design* aDesign)
{
  ofstream outfile(filename.c_str());
  
  outfile.close();
}

int main (int argc, char const *argv[])
{
  LOG("Parsing and dumping test.v");
	Design *a;
	a = parseThatShit("test.v");
  dumpToFile("test.v.out", a);
  
  LOG("Parsing and dumping test2.v");
  a = parseThatShit("test2.v");
  dumpToFile("test2.v.out", a);
  
  return 0;
}