#pragma once

class BaseClass
{
public:

	enum type { ELEMENT, SET, BASE };

	virtual void print() = 0;

	virtual	type getType() = 0;

    virtual	bool equals(BaseClass*, BaseClass*) = 0;

	virtual BaseClass* getAt(int p) { return nullptr; };
};