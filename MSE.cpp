#include "stdafx.h"
#include "MSE.h"
#include "math.h"

MSE::MSE() {
}

double MSE::ComputeVertexError(Vertex * vertex, double expectedValue) {
	return 1.0/2 * pow(expectedValue - vertex->GetActivation(),2);
}

double MSE::ComputeTotalError(Layer * layer, std::vector<float> & outputValues, int size)
{
	double sum = 0.0;
	for (int i = 0; i < size; i++) {
		Vertex * vertex = layer->GetVertices()[i];
		sum += ComputeVertexError(vertex,outputValues[i]);
	}
	return sum;
}

void MSE::ComputeVertexErrorActivationDerivative(Layer * layer, std::vector<float> & outputValues, int size)
{
	for (int i = 0; i < size; i++) {
		Vertex * vertex = layer->GetVertices()[i];
		float derivative = vertex->GetActivation() - outputValues[i];
		vertex->SetErrorActivationDeriv(derivative);
	}
}


MSE::~MSE() {
}
