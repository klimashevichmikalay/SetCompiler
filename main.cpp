#include <iostream>
#include <iostream>
#include <string>
#include <regex>
#include "tests.h"
#include "CheckSyntax.h"
#include "RegexConstants.h"

using namespace std;
using namespace std::regex_constants;

void startTests();
int ckeckSet(string str);

int main()
{
	startTests();

	//cout << ckeckSet("Set set;");

	cin.get();
	cin.get();
	return 0;
}

//

void startTests()
{
	cout << "\nStart tests...\n";

	int i = 0;
	
	while (tests[i] != NULL)
	{
		tests[i]();
		i++;
	}

	cout << "\n\nEnd tests...\n";
}

int ckeckSet(string str)
{
	std::regex e(regConstants::announcementSet);
	if (std::regex_match(str, e))
		return regConstants::ANNSET;
	return regConstants::FALSE;
}