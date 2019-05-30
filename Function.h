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
	string file;
	string returnedValueName;
	map<string, BaseClass*> variables;
	vector<string> code;
	map<string, type> parameters;
	int startLine;
	vector<Function*> functions;
	map <lineType, ICommand*> commands;
	int curLine;

public:

	int getCurLine()
	{
		return this->curLine;
	}

	void setName(string _name)
	{
		this->name = _name;
	}

	void setVariables(map<string, BaseClass*>& _variables)
	{
		this->variables = _variables;
	}

	vector<Function*> getFunctions()
	{
		return this->functions;
	}

	void setFunctions(vector<Function*> _functions)
	{
		this->functions = _functions;
	}

	string name;
	Function();
	void execute();
	void clearVariables();

	void setCurLine(int i)
	{
		this->curLine = i;
	}

	map <lineType, ICommand*> getCommands()
	{
		return this->commands;
	}

	void setCommands(map <lineType, ICommand*> _commands)
	{
		this->commands = _commands;
	}
	vector<string> splitHeader(string str);
	void setInfo(string _header, type _t);
	void setCode(vector<string> _code);
	vector<string> getCode();
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
	void setReturnedName();
	bool isAlreadyExists(string name);
	map<string, BaseClass*> &getVariables()
	{
		return this->variables;
	}

	Function* getFunction(Function* f)
	{
		for (int j = 0; j < this->functions.size(); j++)
			if ((*f) == (*functions[j]))
				functions[j];
		return nullptr;
	}
};

class ICommand
{
public:

	virtual void executeInstruction(vector<Function*> functions, map<string, BaseClass*> variables, string instruction, Function* curFunction) = 0;
};
