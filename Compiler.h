#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <map> 
#include <algorithm>
#include "BaseClass.h"
#include "SyntaxParser.h"
#include "Function.h"
#include "RegexConstants.h"


using namespace std;

class Compiler
{
private:

	SyntaxParser sp;
	vector<Function*> functions;
	map <lineType, ICommand*> commands;

public:

	Compiler();
	void setCommands();
	void compile(string _path);
	Function *isMainGood();
	bool isDuplicatesPrototypes();
	int addCode(Function* _newFunc, vector<string> _vecOfStrs, int _curLine);
	void formFunctions(string _path);
};