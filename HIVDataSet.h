#pragma once
#include "DataSet.h"
#include <fstream>
#include <iostream>

class HIVDataSet : public DataSet {
public:
	HIVDataSet(float DataSetSplitRatio);
	float Normalize(char letter);
	void LoadData();
private:
	float splitRatio;
	~HIVDataSet();
};

