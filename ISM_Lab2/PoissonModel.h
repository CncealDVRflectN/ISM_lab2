#pragma once
#include "PRNG.h"

class PoissonModel : public Cloneable
{
private:
	PRNG* prng;
	double lambda;
public:
	PoissonModel(PRNG* prng, double lambda);
	PoissonModel(const PoissonModel* source);
	~PoissonModel();

	int next();
	void reset();

	PoissonModel* clone() override;
};

