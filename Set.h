#pragma once

#include <iostream>
#include <string>
#include <vector>
#include "Element.h"
#include "BaseClass.h"

using namespace std;

class Set : public BaseClass
{
private:
	vector<BaseClass*> set;

public:

	~Set();
	bool  equals(BaseClass* leftEl, BaseClass* rightEl);

	BaseClass* getAt(int p);
	vector<BaseClass*> getValue();	
	void setSet(vector<BaseClass*> _set);
	type getType();
	size_t getSize();

	void add(Element _el);
	void add(Set _st);
	void add(BaseClass *_bc);

	void pop_back();
	void print();
	void erase(BaseClass* _toComp);
	vector<BaseClass*> getSet();	
	Set* difference(Set* _set);
	Set* intersection(Set* _set);
	Set* ñartesianMult(Set* _set);
	Set* unite(Set* _set);
	void unique();
};




