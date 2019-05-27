#include <iostream>
#include <iostream>
#include <string>
#include <regex>
#include <vector>
#include <sstream> 
#include "tests.h"
#include "SyntaxParser.h"
#include "RegexConstants.h"

using namespace std;

vector<string> split(string str, char delimiter);
void startTests();
int ckeckSet(string str);
vector<string> eraseSpaces(vector<string> v);

int main()
{
//	startTests();	

	SyntaxParser sp;
	if (sp.checkSyntaxInFile("file.txt"))
	{
		cout << "\nSucces pars";
	}
	else {
		cout << "\nFail pars";
	}
	
	cin.get();
	cin.get();
	return 0;
}

vector<string>  eraseSpaces(vector<string> v)
{
	vector<string> res;
	for (int i = 0; i < v.size(); i++)
		if (v[i] != "")
			res.push_back(v[i]);

	return res;
}

vector<string> split(string str, char delimiter) {
	//vector<string> v = split("   include       file.txt", ' ');
	vector<string> internal;
	stringstream ss(str);
	string tok;
	while (getline(ss, tok, delimiter)) {
		internal.push_back(tok);
	}
	return  eraseSpaces(internal);
}

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