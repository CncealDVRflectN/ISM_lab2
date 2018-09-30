#include "pch.h"
#include "PoissonModel.h"
#include "algorithm"


PoissonModel::PoissonModel(PRNG* prng, double lambda)
{
	this->prng = (PRNG*)(prng->clone());
	this->lambda = lambda;
}

PoissonModel::PoissonModel(const PoissonModel* source)
{
	this->prng = (PRNG*)(source->prng->clone());
	this->lambda = source->lambda;
}

PoissonModel::~PoissonModel()
{
	delete prng;
}


int PoissonModel::next()
{
	double sum = exp(-lambda);
	double curProbability = sum;
	double randomValue = prng->next();
	int discreteValue = 0;

	while (randomValue > sum)
	{
		discreteValue++;
		curProbability *= lambda / discreteValue;
		sum += curProbability;
	}

	return discreteValue;
}

void PoissonModel::reset()
{
	this->prng->reset();
}

PoissonModel* PoissonModel::clone()
{
	return new PoissonModel(this);
}

