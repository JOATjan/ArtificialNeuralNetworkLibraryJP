#pragma once
#include "Vertex.h"
class WeightedSum {
public:
	WeightedSum();
	float ComputeInput(Vertex * vertex);
	float ComputeError(Vertex * vertex);
	~WeightedSum();
};

