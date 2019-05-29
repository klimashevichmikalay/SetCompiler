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

int ckeckFunctionSet(string str)
{
	std::regex e(regConstants::functionSet);
	if (std::regex_match(str, e))
		return regConstants::FUNCSET;
	return regConstants::FALSE;
}

int ckeckFunctionElement(string str)
{
	std::regex e(regConstants::functionElement);
	if (std::regex_match(str, e))
		return regConstants::FUNCEL;
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

int ckeckOpenBrace(string str)
{
	std::regex e(regConstants::openBrace);
	if (std::regex_match(str, e))
		return regConstants::OPENBR;
	return regConstants::FALSE;
}

int ckeckCloseBrace(string str)
{
	std::regex e(regConstants::closeBrace);
	if (std::regex_match(str, e))
		return regConstants::CLOSEBR;
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

int(*pointsToCheckFs[])(string line) =
{
	ckeckAnnouncementElement,
	ckeckAnnouncementSet,
	ckeckFunctionVoid,
	ckeckFunctionSet,
	ckeckFunctionElement,
	ckeckAssignmentElement,
	ckeckAssignment,
	ckeckErase,
	ckeckAdd,
	ckeckInclude,
	ckeckOpenBrace,
	ckeckCloseBrace,
	ckeckUnaryMinus,
	ckeckUnaryPlus,
	ckeckAssigmentToFunction,	
	ckeckAssigmentOperation,
	ckeckReturn,
	ckeckEmpty,
	ckeckDoFunction,
	NULL
};