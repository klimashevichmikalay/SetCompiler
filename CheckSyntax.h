#pragma once
#include <regex>
#include <iostream>
#include <string>
#include "RegexConstants.h"

using namespace std;
using namespace std::regex_constants;

int ckeckErase(string str);
int ckeckAdd(string str);
int ckeckAssigmentToFunction(string str);
int ckeckAssignment(string str);
int ckeckAnnouncementSet(string str);
int ckeckInclude(string str);
int ckeckFunction(string str);
int ckeckBrace(string str);
int checkLine(string line);

extern int(*pointsToCheckFs[])(string line);
