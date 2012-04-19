#include "global.h"
#include <iostream>
#include "parser.h"

int main (int argc, char const *argv[])
{
  LOG("Hi");
	Design *aDesign;
	aDesign = parseThatShit("test2.v");
  LOG("BYE");
  return 0;
}