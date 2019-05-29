#pragma once
#include "CommandPrintText.h";

void CommandPrintText::executeInstruction(vector<Function*> functions, map<string, BaseClass*> variables, string instruction)
{	
	SyntaxParser sp;
	cout << (sp.split(instruction, '\'')[1]);	
	cin.get();
	cin.get();

}