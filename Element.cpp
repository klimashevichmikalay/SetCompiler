#include "Element.h"

Element::Element() {};

Element::Element(string _value)
{
	value = std::stoi(_value);
}

bool Element::equals(BaseClass* leftEl, BaseClass* rightEl)
{
	if (static_cast<Element*>(leftEl)->getValue() == static_cast<Element*>(rightEl)->getValue())
		return true;

	return false;
}

bool Element::operator==(const int &i)
{
	if (this->value == i)
		return true;

	return false;
}

void Element::operator=(const int &i)
{
	this->value = i;
}


void Element::operator+=(const int &i)
{
	this->value += i;
}

void Element::operator-=(const int &i)
{
	this->value -= i;
}

int Element::getValue()
{
	return value;
}

void Element::setValue(string _value)
{
	value = std::stoi(_value);
}

void Element::print()
{
	cout << value << " ";
}

Element::type Element::getType()
{
	return ELEMENT;
}