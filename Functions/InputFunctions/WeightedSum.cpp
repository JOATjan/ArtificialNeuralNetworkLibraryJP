#include "stdafx.h"
#include "WeightedSum.h"
#include "Vertex.h"
#include "Edge.h"


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

//float WeightedSum::ComputeError(Vertex * vertex) {
//	float sum = 0.0f;
//	for (auto const& i : vertex->GetOutputEdges()) {
//		float weight = i->GetWeight();
//		float edgeOutput = (i->GetOutputVertex())->GetError();
//		sum += weight * edgeOutput;
//	}
//}

WeightedSum::~WeightedSum() {
}
