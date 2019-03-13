#include "stdafx.h"
#include "HIVDataSet.h"

HIVDataSet::HIVDataSet(float dataSetSplitRatio)
{
	splitRatio = dataSetSplitRatio;
}

void HIVDataSet::LoadData()
{
	std::vector<float> singleInput;
	std::vector<float> singleOutput;
	std::vector<std::vector<float>> inputs;
	std::vector<std::vector<float>> outputs;
	char inputLetter, separator, output;
	std::fstream file("Scenario\\1625Data.txt", std::fstream::in);
	if (file.is_open()) {
		while (file.good()) {
			for (int i = 0; i < 8; i++) {
				file.get(inputLetter);
				singleInput.push_back(Normalize(inputLetter));
			}
			file.get(separator);
			file.get(output);
			if (output == '1')
				singleOutput.push_back(1);
			else {
				singleOutput.push_back(0);
				file.get(output);
			}
			file.get(separator);
			inputs.push_back(singleInput);
			outputs.push_back(singleOutput);
			singleInput.clear();
			singleOutput.clear();
		}
	}
	Split(inputs, outputs, splitRatio);
	if (!file.eof() && file.fail())
		std::cout << "error \n" << std::endl;
	file.close();
}

float HIVDataSet::Normalize(char letter)
{
	float value = (int)letter;
	float minValue = 65.0f;
	float maxValue = 89.0f;
	return (value - minValue)/(maxValue-minValue);
}

HIVDataSet::~HIVDataSet()
{
}
