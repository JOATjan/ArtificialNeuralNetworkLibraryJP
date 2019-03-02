#include "stdafx.h"
#include "Coach.h"


Coach::Coach()
{
}

void Coach::Train(NeuralNet nn, std::vector<std::vector<float>> & trainingInput, std::vector<std::vector<float>> & trainingOutput, int epochsNumber, float learningRate,float errorMargin)
{
	for (int i = 1; i <= epochsNumber; i++) {
		float epochAccuracy = 0.0;
		for (int j = 0; j < trainingInput.size(); j++) {
			nn.FeedForward(trainingInput[j]);
			epochAccuracy += EvaluateAccuracy(errorMargin,nn.GetLastLayer(), trainingOutput[j]);
			nn.Backprophagate(trainingOutput[j], trainingOutput.size(), learningRate);
		}
		epochAccuracy = epochAccuracy / trainingInput.size();
		std::cout << "Epoch nr: " << i << "epoch accuracy: "<< epochAccuracy;
	}
}

void Coach::Evaluate(NeuralNet nn, std::vector<float>& testInput, std::vector<float>& testOutput)
{

}

int Coach::EvaluateAccuracy(float errorMargin, Layer * outputLayer, std::vector<float> & trainingOutput)
{
	for (int i = 0; i < trainingOutput.size(); i++) {
		float output = outputLayer->GetVertices()[i]->GetActivation();
		float expVal = trainingOutput[i];
		if (abs(output - expVal) < errorMargin)
			return 1;
		else
			return 0;
			
		
}
	}
}


Coach::~Coach()
{
}
