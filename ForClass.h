#include "Function.h";
#include "Element.h";
#include "Set.h";
#include "CheckSyntax.h"
using namespace std;

class ForClass : public ICommand
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
				cout << "\nError: required opening brace in IF in function \"" <<
				curFunction->getName() << "\" at line " << curFunction->getCurLine() << "\.";

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
			vector<string> v;
			return v;
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
			return nullptr;
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
		string varneg = sp.split((sp.split(instruction, '(')[1]), ')')[0];
		int number = std::stoi(varneg);	

		Function* funcIf = formFunction(curFunction);

		if (funcIf == nullptr)
		{
			cout << "\nError in body FOR. Exit.";
			cin.get();
			cin.get();
			exit(0);
		}

		for (int i = 0; i < number; i++)
			funcIf->execute();
	}
};