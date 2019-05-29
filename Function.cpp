#include "Function.h"

Function::Function() {};

void Function::execute()
{
	cout << "\nexecute in " << this->name << " in file " << this->file;
}

bool Function::operator==(Function _f)
{
	if (this->name != _f.getName() || this->parameters.size() != _f.parameters.size())
		return false;

	int sets = 0, els = 0;
	
	for (auto& item : this->parameters)
		(item.second == BaseClass::ELEMENT) ? els++ : sets++;

	for (auto& item : _f.parameters)
		(item.second == BaseClass::ELEMENT) ? els-- : sets--;	

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

void Function::setInfo(string _header, BaseClass::type _t)
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
			parameters.insert(pair<string, BaseClass::type>(header[i + 1], BaseClass::SET));
		else if (header[i] == "Element")
			parameters.insert(pair<string, BaseClass::type>(header[i + 1], BaseClass::ELEMENT));
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

vector<string> Function::getCode()
{
	return this->code;
}

BaseClass::type Function::getType()
{
	return retType;
}

string Function::getName()
{
	return name;
}

void Function::clearVariables()
{
	variables.clear();
}

BaseClass* Function::getVariable(string name)
{
	return variables.find(name)->second;
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

map<string, BaseClass::type> Function::getParameters()
{
	return parameters;
}