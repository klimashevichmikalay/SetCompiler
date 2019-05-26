#include "Set.h"

BaseClass* Set::getAt(int p)
{
	return set[p];
}

vector<BaseClass*> Set::getValue()
{
	return this->set;
}

bool  Set::equals(BaseClass* leftEl, BaseClass* rightEl)
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

void Set::add(Element _el)
{
	Element *newEl = new Element;
	*(newEl) = _el;

	set.push_back(newEl);
}

void Set::add(Set _st)
{
	Set *newSet = new Set;
	*newSet = _st;

	set.push_back(newSet);
}

void Set::add(BaseClass *_bc)
{
	set.push_back(_bc);
}

void Set::pop_back()
{
	set.pop_back();
}

void Set::print()
{
	cout << "{ ";
	for (int i = 0; i < set.size(); i++)
		set[i]->print();
	cout << " }";
}

void Set::erase(BaseClass* _toComp)
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

vector<BaseClass*> Set::getSet()
{
	return this->set;
}

Set::~Set()
{
	for (int i = 0; i < set.size(); i++)
		delete set[i];
}

Set* Set::difference(Set* _set)
{
	vector<BaseClass*> res = set;
	vector<BaseClass*> subtrahend = _set->getValue();

	for (int i = 0; i < subtrahend.size(); i++)
		for (int j = 0; j < res.size(); j++)
		{
			if (equals(subtrahend[i], res[j]))
			{
				res.erase(res.begin() + j);
				break;
			}
		}

	Set* setRes = new Set();
	setRes->setSet(res);
	return setRes;
}

Set* Set::intersection(Set* _set)
{
	vector<BaseClass*> res;
	vector<BaseClass*> subtrahend = _set->getValue();

	for (int i = 0; i < subtrahend.size(); i++)
		for (int j = 0; j < set.size(); j++)
		{
			if (equals(subtrahend[i], set[j]))
			{
				res.push_back(set[j]);
				break;
			}
		}

	Set* setRes = new Set();
	setRes->setSet(res);
	return setRes;
}

Set* Set::ÒartesianMult(Set* _set)
{
	vector<BaseClass*> res;
	vector<BaseClass*> subtrahend = _set->getValue();

	for (int i = 0; i < subtrahend.size(); i++)
		for (int j = 0; j < set.size(); j++)
		{
			Set* cur—ortege = new Set();
			cur—ortege->add(subtrahend[i]);
			cur—ortege->add(set[j]);
			res.push_back(cur—ortege);
		}

	for (int i = 0; i < set.size(); i++)
		for (int j = 0; j < subtrahend.size(); j++)
		{
			Set* cur—ortege = new Set();
			cur—ortege->add(set[i]);
			cur—ortege->add(subtrahend[j]);
			res.push_back(cur—ortege);
		}

	Set* setRes = new Set();
	setRes->setSet(res);
	//setRes->unique();
	return setRes;
}

Set* Set::unite(Set* _set)
{
	vector<BaseClass*> v1 = _set->getValue();
	vector<BaseClass*> v2 = this->set;
	vector<BaseClass*> v3;
	v3.reserve(v1.size() + v2.size());
	v3.insert(v3.end(), v1.begin(), v1.end());
	v3.insert(v3.end(), v2.begin(), v2.end());

	Set* res = new Set;
	res->setSet(v3);
	return res;
}

void Set::unique()
{
	if (set.size() < 2)
		return;

	for (int i = 0; i < set.size() - 1; i++)
		for (int j = i + 1; j < set.size(); j++)
			if (equals(set[i], set[j]))
			{
				set.erase(set.begin() + j);
				if (i > 0)	i--;
				if (j > 0) j--;
			}
}

void Set::setSet(vector<BaseClass*> _set)
{
	this->set = _set;
}

Set::type Set::getType()
{
	return SET;
}

size_t Set::getSize()
{
	return set.size();
}




