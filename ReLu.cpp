#include "stdafx.h"
#include "ReLu.h"


ReLu::ReLu() {
}

double ReLu::ComputeActivation(Vertex * vertex) {
	if (vertex->GetInput() <= 0)
		return 0;
	else
		return vertex->GetInput();
}

void ReLu::ComputeActivationInputDeriv(Vertex * vertex)
{
	if (vertex->GetInput() <= 0)
		vertex->SetActivationInputDeriv(0);
	else
		vertex->SetActivationInputDeriv(1);
}


ReLu::~ReLu() {
}
