#pragma once
#include "PRNG.h"

class NegativeBinomialModel : public Cloneable
{
private:
	PRNG* prng;
	int failNum;
	double probability;
public:
	NegativeBinomialModel(PRNG* prng, int failNum, double probability);
	NegativeBinomialModel(const NegativeBinomialModel* source);
	~NegativeBinomialModel();

	int next();
	void reset();

	NegativeBinomialModel* clone() override;
};

