/**
* PA5 Part 1
* Chris Li, Grayson Smith
*/
#include "global.h"
#include <iostream>
#include "parser.h"

int main (int argc, char const *argv[])
{
  LOG("Parsing and dumping test.v");
	Design *aDesign;
	aDesign = parseThatShit("test.v");
  
  LOG("Parsing and dumping test2.v");
  aDesign = parseThatShit("test2.v");
  return 0;
}