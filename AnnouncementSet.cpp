#pragma once
#include "AnnouncementSet.h";
#include "Set.h";
void AnnouncementSet::executeInstruction(vector<Function*> functions, map<string, BaseClass*> variables, string instruction, Function* curFunction)
{
	SyntaxParser sp;
	//m.find("f") == m.end()
	if (curFunction->isAlreadyExists((sp.split(instruction, ' ')[1])))
	{
		cout << "\nError in announcement Set in function \"" <<  curFunction->getName() << "\" in file " <<
			curFunction->getFile() << ":\nname \"" << sp.split(instruction, ' ')[1] << "\" is already exists.";
		return;
	}
		
		Set* set = new Set();
		curFunction->getVariables().insert(pair<string, Set*>((sp.split(instruction, ' ')[1]), set));
}