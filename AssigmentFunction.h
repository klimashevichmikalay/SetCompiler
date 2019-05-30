#include "Function.h";
#include "Element.h";
#include "Set.h";
using namespace std;

class AssigmentFunction : public ICommand
{
public:

	Function* getAssigmentF(vector<Function*> functions, map<string, BaseClass*> variables, string instruction, Function* curFunction)
	{
		SyntaxParser sp;
		Function* prototype = new Function();
		map<string, type> parameters;
		map<string, BaseClass*> newVariables;

		string funcProt = (sp.split(instruction, '=')[1]);
		vector<string> header = curFunction->splitHeader(funcProt);
		if (sp.split(instruction, '(')[1].size() == 1)
			prototype->setName(sp.split((sp.split(instruction, '(')[0]), ' ')[2]);
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
				curFunction->getFile() << " at line " << curFunction->getCurLine() << "\nthere is no such function. EXIT.";
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

		return f;
	}


	void executeInstruction(vector<Function*> functions, map<string, BaseClass*> variables, string instruction, Function* curFunction)
	{
		SyntaxParser sp;
		if (!curFunction->isAlreadyExists((sp.split(instruction, ' ')[0])))
		{
			cout << "\nError in assigment vars in function \"" << curFunction->getName() << "\" in file: " <<
				curFunction->getFile() << "\nvar(s) is not initialized. EXIT.";
			cin.get();
			cin.get();
			exit(0);
		}

		Function *f = getAssigmentF(functions, variables, instruction, curFunction);
		if (f->getReturnedName() == "")
		{
			cout << "\nError in assigment vars in function \"" << curFunction->getName() << "\" in file: " <<
				curFunction->getFile() << "\nfunction \"" << f->getName() << "\" does not return values. EXIT.";
			cin.get();
			cin.get();
			exit(0);
		}
		f->execute();
		if ((curFunction->getVariable((sp.split(instruction, ' '))[0]))->getType() !=
			(f->getReturnedValue()->getType()))
		{
			cout << "\nError in assigment vars in function \"" << curFunction->getName() << "\" in file: " <<
				curFunction->getFile() << "\nfunction \" " << f->getName() << "\"\nthe assigned and returned value of the function\nmust be of the same type. EXIT.";
			cin.get();
			cin.get();
			exit(0);
		}

		if ((curFunction->getVariable((sp.split(instruction, ' '))[0]))->getType() == ELEMENT)
			*((Element*)(curFunction->getVariable((sp.split(instruction, ' '))[0]))) = *((Element*)(f->getReturnedValue()));

		if ((curFunction->getVariable((sp.split(instruction, ' '))[0]))->getType() == SET)
			*((Set*)(curFunction->getVariable((sp.split(instruction, ' '))[0]))) = *((Set*)(f->getReturnedValue()));
	}
};