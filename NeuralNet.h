#pragma once
#include <vector>
#include "Layer.h"
#include "WeightedSum.h"

class NeuralNet {
public:
	NeuralNet();
	void AddLayer(Layer * layer);
	void FeedForward(float inputValues[]);
	void SetFirstLayerValues(float * inputValues);
	//void FeedFirstLayer(float * inputValues);
	// TO DO void Backpropaghate();
	~NeuralNet();
private:
	std::vector<Layer*> layers;
};

