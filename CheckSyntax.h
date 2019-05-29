#pragma once
#include <regex>
#include <iostream>
#include <string>
#include "RegexConstants.h"

using namespace std;
using namespace std::regex_constants;

extern int(*pointsToCheckFs[])(string line);

int ckeckAnnouncementSet(string str);
int ckeckAnnouncementElement(string str);
int ckeckInclude(string str);
int ckeckFunctionVoid(string str);
int ckeckFunctionSet(string str);
int ckeckFunctionElement(string str);
int ckeckAssignment(string str);
int ckeckAssignmentElement(string str);
int ckeckErase(string str);
int ckeckAdd(string str);
int ckeckOpenBrace(string str);
int ckeckCloseBrace(string str);
int ckeckUnaryMinus(string str);
int ckeckUnaryPlus(string str);
int ckeckAssigmentToFunction(string str);
int ckeckReturn(string str);
int ckeckEmpty(string str);
int ckeckDoFunction(string str);
int ckeckAssigmentOperation(string str);
int ckeckPrintVar(string str);
int ckeckPrintText(string str);
int checkLine(string line);


