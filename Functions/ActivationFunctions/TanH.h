#pragma once
#include "ActivationFunction.h"
class TanH: public ActivationFunction
{
public:
	TanH();
	double ComputeActivation(Vertex * vertex);
	void ComputeActivationInputDeriv(Vertex * vertex);
	~TanH();
};

