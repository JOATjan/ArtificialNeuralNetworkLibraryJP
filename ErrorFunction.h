#pragma once
#include "Vertex.h"
class ErrorFunction {
public:
	ErrorFunction();
	virtual float ComputeError(Vertex * vertex) = 0;
	~ErrorFunction();
};

