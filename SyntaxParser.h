#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream> 
#include <algorithm>
#include "CheckSyntax.h"


using namespace std;
using namespace regConstants;

class SyntaxParser
{
private:

	bool result;

public:

	SyntaxParser();
	std::vector<std::string> getFileContent(std::string _path);
	vector<string>  eraseSpaces(vector<string> v);
	vector<string> split(string str, char delimiter);
	bool checkSyntaxInFile(string _path);
};
