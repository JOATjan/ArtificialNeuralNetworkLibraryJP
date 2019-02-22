#pragma once
#include "ActivationFunction.h"

class ReLu: public ActivationFunction {
public:
	ReLu();
	double ComputeActivation(Vertex * vertex);
	~ReLu();
};

