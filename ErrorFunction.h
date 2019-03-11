#pragma once
#include "Vertex.h"

class ErrorFunction {
public:
	ErrorFunction();
	virtual double ComputeVertexError(Vertex * vertex,double expectedValues) = 0;
	~ErrorFunction();
};

