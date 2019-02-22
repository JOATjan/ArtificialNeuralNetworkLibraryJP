#pragma once
#include "Layer.h"
class InputLayer :
	public Layer {
public:
	InputLayer(float * _inputs,int _size);
	InputLayer();
	~InputLayer();
private:
	float* inputs = nullptr;
	int size = 0;
};

