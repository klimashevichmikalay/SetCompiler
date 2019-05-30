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
	string name;

public:

	int getCurLine();
	void setName(string _name);
	void setVariables(map<string, BaseClass*>& _variables);
	vector<Function*> getFunctions();
	void setFunctions(vector<Function*> _functions);
	void setCurLine(int i);
	map <lineType, ICommand*> getCommands();
	void setCommands(map <lineType, ICommand*> _commands);
	type getType();
	map<string, BaseClass*> &getVariables();
	Function* getFunction(Function* f);
	Function();
	void execute();
	void clearVariables();	
	vector<string> splitHeader(string str);
	void setInfo(string _header, type _t);
	void setCode(vector<string> _code);
	vector<string> getCode();	
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
	void setParameters(map<string, type> &_parameters);
	bool isAlreadyExists(string name);
	
};

class ICommand
{
public:

	virtual void executeInstruction(vector<Function*> functions, map<string, BaseClass*> variables, string instruction, Function* curFunction) = 0;
};
