#pragma once
#include <string>

namespace regConstants
{
	using namespace std;

	enum lineType {
		FALSE = 0,
		INC,
		FUNCVOID,
		FUNC,
		ASSEL,
		ASS,
		ADD,
		ERASE,
		BR,
		UNARYMINUS,
		UNARYPLUS,
		ANNSET,
		ANNEL,
		ASSFUNC,
		ASSOP
	};

	const string include = "^[ ]*(include)[ ]+[a-zA-Z0-9_\\.]+[ ]*;[ ]*$";
	const string announcementSet = "^[ ]*(Set)[ ]+[a-zA-Z0-9_]+[ ]*;[ ]*$";
	const string announcementElement = "^[ ]*(Element)[ ]+[a-zA-Z0-9_]+[ ]*;[ ]*$";
	const string functionVoid = "^[ ]*(function)[ ]+[a-zA-Z]+\\(.*\\);[ ]*$";
	const string function = "^[ ]*(function)[ ]+(Set|Element){1}[ ]+[a-zA-Z]+\\(.*\\);[ ]*$";
	const string assignment = "^[ ]*[a-zA-Z]+[ ]+\\=[ ]+[a-zA-Z0-9_]+[ ]*;[ ]*$";
	const string assignmentElement = "^[ ]*[a-zA-Z]+[ ]+\\=[ ]+[0-9]+[ ]*;[ ]*$";
	const string  add = "^[ ]*[a-zA-Z]+[ ]+\\<\\<[ ]+[a-zA-Z]+[ ]*;[ ]*$";//" el << el ; "
	const string  erase = "^[ ]*[a-zA-Z]+[ ]+\\>\\>[ ]+[a-zA-Z]+[ ]*;[ ]*$";//" el >> el ; "
	const string unaryMinus = "^[ ]*[a-zA-Z]+[ ]+(\\-=){1}[ ]+[0-9]+[ ]*;[ ]*$";//" el -= t ; "
	const string unaryPlus = "^[ ]*[a-zA-Z]+[ ]+(\\+=){1}[ ]+[0-9]+[ ]*;[ ]*$";//" el -= t ; "
	const string brace = "^[ ]*(\\{|\\}){1}[ ]*$";
	const string assigmentToFunction = "^[ ]*[a-zA-Z0-9_]+[ ]+\\=[ ]+[a-zA-Z]+\\(.*\\)[ ]*;[ ]*$";//" el = f(g) ; "	
	const string assigmentOperation = "^[ ]*[a-zA-Z0-9_]+[ ]+\\=[ ]+[a-zA-Z0-9_]+[ ]+[\\*\\-\\+\\~]{1}[ ]+[a-zA-Z0-9_]+[ ]*;[ ]*$";;
}