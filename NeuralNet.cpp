#include "stdafx.h"
#include "NeuralNet.h"

NeuralNet::NeuralNet() {
}

void NeuralNet::FeedForward(std::vector<float> & inputValues) {
	WeightedSum weightedSumComputer;
	SetFirstLayerValues(inputValues);
	for (int i = 1; i < layers.size(); i++) {
		ActivationFunction * activationfunc = layers[i]->GetActivationFunction();
		for (auto const & j : layers[i]->GetVertices()) {
			float input = weightedSumComputer.ComputeInput(j);
			j->SetInput(input);
			float activation = activationfunc->ComputeActivation(j);
			j->SetActivation(activation);
		}
	}
}

void NeuralNet::SetFirstLayerValues(std::vector<float> & inputValues) {
	Layer * inputLayer = layers[0];
	ActivationFunction * activationfunc = inputLayer->GetActivationFunction();
	int inputsNumber = inputLayer->GetVertices().size();
	for (int j = 0; j < inputsNumber; j++) {
		Vertex * currentVertex = inputLayer->GetVertices()[j];
		currentVertex->SetInput(inputValues[j]);
		float activation = activationfunc->ComputeActivation(currentVertex);
		currentVertex->SetActivation(activation);
	}
}

void NeuralNet::Backprophagate(std::vector<float> & outputValues, int size, float learningRate)
{
	UpdateOutputLayerInputEdges(outputValues, size, learningRate);
	UpdateHiddenLayersInputEdges();
}

void NeuralNet::UpdateOutputLayerInputEdges(std::vector<float> & outputValues, int size, float learningRate)
{
	MSE MSErrorComputer;
	Layer * outputLayer = layers.back();
	ActivationFunction * activationfunc = outputLayer->GetActivationFunction();
	MSErrorComputer.ComputeVertexErrorActivationDerivative(outputLayer, outputValues, size);
	for (auto const & i : outputLayer->GetVertices()) {
		activationfunc->ComputeActivationInputDeriv(i);
		float errActDeriv = i->GetErrorActivationDeriv();
		float actInputDeriv = i->GetActivationInputDeriv();
		float chainVals = learningRate * errActDeriv * actInputDeriv;
		for (auto const & j : i->GetInputEdges()) {
			float edgeInput = j->GetInputVertex()->GetActivation();
			float oldWeight = j->GetWeight();
			j->SetOldWeight(oldWeight);
			float newWeight = oldWeight - chainVals * edgeInput;
			j->SetWeight(newWeight);
		}
	}
}

void NeuralNet::UpdateHiddenLayersInputEdges()
{
	for (int i = layers.size() - 2; i > 0; i--) {
		ActivationFunction * activationFunc = layers[i]->GetActivationFunction();
		for (auto const & j : layers[i]->GetVertices()) {
			activationFunc->ComputeActivationInputDeriv(j);
			float sumETotal = 0.0;
			for (auto const & k : j->GetOutputEdges()) {
				float errActDeriv = k->GetOutputVertex()->GetErrorActivationDeriv();
				float actInputDeriv = k->GetOutputVertex()->GetActivationInputDeriv();
				sumETotal += errActDeriv * actInputDeriv * k->GetOldWeight();
			}
			for (auto const & k : j->GetInputEdges()) {
				float actInputDeriv = j->GetActivationInputDeriv();
				float edgeInput = k->GetInputVertex()->GetActivation();
				float oldWeight = k->GetWeight();
				k->SetOldWeight(oldWeight);
				float newWeight = oldWeight - sumETotal * edgeInput * actInputDeriv;
				k->SetWeight(newWeight);
			}
			j->SetErrorActivationDeriv(sumETotal);
		}
	}
}

void NeuralNet::AddLayer(Layer * layer) {
	layers.push_back(layer);
}

void NeuralNet::ConnectLayers() {
	auto gen = std::mt19937{ std::random_device{}() };
	std::uniform_real_distribution<> dist(-1, 1);
	for (int i = 0; i < layers.size() - 1; i++) {
		for (auto const & x : layers[i]->GetVertices()) {
			for (auto const & j : layers[i + 1]->GetVertices()) {
				float randomVal = dist(gen);
				new Edge(x, j, randomVal);
			}
		}
	}
}

Layer * NeuralNet::GetLastLayer() {
	return layers[layers.size()-1];
}

NeuralNet::~NeuralNet() {

}
