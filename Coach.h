#pragma once
#include "NeuralNet.h"
#include <vector>
#include <math.h>
#include <iostream>

class Coach {
public:
	Coach();
	void Train(NeuralNet nn, std::vector<std::vector<float>> & trainingInput, std::vector<std::vector<float>> & trainingOutput, int epochsNumber, float learningRate, float errorMargin);
	void Evaluate(NeuralNet nn, std::vector<std::vector<float>> & testInput, std::vector<std::vector<float>> & testOutput, float errorMargin);
	int EvaluateAccuracy(float errorMargin, Layer * outputLayer, std::vector<float> & trainingOutput);
	~Coach();
};

