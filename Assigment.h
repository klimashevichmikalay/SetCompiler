#include "Function.h";
#include "Element.h";
#include "Set.h";
using namespace std;

class Assigment : public ICommand
{
public:
	void executeInstruction(vector<Function*> functions, map<string, BaseClass*> variables, string instruction, Function* curFunction)
	{//
		SyntaxParser sp;
		if (!curFunction->isAlreadyExists((sp.split(instruction, ' ')[0])) ||			
			!curFunction->isAlreadyExists((sp.split(instruction, ' ')[2])))
		{
			cout << "\nError in assigment vars in function \"" << curFunction->getName() << "\" in file: " <<
				curFunction->getFile() << "\nvar(s) is not initialized.";
			return;
		}

		if ((curFunction->getVariable((sp.split(instruction, ' '))[0])->getType()) != 
			(curFunction->getVariable(sp.split(instruction, ' ')[2])->getType()))
		{
			cout << "\nError in assigment vars in function \"" << curFunction->getName() << "\" in file: " <<
				curFunction->getFile() << "\nno assignment is possible because variables\n have a different type.";
			return;
		}  	
		
		if((curFunction->getVariable((sp.split(instruction, ' '))[0]))->getType() == ELEMENT)
		*((Element*)curFunction->getVariable((sp.split(instruction, ' '))[0])) = *((Element*)curFunction->getVariable((sp.split(instruction, ' '))[2]));
      
		if ((curFunction->getVariable((sp.split(instruction, ' '))[0]))->getType() == SET)
			*((Set*)curFunction->getVariable((sp.split(instruction, ' '))[0])) = *((Set*)curFunction->getVariable((sp.split(instruction, ' '))[2]));
	}
};