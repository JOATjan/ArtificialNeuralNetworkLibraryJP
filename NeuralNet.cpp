#include "stdafx.h"
#include "NeuralNet.h"

NeuralNet::NeuralNet() {
}

void NeuralNet::AddLayer(Layer * layer) {
	layers.push_back(layer);
}

void NeuralNet::ConnectLayers()
{
	auto gen = std::mt19937{ std::random_device{}() };
	auto dist = std::normal_distribution<float>{ 0, 0.25 };
	for (int i = 0; i < layers.size() - 1; i++) {
		for (auto const & x : layers[i]->GetVertices()) {
			for (auto const & j : layers[i + 1]->GetVertices()) {
				float randomVal = dist(gen);
				new Edge(x, j, randomVal);
			}
		}
	}
}

Layer * NeuralNet::GetLastLayer()
{
	return layers[layers.size()-1];
}

void NeuralNet::FeedForward(std::vector<float> & inputValues) {
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

void NeuralNet::SetFirstLayerValues(std::vector<float> & inputValues) {
	Layer * inputLayer = layers[0];
	ActivationFunction * activationfunc = inputLayer->GetActivationFunction();
	int inputsNumber = inputLayer->GetVertices().size();
	for (int j = 0; j < inputsNumber; j++) {
		//TO DO Error when inputs number doesnt match - handling!
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
	/*
	1.Dla ostatniej warstwy :
	ComputeVertexErrorActivationDerivative(layer, expectedVals, size)
		Dla każdego neuronu z tej warstwy :
	ActivationFunction.ComputeActivationInputDeriv(vertex)
		dla kazdego input edge do neuronu nowa waga = stara waga - learningRate * vertex.ErrorActivationDeriv * vertex.ActivationInputDeriv * aktywacjapoprzedniegovvertexa*/
	MSE MSErrorComputer;
	Layer * outputLayer = layers.back();
	ActivationFunction * activationfunc = outputLayer->GetActivationFunction();
	MSErrorComputer.ComputeVertexErrorActivationDerivative(outputLayer, outputValues, size);
	for (auto const & i : outputLayer->GetVertices()) {
		float errActDeriv = i->GetErrorActivationDeriv();
		float actInputDeriv = i->GetActivationInputDeriv();
		float chainVals = learningRate * errActDeriv * actInputDeriv;
		for (auto const & j : i->GetInputEdges()) {
			float edgeInput = j->GetInputVertex()->GetActivation();
			float oldWeigth = j->GetWeight();
			float newWeigth = oldWeigth - chainVals * edgeInput;
		}
	}
}

void NeuralNet::UpdateHiddenLayersInputEdges()
{
	/*
	2. Dla pozostałych warstw:
	Dla kazdego neuronu:
	sumaEtotal = 0
	Dla każdego wychodzącego edge:
	sumaEtotal += wychodzacyEdge.ErrorActivationDeriv * wychodzacyEdge.ActivationInputDeriv * edge.weigth
	ActivationFunction.ComputeActivationInputDeriv(vertex)
	roznicaDoUpdateWeigth = sumaEtotal * vertex.ActivationInputDeriv*aktywacjapoprzedniegovvertexa
	Dla każdego wchodzącego edge:
	nowa waga = stara waga - learningrate * roznicaDoUpdateWeigth
	3. Jeżeli to pierwsza warstwa to skończ.
	*/

	for (int i = layers.size() - 2; i > 0; i--) {
		ActivationFunction * activationFunc = layers[i]->GetActivationFunction();
		for (auto const & j : layers[i]->GetVertices()) {
			activationFunc->ComputeActivationInputDeriv(j);
			float sumETotal = 0.0;
			for (auto const & k : j->GetOutputEdges()) {
				float errActDeriv = k->GetOutputVertex()->GetErrorActivationDeriv();
				float actInputDeriv = k->GetOutputVertex()->GetActivationInputDeriv();
				sumETotal += errActDeriv * actInputDeriv * k->GetWeight();
			}
			for (auto const & k : j->GetInputEdges()) {
				float actInputDeriv = j->GetActivationInputDeriv();
				float edgeInput = k->GetInputVertex()->GetActivation();
				float oldWeigth = k->GetWeight();
				float newWeigth = oldWeigth - sumETotal * edgeInput * actInputDeriv;
			}
			j->SetErrorActivationDeriv(sumETotal);
		}
	}
}

NeuralNet::~NeuralNet() {

}
