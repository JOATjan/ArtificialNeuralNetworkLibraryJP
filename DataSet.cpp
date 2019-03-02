#include "stdafx.h"
#include "DataSet.h"


DataSet::DataSet()
{
	firstTimeRand = true;
}

void DataSet::Split(std::vector<std::vector<float>> & InputSet, std::vector<std::vector<float>> & OutputSet, float trainingSetRatio)
{
	// TO DO: check if input and output sets are the same size. 
	for (int i = 0; i < InputSet.size(); i++) {
		if (RandomSplitter() > trainingSetRatio) {
			testInputs.push_back(InputSet[i]);
			testOutputs.push_back(OutputSet[i]);
		}
		else {
			trainingInputs.push_back(InputSet[i]);
			trainingOutputs.push_back(OutputSet[i]);
		}
	
	}
}

float DataSet::RandomSplitter()
{
	if (firstTimeRand) {
		srand(time(NULL));
		firstTimeRand = false;
	}
	float random = rand() % ((1 + 1));
	return random;
}


DataSet::~DataSet()
{
}
