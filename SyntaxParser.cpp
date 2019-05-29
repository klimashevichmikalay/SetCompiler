#include "SyntaxParser.h"

SyntaxParser::SyntaxParser()
{
	result = true;
}

std::vector<std::string> SyntaxParser::getFileContent(std::string _path)
{
	std::vector<std::string>  vecOfStrs;
	std::ifstream in(_path.c_str());
	if (!in)
	{
		cout << endl << "Cannot open the File : " << _path << ".";
		return vecOfStrs;
	}

	std::string str;
	while (std::getline(in, str))			
			vecOfStrs.push_back(str);
	
	in.close();
	return vecOfStrs;
}

vector<string>  SyntaxParser::eraseSpaces(vector<string> v)
{
	vector<string> res;
	for (int i = 0; i < v.size(); i++)
		if (v[i] != "")
			res.push_back(v[i]);

	return res;
}

vector<string> SyntaxParser::split(string str, char delimiter)
{
	vector<string> internal;
	stringstream ss(str);
	string tok;
	while (getline(ss, tok, delimiter)) {
		internal.push_back(tok);
	}
	return  eraseSpaces(internal);
}


bool SyntaxParser::checkSyntaxInFile(string _path)
{
	std::vector<std::string>  vecOfStrs = getFileContent(_path);
	if (vecOfStrs.empty())
	{
		cout << "\nWarning: file " << _path << " is empty or missing.";
		return false;
	}

	for (int i = 0; i < vecOfStrs.size(); i++)
	{
		if (FALSE == checkLine(vecOfStrs[i]))
		{
			cout << "\nError: Syntax error in file " << _path << " at line " << i + 1 << ".";
			result = false;
		}

		if (INC == checkLine(vecOfStrs[i]))
			checkSyntaxInFile(split(vecOfStrs[i], ' ')[1]);
	}
	return result;
}