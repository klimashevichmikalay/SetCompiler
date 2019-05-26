#include <iostream>
#include "Element.h"
#include "Set.h"
using namespace std;

void add2(Set *set)
{
	Element el("1");
	Element el1("2");
	Element el2("3");

	set->add(el);
	set->add(el1);
	set->add(el2);	
}

void add(Set *set)
{
	Element el("1234");
	Element el1("9");
	Element el2("1");
	Element el3("12");
	Element el4("1234");
	Element el5("23");

	el = 0;
	el1 -= 4;
	el2 += 9;
	el3 += 3;

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
	add2(st);

	st->print();
	cout << endl << "Adding new set...\n";

	Set* st3 = new Set;
	add2(st3);

	Set* st1 = new Set;
	add(st1);
	st1->add(st3);
	st->add(st1);
	st->print();

	Element* el2 = new Element("10");
	cout << "\nerasing 10...\n";
	st->erase(el2);
	st->print();

	cout << "\nerasing set1...\n";
	st->erase(st1);
	st->print();


	cin.get();
	cin.get();
	return 0;
}