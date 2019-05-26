#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "BaseClass.h"

using namespace std;

class Element : public BaseClass
{
private:

	int value;

public:

	Element();
	Element(string _value);	
	bool operator==(const int &i);
	void operator=(const int &i);
	void operator+=(const int &i);
	void operator-=(const int &i);
	bool equals(BaseClass* leftEl, BaseClass* rightEl);
	int getValue();
	void setValue(string _value);
	void print();
	type getType();
};