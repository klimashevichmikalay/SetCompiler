#include "Compiler.h"
#include "CommandPrintText.h"
#include "AnnouncementSet.h";
#include "AnnouncementElement.h";
#include "AssigmentElement.h";
#include "Assigment.h";
#include "Add.h";
#include "Erase.h";
#include "UnaryMinus.h";
#include "UnaryPlus.h";
#include "PrintVar.h";
#include "AssigmentOperation.h"
#include "IfPositive.h"
#include "IfNegation.h"
#include "ForClass.h"
#include "FuncDo.h"

Compiler::Compiler()
{
	setCommands();
};

void Compiler::setCommands()
{
	CommandPrintText*printtex = new CommandPrintText();	
	commands.insert(pair<lineType, CommandPrintText*>(PRINTTEXT, printtex));	

	AnnouncementSet *annset = new AnnouncementSet();
	commands.insert(pair<lineType, AnnouncementSet*>(ANNSET, annset));

	AnnouncementElement *annel = new AnnouncementElement();
	commands.insert(pair<lineType, AnnouncementElement*>(ANNEL, annel));
	//
	AssigmentElement *assel = new AssigmentElement();
	commands.insert(pair<lineType, AssigmentElement*>(ASSEL, assel));

	Assigment *ass = new Assigment();
	commands.insert(pair<lineType, Assigment*>(ASS, ass));	

	Add *add = new Add();
	commands.insert(pair<lineType, Add*>(ADD, add));

	Erase *erase = new Erase();
	commands.insert(pair<lineType, Erase*>(ERASE, erase));

	UnaryMinus *unmin = new UnaryMinus();
	commands.insert(pair<lineType, UnaryMinus*>(UNARYMINUS, unmin));

	UnaryPlus *unplus = new UnaryPlus();
	commands.insert(pair<lineType, UnaryPlus*>(UNARYPLUS, unplus));

	PrintVar *printvar = new PrintVar();
	commands.insert(pair<lineType, PrintVar*>(PRINTVAR, printvar));

	AssigmentOperation *assop = new AssigmentOperation();
	commands.insert(pair<lineType, AssigmentOperation*>(ASSOP, assop));

	IfPositive *ifpos = new IfPositive();
	commands.insert(pair<lineType, IfPositive*>(IF, ifpos));

	IfNegation *ifneg = new IfNegation();
	commands.insert(pair<lineType, IfNegation*>(IFNEGATION, ifneg));

	ForClass *fr = new ForClass();
	commands.insert(pair<lineType, ForClass*>(FOR, fr));

	FuncDo *fdo = new FuncDo();
	commands.insert(pair<lineType, FuncDo*>(FUNCDO, fdo));
	
}

void  Compiler::compile(string _path)
{
	if (!sp.checkSyntaxInFile(_path))
	{
		cout << "\nCompilation failed: file(s) has syntax error(s).";
		return;
	}

	formFunctions(_path);
	if (isDuplicatesPrototypes())
		return;
	Function *mainFunc = isMainGood();
	if (mainFunc == nullptr)
		return;

	for (int j = 0; j < this->functions.size(); j++)
	{
		functions[j]->setFunctions(functions);
	}

	mainFunc->execute();
}

Function *Compiler::isMainGood()
{
	for (int j = 0; j < this->functions.size(); j++)
		if (functions[j]->getName() == "main" &&
			functions[j]->getType() == VOID &&
			functions[j]->getParameters().size() == 0)
			return functions[j];

	cout << "\nError: there is no entry point to the program."
		<< "\nThe function \"main()\" should be of type void and have no parameters.";
	return nullptr;
}

bool Compiler::isDuplicatesPrototypes()
{
	for (int i = 0; i < this->functions.size(); i++)
		for (int j = i + 1; j < this->functions.size(); j++)
			if ((*functions[i]) == (*functions[j]))
			{
				cout << "\nError in file " << functions[i]->getFile() << " in function " <<
					functions[i]->getName() << "(announced at line " << functions[i]->getStartLine() << ")" <<
					": the function is duplicate.";
				return true;
			}
	return false;
}

int Compiler::addCode(Function* _newFunc, vector<string> _vecOfStrs, int _curLine)
{
	int countBr = -1;
	int endBody;
	int startBody;

	for (int i = _curLine + 1; i < _vecOfStrs.size() && countBr < 0; i++)
		if (OPENBR == checkLine(_vecOfStrs[i]))
		{
			countBr = 1;
			startBody = i;
		}

	if (countBr < 0)
	{
		cout << "\nError in file " << _newFunc->getFile() << " in function " <<
			_newFunc->getName() << "(announced at line " << _newFunc->getStartLine() << ")" <<
			": the function must have a body and the beginning of the body with braces.";
		return -1;
	}


	for (int i = startBody + 1; i < _vecOfStrs.size() && countBr != 0; i++)
	{
		if (OPENBR == checkLine(_vecOfStrs[i]))
			countBr++;

		if (CLOSEBR == checkLine(_vecOfStrs[i]))
			countBr--;

		endBody = i;
	}

	if (countBr != 0)
	{
		cout << "\nError in file " << _newFunc->getFile() << " in function " <<
			_newFunc->getName() << "(announced at line " << _newFunc->getStartLine() << ")" <<
			": the number of opening and closing curly brackets must be the same.";
		return -2;
	}

	vector<string>::const_iterator first = _vecOfStrs.begin() + startBody + 1;
	vector<string>::const_iterator last = _vecOfStrs.begin() + endBody;
	vector<string> funcBody(first, last);
	_newFunc->setCode(funcBody);

	return endBody;
}

void Compiler::formFunctions(string _path)
{
	using namespace regConstants;

	vector<string>  vecOfStrs = sp.getFileContent(_path);
	lineType line;

	for (int i = 0; i < vecOfStrs.size(); i++)
	{
		line = (lineType)checkLine(vecOfStrs[i]);
		if (INC == line)
		{
			formFunctions(sp.split(vecOfStrs[i], ' ')[1]);
			continue;
		}

		if ((FUNCVOID == line || FUNCSET == line || FUNCEL == line) && IF != line && IFNEGATION != line)
		{
			Function* newFunc = new Function();

			if (FUNCVOID == line)
				newFunc->setInfo(vecOfStrs[i], VOID);

			if (FUNCSET == line)
				newFunc->setInfo(vecOfStrs[i], SET);

			if (FUNCEL == line)
				newFunc->setInfo(vecOfStrs[i], ELEMENT);

			newFunc->setFile(_path);
			newFunc->setStartLine(i);

			int endFunc = addCode(newFunc, vecOfStrs, i);
			if (endFunc > 0)
			{
				newFunc->setReturnedName();
				newFunc->setCommands(this->commands);
				functions.push_back(newFunc);
				i = endFunc;
			}
			else return;
		}
	}
}