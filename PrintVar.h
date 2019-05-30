#include "Function.h";
#include "Element.h";
#include "Set.h";
using namespace std;

class PrintVar : public ICommand
{
public:
	void executeInstruction(vector<Function*> functions, map<string, BaseClass*> variables, string instruction, Function* curFunction)
	{
		SyntaxParser sp;
		vector<string> v1 = sp.split(instruction, '(');
		vector<string> v2 = sp.split(v1[1], ')');

		if (!curFunction->isAlreadyExists(v2[0]))
		{
			cout << "\nError in print in function \"" << curFunction->getName() << "\" in file: " <<
				curFunction->getFile() << "\nvar(s) is not initialized.";
			cin.get();
			cin.get();
			exit(0);
		}
		curFunction->getVariable(v2[0])->print();
	}
};