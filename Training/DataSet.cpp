#include "stdafx.h"
#include "DataSet.h"

DataSet::DataSet() {
}

void DataSet::Split(std::vector<std::vector<float>> & InputSet, std::vector<std::vector<float>> & OutputSet, float trainingSetRatio) {
	auto gen = std::mt19937{ std::random_device {}() };
	std::uniform_real_distribution<> dist(0.0,1.0);
	for (int i = 0; i < InputSet.size(); i++) {
		if (dist(gen) > trainingSetRatio) {
			testInputs.push_back(InputSet[i]);
			testOutputs.push_back(OutputSet[i]);
		}
		else {
			trainingInputs.push_back(InputSet[i]);
			trainingOutputs.push_back(OutputSet[i]);
		}
	}
}

void DataSet::Print() {
	char c;
	std::cout << "Training Set Inputs Size = " << trainingInputs.size() << std::endl;
	std::cout << "Training Set Outputs Size = " << trainingOutputs.size() << std::endl;
	std::cout << "Test Set Inputs Size = " << testInputs.size() << std::endl;
	std::cout << "Test Set Outputs Size = " << testOutputs.size() << std::endl;
	std::cin >> c;
	for (int i = 0; i < trainingInputs.size(); i++) {
		for (int j = 0; j < trainingInputs[i].size(); j++) {
			std::cout << trainingInputs[i][j];
		}
		std::cout << std::endl;
	}
	for (int i = 0; i < trainingOutputs.size(); i++) {
		for (int j = 0; j < trainingOutputs[i].size(); j++) {
			std::cout << trainingOutputs[i][j];
		}
		std::cout << std::endl;
	}
}

std::vector<std::vector<float>> DataSet::GetTestInputs()
{
	return testInputs;
}

std::vector<std::vector<float>> DataSet::GetTestOutputs()
{
	return testOutputs;
}

std::vector<std::vector<float>> DataSet::GetTrainInputs()
{
	return trainingInputs;
}

std::vector<std::vector<float>> DataSet::GetTrainOutputs()
{
	return trainingOutputs;
}

DataSet::~DataSet() {
}
