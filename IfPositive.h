#include "Function.h";
#include "Element.h";
#include "Set.h";
#include "CheckSyntax.h"
using namespace std;

class IfPositive : public ICommand
{
public:

	
	vector<string> formNewFunctionCode(Function* curFunction)
	{
		vector<string> newCode;
		vector<string> code = curFunction->getCode();
		bool start = false;
		bool end = false;
		for (int i = curFunction->getCurLine() + 1; i < code.size(); i++)
		{
			lineType lt = (lineType)checkLine(code[i]);
			if (lt == EMPTY)
				continue;

			if (lt == CLOSEBR && !start)
			{
				cout << "\nError: required opening brace in IF in function \"" <<
					curFunction->getName() << "\" at line " << curFunction->getCurLine() << "\.";
				cin.get();
				cin.get();
				exit(0);
			}
			
			if (lt == OPENBR && !end)
			{
				start = true;
				continue;
			}

			if (lt == CLOSEBR && start)
			{
				end = true;
				break;
			}

			if (start && !end)
			{
				newCode.push_back(code[i]);
			}
		}

		if (!end || !start)
		{
			cout << "\nYou have problem with scopes." << "\nEnd programm.";
			cin.get();
			cin.get();
			exit(0);
		}
		
		return newCode;
	}

	Function* formFunction(Function* curFunction)
	{
		Function* funcIf = new Function();
		vector<string> newCode = formNewFunctionCode(curFunction);

		if (newCode.size() == 0)
		{
			cout << "\nError: IF must have body \"" <<
				curFunction->getName() << "\" at line " << curFunction->getCurLine() << "\.";
			cin.get();
			cin.get();
			exit(0);
		}

		funcIf->setCode(newCode);
		funcIf->setName("IF");
		funcIf->setVariables(curFunction->getVariables());
		funcIf->setFunctions(curFunction->getFunctions());
		funcIf->setCommands(curFunction->getCommands());		
		curFunction->setCurLine(newCode.size() + curFunction->getCurLine() + 1);
		return funcIf;
	}

	void executeInstruction(vector<Function*> functions, map<string, BaseClass*> variables, string instruction, Function* curFunction)
	{
		SyntaxParser sp;
		if (!curFunction->isAlreadyExists(sp.split((sp.split(instruction, '(')[1]), ')')[0]))
		{
			cout << "\nError in  IF \"" << curFunction->getName() << "\" in file: " <<
				curFunction->getFile()<< " at Line  in function #" << curFunction->getCurLine() << "\nvar(s) is not initialized. EXIT.";
			cin.get();
			cin.get();
			exit(0);
		}

		Function* funcIf = formFunction(curFunction);

		if (funcIf == nullptr)
		{
			cout << "\nError in IF. Exit.";
			cin.get();
			cin.get();
			exit(0);			
		}

		if ((curFunction->getVariable(((sp.split((sp.split(instruction, '(')[1]), ')')[0])))->getType() == SET)
			&& ((Set*)((curFunction->getVariable(((sp.split((sp.split(instruction, '(')[1]), ')')[0]))))))->getSize() != 0)
			funcIf->execute();

		if ((curFunction->getVariable(((sp.split((sp.split(instruction, '(')[1]), ')')[0])))->getType() == ELEMENT)
			&& ((Element*)((curFunction->getVariable(((sp.split((sp.split(instruction, '(')[1]), ')')[0]))))))->getValue() != 0)
			funcIf->execute();
	}
};