#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "BaseClass.h"

using namespace std;

class Element: public BaseClass
{
private:

	int value; 

public:

	Element() {};

	Element(string _value)
	{
		value = std::stoi(_value);
	}

    bool equals(BaseClass* leftEl, BaseClass* rightEl)
	{
		if (static_cast<Element*>(leftEl)->getValue() == static_cast<Element*>(rightEl)->getValue())
			return true;

		return false;
	}

	bool operator==(const int &i)
	{
		if (this->value == i)
			return true;

		return false;
	}

	void operator=(const int &i)
	{
		this->value = i;
	}
	

	void operator+=(const int &i)
	{
		this->value += i;
	}
	
	void operator-=(const int &i)
	{
		this->value -= i;
	}	

	int getValue()
	{
		return value;
	}

	void setValue(string _value)
	{
		value = std::stoi(_value);
	}

	void print()
	{
		cout << value << " ";
	}

	type getType()
	{
		return ELEMENT;
	}
};