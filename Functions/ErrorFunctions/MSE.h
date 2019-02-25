#pragma once
#include "ErrorFunction.h"
#include "Layer.h"

class MSE : public ErrorFunction {
public:
	MSE();
	double ComputeVertexError(Vertex * vertex, double expectedValue);
	double ComputeTotalError(Layer * layer, double expectedValues[], int size);
	void ComputeVertexErrorActivationDerivative(Layer * layer, float expectedValues[], int size);
	~MSE();
};

