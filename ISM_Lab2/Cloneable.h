#pragma once

class Cloneable
{
public:
	virtual Cloneable* clone() = 0;
};