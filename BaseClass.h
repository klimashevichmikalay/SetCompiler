#pragma once
class BaseClass
{
public:

    enum type { VOID, ELEMENT, SET };

	virtual void print() = 0;

	virtual	type getType() = 0;

	virtual	bool equals(BaseClass*, BaseClass*) = 0;

	virtual BaseClass* getAt(int p) { return nullptr; };
};