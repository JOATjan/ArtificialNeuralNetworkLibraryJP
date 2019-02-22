#pragma once
#include <vector>
#include "Layer.h"
class NeuralNet
{
public:
	NeuralNet();
	void AddLayer(Layer * layer);
	void FeedForward(float inputValues[]);
	void FeedFirstLayer(float * inputValues);
	// TO DO void Backpropaghate() ;
	~NeuralNet();
private:
	std::vector<Layer*> layers;
};

