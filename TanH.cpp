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


TanH::~TanH()
{
}
