#pragma once
#include <vector>
#include <random>
#include <iostream>

class DataSet
{
public:
	DataSet();
	void Split(std::vector<std::vector<float>> & InputSet, std::vector<std::vector<float>> & OutputSet, float trainingSetRatio);
	void Print();
	~DataSet();
private:
	bool firstTimeRand;
	std::vector<std::vector<float>> testInputs;
	std::vector<std::vector<float>> trainingInputs;
	std::vector<std::vector<float>> testOutputs;
	std::vector<std::vector<float>> trainingOutputs;
};