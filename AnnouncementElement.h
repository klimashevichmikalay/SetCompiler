#include "Function.h";
#include "Element.h";
using namespace std;

class AnnouncementElement : public ICommand
{
public:
	void executeInstruction(vector<Function*> functions, map<string, BaseClass*> variables, string instruction, Function* curFunction)
	{
		SyntaxParser sp;		
		if (curFunction->isAlreadyExists((sp.split(instruction, ' ')[1])))
		{
			cout << "\nError in announcement ELement in function \"" << curFunction->getName() << "\" in file " <<
				curFunction->getFile() << ":\nname \"" << sp.split(instruction, ' ')[1] << "\" is already exists.";
			return;
		}

		Element* el = new Element();		
		curFunction->getVariables().insert(pair<string, Element*>((sp.split(instruction, ' ')[1]), el));
	}	
};