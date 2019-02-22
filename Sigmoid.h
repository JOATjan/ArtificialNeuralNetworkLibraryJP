#pragma once
#include "ActivationFunction.h"
#include "cmath"
class Sigmoid: public ActivationFunction
{
public:
	Sigmoid();
	double ComputeActivation(Vertex * vertex);
	~Sigmoid();
};

