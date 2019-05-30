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
			cin.get();
			cin.get();
			exit(0);
		}

		if ((curFunction->getVariable((sp.split(instruction, ' '))[0])->getType()) != SET)
		{
			cout << "\nError in added vars in function \"" << curFunction->getName() << "\" in file: " <<
				curFunction->getFile() << "\ncannot add to Element.";
			cin.get();
			cin.get();
			exit(0);
		}	
		((Set*)curFunction->getVariable((sp.split(instruction, ' '))[0]))->add((curFunction->getVariable((sp.split(instruction, ' '))[2])));
	}
};