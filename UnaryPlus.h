#include "Function.h";
#include "Element.h";
#include "Set.h";
using namespace std;

class UnaryPlus : public ICommand
{
public:
	void executeInstruction(vector<Function*> functions, map<string, BaseClass*> variables, string instruction, Function* curFunction)
	{//
		SyntaxParser sp;
		if (!curFunction->isAlreadyExists((sp.split(instruction, ' ')[0])))
			
		{
			cout << "\nError in unary plus,in function \"" << curFunction->getName() << "\" in file: " <<
				curFunction->getFile() << "\nvar(s) is not initialized.";
			return;
		}

		if ((curFunction->getVariable((sp.split(instruction, ' '))[0])->getType()) == SET)
		{
			cout << "\nError in  unary plus in function \"" << curFunction->getName() << "\" in file: " <<
				curFunction->getFile() << "\nSet has not unary plus.";
			return;
		}
		(*((Element*)curFunction->getVariable((sp.split(instruction, ' '))[0]))) += std::stoi(sp.split(instruction, ' ')[2]);;
	}
};