#pragma once
#include "../../Structure/Vertex.h"
#include "../../Structure/Edge.h"
class WeightedSum {
public:
	WeightedSum();
	float ComputeInput(Vertex * vertex);
	float ComputeError(Vertex * vertex);
	~WeightedSum();
};

