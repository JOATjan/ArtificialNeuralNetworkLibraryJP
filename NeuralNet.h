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
	void FeedForward(std::vector<float> & inputValues);
	void SetFirstLayerValues(std::vector<float> & outputValues);
	void Backprophagate(std::vector<float> & outputValues, int size, float learningRate);
	void UpdateHiddenLayersInputEdges();
	void UpdateOutputLayerInputEdges(std::vector<float> & outputValues, int size, float learningRate);
	Layer * GetLastLayer();
	// TO DO void Backpropaghate();
	~NeuralNet();
private:
	std::vector<Layer*> layers;
};

