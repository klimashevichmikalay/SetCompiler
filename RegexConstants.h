#pragma once
#include <string>

namespace regConstants
{
	using namespace std;

	enum type { VOID, ELEMENT, SET };

	enum lineType {
		FALSE = 0,//+
		INC,//+
		FUNCVOID,//+
		FUNCSET,//+	
		FUNCEL,//+
		ASSEL,//+
		ASS,//+
		ADD,//+
		ERASE,//+
		OPENBR,//+
		CLOSEBR,//+		
		ANNSET,//+
		ANNEL,//+
		RET,//+
		EMPTY,//+		
		PRINTTEXT,//+
		UNARYMINUS,//+
		UNARYPLUS,//+
		PRINTVAR,//+
		ASSOP,//+		
		IF,//-
		IFNEGATION,//-
		FUNCDO,//-
		ASSFUNC,//-
		
	};

	const string include = "^[ ]*(include)[ ]+[a-zA-Z0-9_\\.]+[ ]*[ ]*$";
	const string announcementSet = "^[ ]*(Set)[ ]+[a-zA-Z0-9_]+[ ]*[ ]*$";
	const string announcementElement = "^[ ]*(Element)[ ]+[a-zA-Z0-9_]+[ ]*[ ]*$";
	const string functionVoid = "^[ ]*(function)[ ]+[a-zA-Z0-9_]+\\(.*\\)[ ]*$";
	const string functionSet = "^[ ]*(function)[ ]+(Set){1}[ ]+[a-zA-Z0-9_]+\\(.*\\)[ ]*$";
	const string functionElement = "^[ ]*(function)[ ]+(Element){1}[ ]+[a-zA-Z0-9_]+\\(.*\\)[ ]*$";
	const string assignment = "^[ ]*[a-zA-Z0-9_]+[ ]+\\=[ ]+[a-zA-Z0-9_]+[ ]*[ ]*$";
	const string assignmentElement = "^[ ]*[a-zA-Z0-9_]+[ ]+\\=[ ]+[0-9]+[ ]*[ ]*$";
	const string  add = "^[ ]*[a-zA-Z0-9_]+[ ]+\\<\\<[ ]+[a-zA-Z0-9_]+[ ]*[ ]*$";//" el << el ; "
	const string  erase = "^[ ]*[a-zA-Z0-9_]+[ ]+\\>\\>[ ]+[a-zA-Z0-9_]+[ ]*[ ]*$";//" el >> el ; "
	const string unaryMinus = "^[ ]*[a-zA-Z0-9_]+[ ]+(\\-=){1}[ ]+[0-9]+[ ]*[ ]*$";//" el -= t ; "
	const string unaryPlus = "^[ ]*[a-zA-Z0-9_]+[ ]+(\\+=){1}[ ]+[0-9]+[ ]*[ ]*$";//" el -= t ; "
	const string openBrace = "^[ ]*(\\{){1}[ ]*$";
	const string closeBrace = "^[ ]*(\\}){1}[ ]*$";
	const string assigmentToFunction = "^[ ]*[a-zA-Z0-9_]+[ ]+\\=[ ]+[a-zA-Z0-9_]+\\(.*\\)[ ]*[ ]*$";//" el = f(g) ; "	
	const string assigmentOperation = "^[ ]*[a-zA-Z0-9_]+[ ]+\\=[ ]+[a-zA-Z0-9_]+[ ]+[\\*\\-\\+\\~]{1}[ ]+[a-zA-Z0-9_]+[ ]*[ ]*$";	
	const string ret = "^[ ]*(return)[ ]+[a-zA-Z0-9_]+[ ]*$";
	const string empty = "^(\\/\\/.*)|([ ]*)$";
	const string doFunction = "^[ ]*(print){0}[a-zA-Z0-9_]+\\(([^\'^\\)]*)\\)[ ]*$";
	const string printVar = "^[ ]*(print)\\([ ]*[a-zA-Z0-9_]+[ ]*\\)[ ]*$";	
	const string printText = "^[ ]*(print)\\([ ]*\'[^\']+\'[ ]*\\)[ ]*$";
	const string ifPositive = "^[ ]*(if){1}\\([a-zA-Z0-9_]+\\)[ ]*$";
	const string ifNegation = "^[ ]*(if)\\(\\![a-zA-Z0-9_]+\\)[ ]*$";		
}





