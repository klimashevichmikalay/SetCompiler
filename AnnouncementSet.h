#include "Function.h";

using namespace std;

class AnnouncementSet : public ICommand
{
public:
	void executeInstruction(vector<Function*> functions, map<string, BaseClass*> variables, string instruction, Function* curFunction);	
};
