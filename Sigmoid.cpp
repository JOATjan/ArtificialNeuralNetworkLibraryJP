#include "stdafx.h"
#include "Sigmoid.h"


Sigmoid::Sigmoid() {
}

double Sigmoid::ComputeActivation(Vertex * vertex) {
	double x = vertex->GetInput();
	return 1 / (1 + exp(-x));
}


Sigmoid::~Sigmoid() {
}
