#pragma once
#include "../../Structure/Vertex.h"

class ErrorFunction {
public:
	ErrorFunction();
	virtual double ComputeVertexError(Vertex * vertex,double expectedValues) = 0;
	~ErrorFunction();
};

