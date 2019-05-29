#include "Function.h";
#include "Element.h";
using namespace std;

class AssigmentElement : public ICommand
{
public:
	void executeInstruction(vector<Function*> functions, map<string, BaseClass*> variables, string instruction, Function* curFunction)
	{//
		SyntaxParser sp;
		if (!curFunction->isAlreadyExists((sp.split(instruction, ' ')[0])))
		{
			cout << "\nError in assigment Element in function \"" << curFunction->getName() << "\" in file: " <<
				curFunction->getFile() << "\nvar is not initialized.";
			return;
		}

		if (strchr("0123456789", sp.split(instruction, ' ')[2].c_str()[0]))
			curFunction->getVariable(sp.split(instruction, ' ')[0])->setValue(sp.split(instruction, ' ')[2]);	
	}
};