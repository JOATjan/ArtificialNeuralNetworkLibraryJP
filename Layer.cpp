#include "stdafx.h"
#include "Layer.h"

Layer::Layer(int verNum, ActivationFunction* activationType)
{
	AddVertices(verNum);
	activationFunction = activationType;

}

void Layer::AddVertices(int verNum)
{
	for(int i = 0; i < verNum; i++)
	{
		Vertex * vertex = new Vertex();
		layerVertices.push_back(vertex);
	}
}

std::list<Vertex*> Layer::GetVertices()
{
	return layerVertices;
}

Layer::~Layer()
{
}
