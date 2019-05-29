#pragma once
#include <cassert>
#include "CheckSyntax.h"
using namespace regConstants;

//testing annonse set  syntax:
//Set s1;
void test1()
{
	cout << "\ntest1";
	assert(ANNSET == checkLine("Set set"));
	assert(FALSE == checkLine("Set set;"));
	assert(FALSE == checkLine("Seet set"));
	assert(FALSE == checkLine("Set set = 2;"));
	assert(ANNSET == checkLine("  Set set1   "));
	assert(ANNSET != checkLine("Setset "));
}

//testing annonse element  syntax:
//Element el;
void test2()
{
	cout << "\ntest2";
	assert(ANNEL == checkLine("Element el"));
	assert(FALSE == checkLine("Set set;"));
	assert(FALSE == checkLine("EElement set"));
	assert(FALSE == checkLine("Element set = 2;"));
	assert(ANNEL == checkLine("  Element el1   "));
}

//testing annonse include  syntax:
//include file.txt;
void test3()
{
	cout << "\ntest3";
	assert(INC == checkLine("include file.txt"));
	assert(FALSE == checkLine("Set set;;"));
	assert(FALSE == checkLine("EElement set;"));
	assert(FALSE == checkLine("Element set = 2"));
	assert(INC == checkLine(" include   file.txt  "));
	assert(INC != checkLine(" includefile.txt  "));
}

//testing annonse functionVoid  syntax
//function f();
void test4()
{
	cout << "\ntest4";
	assert(FUNCVOID == checkLine("function f() "));
	assert(FUNCVOID == checkLine("function func()"));
	assert(FALSE == checkLine("Set set()"));
	assert(FUNCVOID == checkLine("function f(el1, el2)"));
	assert(FUNCDO == checkLine("  functionf(el1, el2)"));
	assert(FUNCVOID == checkLine("function f()"));
	assert(FUNCVOID != checkLine("function Set f()"));
	assert(FUNCVOID != checkLine("function  f ()"));
	assert(ANNSET == checkLine("Set set"));
}

//testing annonse function  syntax
//function Set f();
void test5()
{
	cout << "\ntest5";
	assert(FUNCEL == checkLine("function Element f()"));
	assert(FUNCVOID == checkLine("function f()"));
	assert(FUNCVOID != checkLine("include file.txt"));
	assert(FUNCDO == checkLine("functionf(el1, el2)"));
	assert(FUNCSET == checkLine("function Set f()"));
	assert(FUNCVOID == checkLine("function  f()"));
	assert(FUNCEL != checkLine("function Element f ()"));
}

//testing elem asigm.  syntax
//el1 = 1;
void test6()
{
	cout << "\ntest6";
	assert(ASSEL == checkLine("a = 1"));
	assert(ASS == checkLine("a = b"));
	assert(FALSE == checkLine("a=b"));
	assert(FALSE == checkLine("a=1"));
}

//testing add & erase  syntax
// a << el;
void test7()
{
	cout << "\ntest7";
	assert(ADD == checkLine("a << b"));
	assert(ADD != checkLine("a<<b"));
	assert(ADD != checkLine("a << 1"));
	assert(ERASE == checkLine("a >> b"));
	assert(ERASE != checkLine("a>>1"));
	assert(ADD == checkLine("  a << q"));
	assert(ADD != checkLine("a << b;"));
}

//testing a += 4
//a -= 4;
void test8()
{
	cout << "\ntest8";
	assert(UNARYMINUS == checkLine("a -= 4"));
	assert(UNARYMINUS != checkLine("a -= b"));
	assert(UNARYMINUS != checkLine("a-=4"));
	assert(UNARYPLUS == checkLine("a += 4"));
	assert(UNARYPLUS != checkLine("a += b"));
	assert(UNARYPLUS != checkLine("a+=4"));
	assert(UNARYPLUS != checkLine("a += q"));
}

//testing assigment for function
//a = f();
void test9()
{
	cout << "\ntest9";
	assert(ASSFUNC == checkLine("a = f()"));
	assert(ASSFUNC != checkLine("a = f ()"));
	assert(ASSFUNC != checkLine("a=f()"));
	assert(ASSFUNC == checkLine("a1 = f(a, b)"));
	assert(ASSFUNC != checkLine("a1 = f (a, b)"));
	assert(ASSFUNC != checkLine("a += 4"));
}

//testing assigment operations
//a = a1 * b;
void test10()
{
	cout << "\ntest10";
	assert(ASSOP == checkLine("a = a1 * b"));
	assert(ASSOP != checkLine("a = a1 *b"));
	assert(ASSOP != checkLine("a = a1* b"));
	assert(ASSOP != checkLine("a =a1 * b"));
	assert(ASSOP != checkLine("a= a1 * b"));
}


//testing return
//return q
void test11()
{
	cout << "\ntest11";
	assert(RET == checkLine("return q"));
	assert(RET != checkLine("return q;"));
	assert(RET != checkLine("a = a1* b"));
	assert(RET != checkLine("a =a1 * b"));
	assert(RET == checkLine("   return  q  "));
}

//testing func do
//a = a1 * b;
void test12()
{
	cout << "\ntest12";
	assert(FUNCDO == checkLine("f()"));
	assert(FUNCDO == checkLine("f(a, b)"));
	assert(FUNCDO != checkLine("a = b"));
	assert(FUNCDO != checkLine("a = a1 * b"));
	assert(FUNCDO != checkLine("f (a, b)"));
}

//testing empty
//
void test13()
{
	cout << "\ntest13";
	assert(EMPTY == checkLine(""));
	assert(EMPTY == checkLine("   "));
	assert(EMPTY != checkLine("a = b"));
	assert(EMPTY != checkLine("a = a1 * b"));
	assert(EMPTY != checkLine("f (a, b)"));
	assert(EMPTY == checkLine("//f (a, b)"));
}

//test brace
void test14()
{
	cout << "\ntest14";
	assert(OPENBR == checkLine("{"));
	assert(OPENBR == checkLine(" {  "));
	assert(OPENBR != checkLine(" "));
	assert(OPENBR != checkLine(""));
	assert(CLOSEBR == checkLine("}"));
	assert(CLOSEBR == checkLine(" } "));
	assert(CLOSEBR != checkLine("{"));
}

void(*tests[])() =
{
	test1,
	test2,
	test3,
	test4,
	test5,
	test6,
	test7,
	test8,
	test9,
	test10,
	test11,
	test12,
	test13,
	test14,
	NULL
};

void startTests()
{
	cout << "\nStart tests...\n";

	int i = 0;

	while (tests[i] != NULL)
	{
		tests[i]();
		i++;
	}

	cout << "\n\nEnd tests...\n";
}