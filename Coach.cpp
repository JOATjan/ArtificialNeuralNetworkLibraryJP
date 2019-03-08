#include "stdafx.h"
#include "Coach.h"
#include <iostream>


Coach::Coach() {
}

void Coach::Train(NeuralNet * nn, std::vector<std::vector<float>> & trainingInput, std::vector<std::vector<float>> & trainingOutput, int epochsNumber, float learningRate,float errorMargin) {
	for (int i = 1; i <= epochsNumber; i++) {
		float epochAccuracy = 0.0;
		for (int j = 0; j < trainingInput.size(); j++) {
			nn->FeedForward(trainingInput[j]);
			epochAccuracy += EvaluateAccuracy(errorMargin,nn->GetLastLayer(), trainingOutput[j]);
			nn->Backprophagate(trainingOutput[j], trainingOutput[j].size(), learningRate);
		}
		epochAccuracy = epochAccuracy / (float)trainingInput.size();
		std::cout << "Epoch nr: " << i << " epoch accuracy: "<< epochAccuracy << std::endl;
	}
}

void Coach::Evaluate(NeuralNet nn, std::vector<std::vector<float>> & testInput, std::vector<std::vector<float>> & testOutput, float errorMargin) {
	float meanAccuracy = 0.0;
	for (int j = 0; j < testInput.size(); j++) {
		nn.FeedForward(testInput[j]);
		meanAccuracy += EvaluateAccuracy(errorMargin, nn.GetLastLayer(), testOutput[j]);
	}
	meanAccuracy = meanAccuracy / testInput.size();
	std::cout << "Mean Network accuracy: " << meanAccuracy << std::endl; 
}

int Coach::EvaluateAccuracy(float errorMargin, Layer * outputLayer, std::vector<float> & trainingOutput) {
	for (int i = 0; i < trainingOutput.size(); i++) {
		float output = outputLayer->GetVertices()[i]->GetActivation();
		float expVal = trainingOutput[i];
		//std::cout << "Net Output = " << output << " Expected = " << expVal<< std::endl;
		if (abs(output - expVal) < errorMargin)
			return 1;
		else
			return 0;
	}
}


Coach::~Coach() {
}
