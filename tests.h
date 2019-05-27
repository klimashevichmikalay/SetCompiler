#pragma once
#include <cassert>
#include "CheckSyntax.h"
using namespace regConstants;

//testing annonse set  syntax:
//Set s1;
void test1()
{
	cout << "\ntest1";
	assert(ANNSET == checkLine("Set set;"));
	assert(FALSE == checkLine("Set set;;"));
	assert(FALSE == checkLine("Seet set;"));
	assert(FALSE == checkLine("Set set = 2;"));
	assert(ANNSET == checkLine("  Set set1  ; "));
	assert(ANNSET != checkLine("Setset ;"));
}

//testing annonse element  syntax:
//Element el;
void test2()
{
	cout << "\ntest2";
	assert(ANNEL == checkLine("Element el;"));
	assert(FALSE == checkLine("Set set;;"));
	assert(FALSE == checkLine("EElement set;"));
	assert(FALSE == checkLine("Element set = 2;"));
	assert(ANNEL == checkLine("  Element el1  ; "));
}

//testing annonse include  syntax:
//include file.txt;
void test3()
{
	cout << "\ntest3";
	assert(INC == checkLine("include file.txt;"));
	assert(FALSE == checkLine("Set set;;"));
	assert(FALSE == checkLine("EElement set;"));
	assert(FALSE == checkLine("Element set = 2;"));
	assert(INC == checkLine(" include   file.txt ; "));
	assert(INC != checkLine(" includefile.txt ; "));
}

//testing annonse functionVoid  syntax
//function f();
void test4()
{
	cout << "\ntest4";
	assert(FUNCVOID == checkLine("function f(); "));
	assert(FALSE == checkLine("Set set;;"));
	assert(FUNCVOID == checkLine("function f(el1, el2);"));
	assert(FALSE == checkLine("  functionf(el1, el2)"));
	assert(FUNCVOID == checkLine("function f();"));
	assert(FUNCVOID != checkLine("function Set f();"));
	assert(FUNCVOID != checkLine("function  f ();"));
}

//testing annonse function  syntax
//function Set f();
void test5()
{
	cout << "\ntest5";
	assert(FUNC == checkLine("function Element f();"));
	assert(FUNCVOID == checkLine("function f();"));
	assert(FUNCVOID != checkLine("include file.txt;"));
	assert(FALSE == checkLine("functionf(el1, el2)"));
	assert(FUNC == checkLine("function Set f();"));
	assert(FUNC != checkLine("function  f();"));
	assert(FUNC != checkLine("function Element f ();"));
}

//testing elem asigm.  syntax
//el1 = 1;
void test6()
{
	cout << "\ntest6";
	assert(ASSEL == checkLine("a = 1;"));
	assert(ASS == checkLine("a = b;"));
	assert(FALSE == checkLine("a=b;"));
	assert(FALSE == checkLine("a=1;"));
}

//testing add & erase  syntax
// a << el;
void test7()
{
	cout << "\ntest7";
	assert(ADD == checkLine("a << b;"));
	assert(ADD != checkLine("a<<b;"));
	assert(ADD != checkLine("a << 1;"));
	assert(ERASE == checkLine("a >> b;"));
	assert(ERASE != checkLine("a>>1;"));
	assert(ADD == checkLine("  a << q;"));
	assert(ADD != checkLine("a << b"));
}

//testing a += 4
//a -= 4;
void test8()
{
	cout << "\ntest8";
	assert(UNARYMINUS == checkLine("a -= 4;"));
	assert(UNARYMINUS != checkLine("a -= b;"));
	assert(UNARYMINUS != checkLine("a-=4;"));
	assert(UNARYPLUS == checkLine("a += 4;"));
	assert(UNARYPLUS != checkLine("a += b;"));
	assert(UNARYPLUS != checkLine("a+=4;"));
	assert(UNARYPLUS != checkLine("a += q;"));
}

//testing assigment for function
//a = f();
void test9()
{
	cout << "\ntest9";
	assert(ASSFUNC == checkLine("a = f();"));
	assert(ASSFUNC != checkLine("a = f ();"));
	assert(ASSFUNC != checkLine("a=f();"));
	assert(ASSFUNC == checkLine("a1 = f(a, b);"));
	assert(ASSFUNC != checkLine("a1 = f (a, b);"));
	assert(ASSFUNC != checkLine("a += 4;"));
}

//testing assigment operations
//a = a1 * b;
void test10()
{
	cout << "\ntest10";
	assert(ASSOP == checkLine("a = a1 * b;"));
	assert(ASSOP != checkLine("a = a1 *b;"));
	assert(ASSOP != checkLine("a = a1* b;"));
	assert(ASSOP != checkLine("a =a1 * b;"));
	assert(ASSOP != checkLine("a= a1 * b;"));
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
	NULL
};