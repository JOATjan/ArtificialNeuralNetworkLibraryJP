#pragma once
#include "Vertex.h"

class Edge {
public:
	Edge(Vertex * In,Vertex * Out, float val);
	float GetWeight();
	void SetWeight(float value);
	float GetOldWeight();
	void SetOldWeight(float value);
	Vertex * GetInputVertex();
	Vertex * GetOutputVertex();
	void InitializeWeight(float val);
	~Edge();
private:
	float weight = 0.0f;
	float oldWeight = 0.0f;
	Vertex* InputVertex = nullptr;
	Vertex* OutputVertex = nullptr;
};

