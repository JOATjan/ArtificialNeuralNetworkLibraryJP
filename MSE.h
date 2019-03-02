#pragma once
#include "ErrorFunction.h"
#include "Layer.h"
#include <vector>

class MSE : public ErrorFunction {
public:
	MSE();
	double ComputeVertexError(Vertex * vertex, double expectedValue);
	double ComputeTotalError(Layer * layer, std::vector<float> & outputValues, int size);
	void ComputeVertexErrorActivationDerivative(Layer * layer, std::vector<float> & outputValues, int size);
	~MSE();
};

