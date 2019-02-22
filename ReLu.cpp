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


ReLu::~ReLu() {
}
