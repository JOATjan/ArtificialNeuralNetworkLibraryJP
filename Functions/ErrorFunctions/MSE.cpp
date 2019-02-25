#include "stdafx.h"
#include "MSE.h"
#include "math.h"

MSE::MSE() {
}

double MSE::ComputeVertexError(Vertex * vertex, double expectedValue) {
	return 1.0/2 * pow(expectedValue - vertex->GetActivation(),2);
}

double MSE::ComputeTotalError(Layer * layer, double expVals[], int size)
{
	double sum = 0.0;
	for (int i = 0; i < size; i++) {
		Vertex * vertex = layer->GetVertices()[i];
		sum += ComputeVertexError(vertex,expVals[i]);
	}
	return sum;
}

void MSE::ComputeVertexErrorActivationDerivative(Layer * layer, float expVals[], int size)
{
	for (int i = 0; i < size; i++) {
		Vertex * vertex = layer->GetVertices()[i];
		float derivative = vertex->GetActivation() - expVals[i];
		vertex->SetErrorActivationDeriv(derivative);
	}
}


MSE::~MSE() {
}
