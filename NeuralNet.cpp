#include "stdafx.h"
#include "NeuralNet.h"

NeuralNet::NeuralNet() {
}

void NeuralNet::AddLayer(Layer * layer) {
	layers.push_back(layer);
}

void NeuralNet::FeedForward(float inputValues[]) {
	WeightedSum weightedSumComputer;
	SetFirstLayerValues(inputValues);
	for (int i = 1; i < layers.size()-1;i++) {
		ActivationFunction * activationfunc = layers[i]->GetActivationFunction();
		for (auto const & j : layers[i]->GetVertices()) {
			float input = weightedSumComputer.ComputeInput(j);
			j->SetInput(input);
			float activation = activationfunc->ComputeActivation(j);
			j->SetActivation(activation);
		}
	}
}

void NeuralNet::SetFirstLayerValues(float * inputValues) {
	Layer * inputLayer = layers[0];
	int inputsNumber = inputLayer->GetVertices().size();
	for (int j = 0; j < inputsNumber; j++) {
		//TO DO Error when inputs number doesnt match - handling!
		Vertex * currentVertex = inputLayer->GetVertices()[j];
		currentVertex->SetInput(inputValues[j]);
		currentVertex->SetActivation(currentVertex->GetInput());
	}
}


NeuralNet::~NeuralNet() {

}
