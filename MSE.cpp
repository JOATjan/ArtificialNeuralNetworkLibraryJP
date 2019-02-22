#include "stdafx.h"
#include "MSE.h"
#include "math.h"

MSE::MSE() {
}

double MSE::Error(Vertex * vertex, double expectedValue) {
	return 1.0/2 * pow(expectedValue - vertex->GetActivation(),2);
}


MSE::~MSE() {
}
