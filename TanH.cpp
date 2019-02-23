#include "stdafx.h"
#include "TanH.h"


TanH::TanH()
{
}

double TanH::ComputeActivation(Vertex * vertex)
{
	double x = vertex->GetInput();
	return tanh(x);
}

void TanH::ComputeActivationInputDeriv(Vertex * vertex)
{
	float activationVal = vertex->GetActivation();
	float derivative = 1 - pow(activationVal, 2);
	vertex->SetActivationInputDeriv(derivative);
}


TanH::~TanH()
{
}
