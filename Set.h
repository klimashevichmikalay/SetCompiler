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

	BaseClass* getAt(int p) { return set[p]; }

	vector<BaseClass*> getValue()
	{
		return this->set;
	}	

	 bool  equals(BaseClass* leftEl, BaseClass* rightEl)
	{
		if (leftEl->getType() != rightEl->getType())
			return false;
		
		if (leftEl->getType() == ELEMENT)

			return leftEl->equals(leftEl, rightEl);

		if (static_cast<Set*>(leftEl)->getSize() != static_cast<Set*>(rightEl)->getSize())
			return false;

		for (int i = 0; i < static_cast<Set*>(leftEl)->getSize(); i++)
		{
			bool flag = false;
			for (size_t j = 0; j < static_cast<Set*>(rightEl)->getSize(); j++)
				if (equals(leftEl->getAt(i), rightEl->getAt(j)))
					flag = true;

			if (!flag)
				return false;
		}

		return  true;
	}

	void add(Element _el)
	{
		Element *newEl = new Element;
		*(newEl) = _el;

		set.push_back(newEl);
	}

	void add(Set _st)
	{
		Set *newSet = new Set;
		*newSet = _st;

		set.push_back(newSet);
	}

	void add(BaseClass *_bc)
	{
		set.push_back(_bc);
	}

	void pop_back()
	{
		set.pop_back();
	}

	void print()
	{

		cout << "{";
		for (int i = 0; i < set.size(); i++)
			set[i]->print();
		cout << "}";
	}

	void erase( BaseClass* _toComp)
	{
		vector<BaseClass*> newSet;
		for (int i = 0; i < set.size(); i++)
		{
			if (_toComp->getType() == set[i]->getType() && equals(_toComp, set[i]))
				continue;

			newSet.push_back(set[i]);
		}

		this->set = newSet;
	}

	vector<BaseClass*> getSet()
	{
		return this->set;
	}

	~Set()
	{
		for (int i = 0; i < set.size(); i++)
			delete set[i];
	}

	Set* unite(Set _set)
	{
		vector<BaseClass*> v1 = _set.getValue();
		vector<BaseClass*> v2 = this->set;
		vector<BaseClass*> v3;
		v3.reserve(v1.size() + v2.size());
		v3.insert(v3.end(), v1.begin(), v1.end());
		v3.insert(v3.end(), v2.begin(), v2.end());

		Set* res = new Set;
		res->setSet(v3);
		return res;
	}
  
	void setSet(vector<BaseClass*> _set)
	{
		this->set = _set;
	}


	type getType()
	{
		return SET;
	}

	size_t getSize()
	{
		return set.size();
	}
};




