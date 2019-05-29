#include "Function.h";

using namespace std;

class CommandPrintText : public ICommand
{
public:
	void executeInstruction(vector<Function*> functions, map<string, BaseClass*> variables, string instruction);
	void fake() { cin.get(); }
};
