#include "pch.h"
#include "NegativeBinomialModel.h"
#include "algorithm"


NegativeBinomialModel::NegativeBinomialModel(PRNG* prng, int failNum, double probability)
{
	this->prng = (PRNG*)(prng->clone());
	this->failNum = failNum;
	this->probability = probability;
}

NegativeBinomialModel::NegativeBinomialModel(const NegativeBinomialModel* source)
{
	this->prng = (PRNG*)(source->prng->clone());
	this->failNum = source->failNum;
	this->probability = source->probability;
}

NegativeBinomialModel::~NegativeBinomialModel()
{
	delete prng;
}


int NegativeBinomialModel::next()
{
	double sum = pow(1.0 - probability, failNum);
	double curProbability = sum;
	double randomValue = prng->next();
	int discreteValue = 0;

	while (randomValue > sum)
	{
		discreteValue++;
		curProbability *= (discreteValue + failNum - 1) * probability / discreteValue;
		sum += curProbability;
	}

	return discreteValue;
}

void NegativeBinomialModel::reset()
{
	this->prng->reset();
}

NegativeBinomialModel* NegativeBinomialModel::clone()
{
	return new NegativeBinomialModel(this);
}

