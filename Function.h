#pragma once
#include <stdlib.h>
#include <iostream>
#include <string>
#include <vector>
#include <map> 
#include <algorithm>
#include "BaseClass.h"
#include "SyntaxParser.h"

using namespace std;

class Function
{
private:

	BaseClass::type retType;//+
	string name;//+
	string file;//+
	map<string, BaseClass*> variables;//-
	vector<string> code;//-
	map<string, BaseClass::type> parameters;//+
	int startLine;//+

public:

	Function();
	void execute();
	void clearVariables();
	vector<string> splitHeader(string str);
	void setInfo(string _header, BaseClass::type _t);
	void setCode(vector<string> _code);
	vector<string> Function::getCode();
	BaseClass::type getType();
	string getName();
	void setFile(string _path);	
	void setStartLine(int _line);
	BaseClass* getVariable(string name);
	string getFile();
	map<string, BaseClass::type> getParameters();
	int getStartLine();
	bool operator==(Function f);
};





