#include "stdafx.h"
#include "WeightedSum.h"

WeightedSum::WeightedSum() {
}

float WeightedSum::ComputeInput(Vertex * vertex) {
	float sum = 0.0f;
	for (auto const& i : vertex->GetInputEdges()) {
		float weight = i->GetWeight();
		float edgeInput = (i->GetInputVertex())->GetActivation();
		sum += weight * edgeInput;
	}
	return sum;
}

WeightedSum::~WeightedSum() {
}
