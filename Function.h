#pragma once
#include <stdlib.h>
#include <iostream>
#include <string>
#include <vector>
#include <map> 
#include <algorithm>
#include "BaseClass.h"
#include "SyntaxParser.h"
#include "RegexConstants.h"


using namespace regConstants;
using namespace std;

class ICommand;

class Function
{
private:

	type retType;
	string name;
	string file;
	string returnedValueName;
	map<string, BaseClass*> variables;//-
	vector<string> code;
	map<string, type> parameters;
	int startLine;
	vector<Function*> functions;
	map <lineType, ICommand*> commands;

public:

	Function();
	void execute();
	void clearVariables();
	void setCommands(map <lineType, ICommand*> _commands)
	{
		this->commands = _commands;
	}
	vector<string> splitHeader(string str);
	void setInfo(string _header, type _t);
	void setCode(vector<string> _code);
	vector<string> Function::getCode();
	type getType()
	{
		return retType;
	}
	string getName();
	BaseClass*  getReturnedValue();
	BaseClass*  getVariable(string str);
	void setFile(string _path);
	void setStartLine(int _line);
	string getFile();
	map<string, type> getParameters();
	int getStartLine();
	bool operator==(Function f);
	void setFunctions(vector<Function*> _functions);
	void setReturnedName();
};

class ICommand
{
public:

	virtual void executeInstruction(std::vector<Function*> functions, map<string, BaseClass*> variables, string instruction) = 0;
};
