#include "Function.h";
#include "Element.h";
#include "Set.h";
using namespace std;

class Erase : public ICommand
{
public:
	void executeInstruction(vector<Function*> functions, map<string, BaseClass*> variables, string instruction, Function* curFunction)
	{//
		SyntaxParser sp;
		if (!curFunction->isAlreadyExists((sp.split(instruction, ' ')[0])) ||
			!curFunction->isAlreadyExists((sp.split(instruction, ' ')[2])))
		{
			cout << "\nError in erase vars in function \"" << curFunction->getName() << "\" in file: " <<
				curFunction->getFile() << "\nvar(s) is not initialized.";
			return;
		}

		if ((curFunction->getVariable((sp.split(instruction, ' '))[0])->getType()) != SET)
		{
			cout << "\nError in erase vars in function \"" << curFunction->getName() << "\" in file: " <<
				curFunction->getFile() << "\nELement can not erase.";
			return;
		}		
		((Set*)curFunction->getVariable((sp.split(instruction, ' '))[0]))->erase((curFunction->getVariable((sp.split(instruction, ' '))[2])));
	}
};