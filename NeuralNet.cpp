#include "stdafx.h"
#include "NeuralNet.h"

NeuralNet::NeuralNet()
{
}

void NeuralNet::AddLayer(Layer * layer)
{
	layers.push_back(layer);
}

void NeuralNet::FeedForward(float inputValues[])
{
	FeedFirstLayer(inputValues);
	// TO DO here end feed forward.
}

void NeuralNet::FeedFirstLayer(float * inputValues)
{
	int valuePos = 0;
	for (auto const& i : layers.front()->GetVertices()) {
		i->SetInput(inputValues[valuePos]);
		valuePos++;
	}
}


NeuralNet::~NeuralNet()
{
}
