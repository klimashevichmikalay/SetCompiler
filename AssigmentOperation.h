#include "Function.h";
#include "Element.h";
using namespace std;

class AssigmentOperation : public ICommand
{
public:
	void executeInstruction(vector<Function*> functions, map<string, BaseClass*> variables, string instruction, Function* curFunction)
	{//
		SyntaxParser sp;
		if (!curFunction->isAlreadyExists((sp.split(instruction, ' ')[0]))
			|| !curFunction->isAlreadyExists((sp.split(instruction, ' ')[2]))
			|| !curFunction->isAlreadyExists((sp.split(instruction, ' ')[4])))
		{
			cout << "\nError in operation in function \"" << curFunction->getName() << "\" in file: " <<
				curFunction->getFile() << "\nvar(s) is not initialized.";
			cin.get();
			cin.get();
			exit(0);
		}

		if (curFunction->getVariable(sp.split(instruction, ' ')[0])->getType() != SET
			|| curFunction->getVariable(sp.split(instruction, ' ')[2])->getType() != SET
			|| curFunction->getVariable(sp.split(instruction, ' ')[4])->getType() != SET)
		{
			cout << "\nError in operation in function \"" << curFunction->getName() << "\" in file: " <<
				curFunction->getFile() << "\nthese operations are for sets.";
			cin.get();
			cin.get();
			exit(0);
		}

		if (sp.split(instruction, ' ')[3][0] == '+')
		{
			*(Set*)(curFunction->getVariable((sp.split(instruction, ' '))[0])) =
				*((((Set*)curFunction->getVariable((sp.split(instruction, ' '))[2]))->
					unite((Set*)curFunction->
						getVariable((sp.split(instruction, ' '))[4]))));
		}

		if (sp.split(instruction, ' ')[3][0] == '-')
		{
			*(Set*)(curFunction->getVariable((sp.split(instruction, ' '))[0])) =
				*((((Set*)curFunction->getVariable((sp.split(instruction, ' '))[2]))->
					difference((Set*)curFunction->
						getVariable((sp.split(instruction, ' '))[4]))));
		}

		if (sp.split(instruction, ' ')[3][0] == '*')
		{
			*(Set*)(curFunction->getVariable((sp.split(instruction, ' '))[0])) =
				*((((Set*)curFunction->getVariable((sp.split(instruction, ' '))[2]))->
					ñartesianMult((Set*)curFunction->
						getVariable((sp.split(instruction, ' '))[4]))));
		}

		if (sp.split(instruction, ' ')[3][0] == '~')
		{
			*(Set*)(curFunction->getVariable((sp.split(instruction, ' '))[0])) =
				*((((Set*)curFunction->getVariable((sp.split(instruction, ' '))[2]))->
					intersection((Set*)curFunction->
						getVariable((sp.split(instruction, ' '))[4]))));
		}

	}
};