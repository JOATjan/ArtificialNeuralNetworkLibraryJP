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
	std::vector<std::vector<float>> GetTestInputs();
	std::vector<std::vector<float>> GetTestOutputs();
	std::vector<std::vector<float>> GetTrainInputs();
	std::vector<std::vector<float>> GetTrainOutputs();
	~DataSet();
private:
	std::vector<std::vector<float>> trainingInputs;
	std::vector<std::vector<float>> trainingOutputs;
	std::vector<std::vector<float>> testOutputs;
	std::vector<std::vector<float>> testInputs;
};