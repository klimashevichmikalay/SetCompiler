#include "Function.h"
#include "CheckSyntax.h"
Function::Function() 
{
	this->returnedValueName = "";
};

void Function::execute()
{	
	for (int i = 0; i < code.size(); i++)
	{
		curLine = i;
		lineType lt = (lineType)checkLine(code[i]);
		if (lt == EMPTY || lt == RET || lt == OPENBR || lt == CLOSEBR)
			continue;
		commands.find(lt)->second->executeInstruction(functions, variables, code[i], this);	
		i = curLine;
	}	
}

void Function::setParameters(map<string, type> &_parameters)
{
	this->parameters = _parameters;
}

int Function::getCurLine()
{
	return this->curLine;
}

void Function::setName(string _name)
{
	this->name = _name;
}

void Function::setVariables(map<string, BaseClass*>& _variables)
{
	this->variables = _variables;
}

vector<Function*> Function::getFunctions()
{
	return this->functions;
}

void Function::setFunctions(vector<Function*> _functions)
{
	this->functions = _functions;
}

void Function::setCurLine(int i)
{
	this->curLine = i;
}

map <lineType, ICommand*> Function::getCommands()
{
	return this->commands;
}

void Function::setCommands(map <lineType, ICommand*> _commands)
{
	this->commands = _commands;
}

type Function::getType()
{
	return retType;
}

map<string, BaseClass*> &Function::getVariables()
{
	return this->variables;
}

Function* Function::getFunction(Function* f)
{
	for (int j = 0; j < functions.size(); j++)
	{
		if ((*f) == (*functions[j]))
		 return	functions[j];
	}
	return nullptr;
}

bool Function::operator==(Function _f)
{
	if (this->name != _f.getName() || this->parameters.size() != _f.parameters.size())
		return false;

	int sets = 0, els = 0;
	
	for (auto& item : this->parameters)
		(item.second == ELEMENT) ? els++ : sets++;

	for (auto& item : _f.parameters)
		(item.second == ELEMENT) ? els-- : sets--;	

	if (sets != 0 | els != 0)
		return false;

	return true;
}

vector<string> Function::splitHeader(string str)
{
	std::replace(str.begin(), str.end(), '(', ' ');
	std::replace(str.begin(), str.end(), ')', ' ');
	std::replace(str.begin(), str.end(), ',', ' ');
	SyntaxParser sp;
	return  sp.split(str, ' ');
}

bool Function::isAlreadyExists(string name)
{  
	if (variables.size() == 0)
		return false;

	if (variables.find(name) != variables.end())
		return true;

	return false;
}


void Function::setInfo(string _header, type _t)
{
	int shift = 2;
	if (_t) shift++;
	retType = _t;
	vector<string> header = splitHeader(_header);
	name = header[shift - 1];

	if (header.size() < 4)
		return;

	if ((header.size() - shift) % 2 != 0)
	{
		cout << "\nError in parameters in function " << "\"" << _header << "\":" << 
			"\ntype or name of parameter is not specified.";
		cin.get();
		exit(0);		
	}

	for (int i = shift; i < header.size(); i += 2)
	{
		if (header[i] == "Set")
			parameters.insert(pair<string, type>(header[i + 1], SET));
		else if (header[i] == "Element")
			parameters.insert(pair<string, type>(header[i + 1], ELEMENT));
		else
		{
			cout << "\nError: unknown type in function " << "\"" << _header << "\"." <<
				"\nValid Types: Set, Element.";
			cin.get();
			exit(0);
		}
	}
}

void Function::setCode(vector<string> _code)
{
	this->code = _code;
}

void Function::setReturnedName()
{
	for (int i = 0; i < this->code.size(); i++)
	{
	
		lineType line = (lineType)checkLine(code[i]);
		if (RET == line)
		{
			SyntaxParser sp;
			this->returnedValueName = sp.split(code[i], ' ')[1];
			break;
		}
	}
}

vector<string> Function::getCode()
{
	return this->code;
}

string Function::getName()
{
	return name;
}

void Function::clearVariables()
{
	variables.clear();
}

BaseClass*  Function::getReturnedValue()
{
	return variables.find(returnedValueName)->second;
}

BaseClass*  Function::getVariable(string str)
{
	return variables.find(str)->second;
}

void Function::setFile(string _path)
{
	this->file = _path;
}
void Function::setStartLine(int _line)
{
	this->startLine = _line;
}

string Function::getFile()
{
	return this->file;
}

int Function::getStartLine()
{
	return this->startLine;
}

map<string, type> Function::getParameters()
{
	return parameters;
}