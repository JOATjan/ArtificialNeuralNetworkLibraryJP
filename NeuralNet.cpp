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
	ActivationFunction * activationfunc = layers[0]->GetActivationFunction();
	int inputsNumber = inputLayer->GetVertices().size();
	for (int j = 0; j < inputsNumber; j++) {
		//TO DO Error when inputs number doesnt match - handling!
		Vertex * currentVertex = inputLayer->GetVertices()[j];
		currentVertex->SetInput(inputValues[j]);
		float activation = activationfunc->ComputeActivation(currentVertex);
		currentVertex->SetActivation(activation);
	}
}

void NeuralNet::Backprophagation(float expectedValues[],float learningRate)
{
	/*
	1.Dla ostatniej warstwy:
		ComputeVertexErrorActivationDerivative(layer,expectedVals,size)
		Dla każdego neuronu z tej warstwy:
			ActivationFunction.ComputeActivationInputDeriv(vertex)
			dla kazdego input edge do neuronu nowa waga = stara waga - learningRate* vertex.ErrorActivationDeriv * vertex.ActivationInputDeriv * vertex.GetInput
	2. Dla pozostałych warstw:
		Dla kazdego neuronu:
			sumaEtotal = 0
			Dla każdego wychodzącego edge:
				sumaEtotal += wychodzacyEdge.ErrorActivationDeriv * wychodzacyEdge.ActivationInputDeriv * edge.weigth
			ActivationFunction.ComputeActivationInputDeriv(vertex)
			roznicaDoUpdateWeigth = sumaEtotal * vertex.ActivationInputDeriv*vertex.GetInput
			Dla każdego wchodzącego edge:
				nowa waga = stara waga - learningrate * roznicaDoUpdateWeigth
	3. Jeżeli to pierwsza warstwa to skończ.
	*/
}


NeuralNet::~NeuralNet() {

}
