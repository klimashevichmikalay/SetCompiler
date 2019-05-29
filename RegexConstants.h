#pragma once
#include <string>

namespace regConstants
{
	using namespace std;

	enum lineType {
		FALSE = 0,
		INC,
		FUNCVOID,
		FUNCSET,	
		FUNCEL,
		ASSEL,
		ASS,
		ADD,
		ERASE,
		OPENBR,
		CLOSEBR,
		UNARYMINUS,
		UNARYPLUS,
		ANNSET,
		ANNEL,
		ASSFUNC,
		FUNCDO,
		ASSOP,
		RET,
		EMPTY
	};

	const string include = "^[ ]*(include)[ ]+[a-zA-Z0-9_\\.]+[ ]*[ ]*$";
	const string announcementSet = "^[ ]*(Set)[ ]+[a-zA-Z0-9_]+[ ]*[ ]*$";
	const string announcementElement = "^[ ]*(Element)[ ]+[a-zA-Z0-9_]+[ ]*[ ]*$";
	const string functionVoid = "^[ ]*(function)[ ]+[a-zA-Z0-9_]+\\(.*\\)[ ]*$";
	const string functionSet = "^[ ]*(function)[ ]+(Set){1}[ ]+[a-zA-Z0-9_]+\\(.*\\)[ ]*$";
	const string functionElement = "^[ ]*(function)[ ]+(Element){1}[ ]+[a-zA-Z0-9_]+\\(.*\\)[ ]*$";
	const string assignment = "^[ ]*[a-zA-Z]+[ ]+\\=[ ]+[a-zA-Z0-9_]+[ ]*[ ]*$";
	const string assignmentElement = "^[ ]*[a-zA-Z]+[ ]+\\=[ ]+[0-9]+[ ]*[ ]*$";
	const string  add = "^[ ]*[a-zA-Z]+[ ]+\\<\\<[ ]+[a-zA-Z]+[ ]*[ ]*$";//" el << el ; "
	const string  erase = "^[ ]*[a-zA-Z]+[ ]+\\>\\>[ ]+[a-zA-Z]+[ ]*[ ]*$";//" el >> el ; "
	const string unaryMinus = "^[ ]*[a-zA-Z]+[ ]+(\\-=){1}[ ]+[0-9]+[ ]*[ ]*$";//" el -= t ; "
	const string unaryPlus = "^[ ]*[a-zA-Z]+[ ]+(\\+=){1}[ ]+[0-9]+[ ]*[ ]*$";//" el -= t ; "
	const string openBrace = "^[ ]*(\\{){1}[ ]*$";
	const string closeBrace = "^[ ]*(\\}){1}[ ]*$";
	const string assigmentToFunction = "^[ ]*[a-zA-Z0-9_]+[ ]+\\=[ ]+[a-zA-Z]+\\(.*\\)[ ]*[ ]*$";//" el = f(g) ; "	
	const string assigmentOperation = "^[ ]*[a-zA-Z0-9_]+[ ]+\\=[ ]+[a-zA-Z0-9_]+[ ]+[\\*\\-\\+\\~]{1}[ ]+[a-zA-Z0-9_]+[ ]*[ ]*$";	
	const string ret = "^[ ]*(return)[ ]+[a-zA-Z]+[ ]*$";
	const string empty = "^(\\/\\/.*)|([ ]*)$";
	const string doFunction = "^[ ]*[a-zA-Z]+\\(.*\\)[ ]*$";
}





