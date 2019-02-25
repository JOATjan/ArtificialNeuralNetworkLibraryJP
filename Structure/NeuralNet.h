#pragma once
#include <vector>
#include "Layer.h"
#include "WeightedSum.h"
#include "MSE.h"
#include "Edge.h"

class NeuralNet {
public:
	NeuralNet();
	void AddLayer(Layer * layer);
	void FeedForward(float inputValues[]);
	void SetFirstLayerValues(float * inputValues);
	void Backprophagation(float expectedValues[], int size, float learningRate);
	void UpdateHiddenLayersInputEdges();
	void UpdateOutputLayerInputEdges(float * expVals, int size, float learningRate);
	// TO DO void Backpropaghate();
	~NeuralNet();
private:
	std::vector<Layer*> layers;
};

