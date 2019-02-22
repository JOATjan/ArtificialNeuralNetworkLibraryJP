#pragma once
#include "ErrorFunction.h"
class MSE : public ErrorFunction
{
public:
	MSE();
	double Error(Vertex * vertex, double expectedValue);
	~MSE();
};

