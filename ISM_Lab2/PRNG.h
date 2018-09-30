#pragma once
#include "Cloneable.h"

class PRNG : public Cloneable
{
public:
	virtual double next() = 0;
	virtual void reset() = 0;
};

