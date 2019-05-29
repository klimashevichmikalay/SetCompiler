#pragma once
#include "CommandPrintText.h";

void CommandPrintText::executeInstruction(vector<Function*> functions, map<string, BaseClass*> variables, string instruction, Function* curFunction)
{	
	SyntaxParser sp;
	cout << endl << (sp.split(instruction, '\'')[1]) << endl;
}