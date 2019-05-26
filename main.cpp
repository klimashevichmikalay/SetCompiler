#include <iostream>
#include "Element.h"
#include "Set.h"
using namespace std;

void add1(Set *set)
{
	Element el("1");
	Element el1("2");
	Element el2("3");
	Element el3("7");

	set->add(el);
	set->add(el1);
	set->add(el3);
	set->add(el);
	set->add(el1);
	set->add(el3);
}

void add(Set *set)
{
	Element el("1");
	Element el1("2");
	Element el2("3");
	Element el3("4");
	Element el4("5");
	Element el5("6");

	set->add(el);	
	set->add(el1);
	set->add(el2);
	set->add(el3);
	set->add(el4);
	set->add(el5);
}

int main()
{
	Set* st = new Set;
	add(st);
		
	Set* st1 = new Set;
	add1(st1);

	st->print();
	cout << endl;
	st1->print();

	Set* st2 = st->ñartesianMult(st1);
	cout << endl;
	st2->print();

	cin.get();
	cin.get();
	return 0;
}