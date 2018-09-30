#include "pch.h"
#include "MultiplicativePRNG.h"

MultiplicativePRNG::MultiplicativePRNG(long long module, long long seed, int multiplier)
{
	this->module = module;
	this->multiplier = multiplier;
	this->seed = seed;
	this->last = seed;
}

MultiplicativePRNG::MultiplicativePRNG(const MultiplicativePRNG* source)
{
	this->module = source->module;
	this->multiplier = source->multiplier;
	this->seed = source->seed;
	this->last = source->last;
}

MultiplicativePRNG::~MultiplicativePRNG()
= default;

double MultiplicativePRNG::next()
{
	last = (last * multiplier) % module;
	return (double)last / module;
}

void MultiplicativePRNG::reset()
{
	last = seed;
}

MultiplicativePRNG* MultiplicativePRNG::clone()
{
	return new MultiplicativePRNG(this);
}
