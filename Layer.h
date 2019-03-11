#pragma once
#include <vector>
#include "Vertex.h"
#include "ActivationFunction.h"

class Layer {
public:
	Layer(int verNum, ActivationFunction * activationType);
	void AddVertices(int verNum);
	ActivationFunction* GetActivationFunction();
	std::vector<Vertex*> GetVertices();
	~Layer();
protected:
	std::vector<Vertex*> layerVertices;
	float eror = 0.0;
	ActivationFunction* activationFunction = nullptr;
};

