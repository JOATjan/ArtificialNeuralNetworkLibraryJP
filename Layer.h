#pragma once
#include <list>
#include "Vertex.h"
#include "ActivationFunction.h"
class Layer
{
public:
	Layer(int verNum, ActivationFunction * activationType);
	void AddVertices(int verNum);
	std::list<Vertex*> GetVertices();
	~Layer();
private:
	std::list<Vertex*> layerVertices;
	ActivationFunction* activationFunction;
};

