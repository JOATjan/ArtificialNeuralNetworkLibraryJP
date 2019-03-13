#pragma once
#include "ErrorFunction.h"
#include "../../Structure/Layer.h"
#include <vector>

class MSE : public ErrorFunction {
public:
	MSE();
	double ComputeTotalError(Layer * layer, std::vector<float> & outputValues, int size);
	void ComputeVertexErrorActivationDerivative(Layer * layer, std::vector<float> & outputValues, int size);
	double ComputeVertexError(Vertex * vertex, double expectedValue);
	~MSE();
};

