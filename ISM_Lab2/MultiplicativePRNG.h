#pragma once
#include "PRNG.h"

class MultiplicativePRNG : public PRNG
{
private:
	long long module;
	long long seed;
	long long last;
	int multiplier;


	static long long mod(long long number, long long module);
public:
	MultiplicativePRNG(long long module, long long seed, int multiplier);
	MultiplicativePRNG(const MultiplicativePRNG* source);
	~MultiplicativePRNG();

	double next() override;
	void reset() override;
	MultiplicativePRNG* clone() override;
};

