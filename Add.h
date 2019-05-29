#include "Function.h";
#include "Element.h";
#include "Set.h";
using namespace std;

class Add : public ICommand
{
public:
	void executeInstruction(vector<Function*> functions, map<string, BaseClass*> variables, string instruction, Function* curFunction)
	{//
		SyntaxParser sp;
		if (!curFunction->isAlreadyExists((sp.split(instruction, ' ')[0])) ||
			!curFunction->isAlreadyExists((sp.split(instruction, ' ')[2])))
		{
			cout << "\nError in added vars in function \"" << curFunction->getName() << "\" in file: " <<
				curFunction->getFile() << "\nvar(s) is not initialized.";
			return;
		}

		if ((curFunction->getVariable((sp.split(instruction, ' '))[0])->getType()) != SET)
		{
			cout << "\nError in added vars in function \"" << curFunction->getName() << "\" in file: " <<
				curFunction->getFile() << "\ncannot add to Element.";
			return;
		}	
		((Set*)curFunction->getVariable((sp.split(instruction, ' '))[0]))->add(((Set*)curFunction->getVariable((sp.split(instruction, ' '))[2])));
	}
};