#include "Function.h";
#include "Element.h";
#include "Set.h";
using namespace std;

class FuncDo : public ICommand
{
public:
	void executeInstruction(vector<Function*> functions, map<string, BaseClass*> variables, string instruction, Function* curFunction)
	{//
		SyntaxParser sp;
		Function* prototype = new Function();
		map<string, type> parameters;
		map<string, BaseClass*> newVariables;
		vector<string> header = curFunction->splitHeader(instruction);
		if (sp.split(instruction, '(')[1].size() == 1)		
			prototype->setName(sp.split((sp.split(instruction, '(')[0]), ' ')[0]);		
		else
		{			
			prototype->setName(header[0]);

			for (int i = 1; i < header.size(); i++)
			{
				if (!curFunction->isAlreadyExists(header[i]))
				{
					cout << "\nError in func parameter vars in function \"" << curFunction->getName() << "\" in file: " <<
						curFunction->getFile() << "\nvar(s) is not initialized. EXIT.";
					cin.get();
					cin.get();
					exit(0);
				}				
				parameters.insert(pair<string, type>(header[i], curFunction->getVariable(header[i])->getType()));			
			}			
			prototype->setParameters(parameters);
		}

		Function* f = curFunction->getFunction(prototype);

		if (f == nullptr)
		{
			cout << "\nError in function call in function \"" << curFunction->getName() << "\" in file: " <<
				curFunction->getFile() << " at lile " << curFunction->getCurLine() << "\nthere is no such function. EXIT.";
			cin.get();
			cin.get();
			exit(0);
		}

		int i = 1;
		for (auto& item : f->getParameters())
		{			
			newVariables.insert(pair<string, BaseClass*>(item.first, curFunction->getVariable(header[i])));
		}
		f->setVariables(newVariables);

		f->execute();
	}
};