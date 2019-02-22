#pragma once
#include "Vertex.h"
class ErrorFunction
{
public:
	ErrorFunction();
	virtual float Error(Vertex * vertex) = 0;
	~ErrorFunction();
};

