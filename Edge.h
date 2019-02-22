#pragma once
#include "Vertex.h"
class Edge
{
public:
	Edge(Vertex * In,Vertex * Out);
	void InitializeWeight(float val);
	float GetWeight();
	void SetWeight(float value);
	Vertex * GetInputVertex();
	~Edge();
private:
	float weight;
	Vertex* InputVertex;
	Vertex* OutputVertex;
};

