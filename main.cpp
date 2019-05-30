#include <iostream>
#include <string>
#include "tests.h"
#include "Compiler.h"

using namespace std;

int main()
{
	//startTests();

  Compiler comp;
  comp.compile("programExample/main.txt");

	cin.get();
	cin.get();
	return 0;
}

