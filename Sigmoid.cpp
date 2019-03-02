#include "stdafx.h"
#include "Sigmoid.h"


Sigmoid::Sigmoid() {
}

double Sigmoid::ComputeActivation(Vertex * vertex) {
	double x = vertex->GetInput();
	return 1 / (1 + exp(-x));
}

void Sigmoid::ComputeActivationInputDeriv(Vertex * vertex)
{
	float activationVal = vertex->GetActivation();
	float derivative = activationVal * (1 - activationVal);
	vertex->SetActivationInputDeriv(derivative);
}


Sigmoid::~Sigmoid() {
}
