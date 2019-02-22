#pragma once
#include "Vertex.h"
class ActivationFunction
{
public:
	ActivationFunction();
	virtual double ComputeActivation(Vertex * vertex) = 0;
	~ActivationFunction();
};

