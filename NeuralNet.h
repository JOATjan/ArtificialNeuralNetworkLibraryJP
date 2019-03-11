#pragma once
#include <vector>
#include "Layer.h"
#include "WeightedSum.h"
#include "MSE.h"
#include "Edge.h"
#include <random>
#include <time.h>

class NeuralNet {
public:
	NeuralNet();
	void FeedForward(std::vector<float> & inputValues);
	void SetFirstLayerValues(std::vector<float> & outputValues);
	void Backprophagate(std::vector<float> & outputValues, int size, float learningRate);
	void UpdateOutputLayerInputEdges(std::vector<float> & outputValues, int size, float learningRate);
	void UpdateHiddenLayersInputEdges();
	void AddLayer(Layer * layer);
	void ConnectLayers();
	Layer * GetLastLayer();
	~NeuralNet();
private:
	std::vector<Layer*> layers;
};

