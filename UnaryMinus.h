#include "Function.h";
#include "Element.h";
#include "Set.h";
using namespace std;

class UnaryMinus : public ICommand
{
public:
	void executeInstruction(vector<Function*> functions, map<string, BaseClass*> variables, string instruction, Function* curFunction)
	{//
		SyntaxParser sp;
		if (!curFunction->isAlreadyExists((sp.split(instruction, ' ')[0])))

		{
			cout << "\nError in unary minus,in function \"" << curFunction->getName() << "\" in file: " <<
				curFunction->getFile() << "\nvar(s) is not initialized.";
			cin.get();
			cin.get();
			exit(0);
		}

		if ((curFunction->getVariable((sp.split(instruction, ' '))[0])->getType()) == SET)
		{
			cout << "\nError in  unary minus in function \"" << curFunction->getName() << "\" in file: " <<
				curFunction->getFile() << "\nSet has not unary minus.";
			cin.get();
			cin.get();
			exit(0);
		}
		(*((Element*)curFunction->getVariable((sp.split(instruction, ' '))[0]))) -= std::stoi(sp.split(instruction, ' ')[2]);;
	}
};