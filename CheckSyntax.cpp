#include "CheckSyntax.h"

int ckeckAnnouncementSet(string str)
{
	std::regex e(regConstants::announcementSet);
	if (std::regex_match(str, e))
		return regConstants::ANNSET;
	return regConstants::FALSE;
}

int ckeckAnnouncementElement(string str)
{
	std::regex e(regConstants::announcementElement);
	if (std::regex_match(str, e))
		return regConstants::ANNEL;
	return regConstants::FALSE;
}

int ckeckInclude(string str)
{
	std::regex e(regConstants::include);
	if (std::regex_match(str, e))
		return regConstants::INC;
	return regConstants::FALSE;
}

int ckeckFunctionVoid(string str)
{
	std::regex e(regConstants::functionVoid);
	if (std::regex_match(str, e))
		return regConstants::FUNCVOID;
	return regConstants::FALSE;
}

int ckeckFunction(string str)
{
	std::regex e(regConstants::function);
	if (std::regex_match(str, e))
		return regConstants::FUNC;
	return regConstants::FALSE;
}

int ckeckAssignment(string str)
{
	std::regex e(regConstants::assignment);
	if (std::regex_match(str, e))
		return regConstants::ASS;
	return regConstants::FALSE;
}

int ckeckAssignmentElement(string str)
{
	std::regex e(regConstants::assignmentElement);
	if (std::regex_match(str, e))
		return regConstants::ASSEL;
	return regConstants::FALSE;
}

int ckeckErase(string str)
{
	std::regex e(regConstants::erase);
	if (std::regex_match(str, e))
		return regConstants::ERASE;
	return regConstants::FALSE;
}

int ckeckAdd(string str)
{
	std::regex e(regConstants::add);
	if (std::regex_match(str, e))
		return regConstants::ADD;
	return regConstants::FALSE;
}

int ckeckBrace(string str)
{
	std::regex e(regConstants::brace);
	if (std::regex_match(str, e))
		return regConstants::BR;
	return regConstants::FALSE;
}

int ckeckUnaryMinus(string str)
{
	std::regex e(regConstants::unaryMinus);
	if (std::regex_match(str, e))
		return regConstants::UNARYMINUS;
	return regConstants::FALSE;
}

int ckeckUnaryPlus(string str)
{
	std::regex e(regConstants::unaryPlus);
	if (std::regex_match(str, e))
		return regConstants::UNARYPLUS;
	return regConstants::FALSE;
}

//////////////////////
////////////////////////


int ckeckAssigmentToFunction(string str)
{
	std::regex e(regConstants::assigmentToFunction);
	if (std::regex_match(str, e))
		return regConstants::ASSFUNC;
	return regConstants::FALSE;
}

int ckeckReturn(string str)
{
	std::regex e(regConstants::ret);
	if (std::regex_match(str, e))
		return regConstants::RET;
	return regConstants::FALSE;
}

int ckeckEmpty(string str)
{
	std::regex e(regConstants::empty);
	if (std::regex_match(str, e))
		return regConstants::EMPTY;
	return regConstants::FALSE;
}

int ckeckDoFunction(string str)
{
	std::regex e(regConstants::doFunction);
	if (std::regex_match(str, e))
		return regConstants::FUNCDO;
	return regConstants::FALSE;
}

int ckeckAssigmentOperation(string str)
{
	std::regex e(regConstants::assigmentOperation);
	if (std::regex_match(str, e))
		return regConstants::ASSOP;
	return regConstants::FALSE;
}


int(*pointsToCheckFs[])(string line) =
{
	ckeckAnnouncementElement,
	ckeckAnnouncementSet,
	ckeckFunctionVoid,
	ckeckFunction,
	ckeckAssignmentElement,
	ckeckAssignment,
	ckeckErase,
	ckeckAdd,
	ckeckInclude,
	ckeckBrace,
	ckeckUnaryMinus,
	ckeckUnaryPlus,
	ckeckAssigmentToFunction,	
	ckeckAssigmentOperation,
	ckeckReturn,
	ckeckEmpty,
	ckeckDoFunction,
	NULL
};

int checkLine(string line)
{
	int i = 0;
	int res;

	while (pointsToCheckFs[i] != NULL)
	{
		res = pointsToCheckFs[i](line);
		if (res)
		return res;
		i++;
	}
	return 0;
}