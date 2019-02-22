#include "stdafx.h"
#include "Edge.h"
#include "Vertex.h"

Edge::Edge(Vertex * In, Vertex * Out) {
	InputVertex = nullptr;
	OutputVertex = nullptr;
	InputVertex = In;
	OutputVertex = Out;
	In->AddOutputEdge(this);
	Out->AddInputEdge(this);
}

void Edge::InitializeWeight(float val) {
	weight = val;
}

float Edge::GetWeight() {
	return weight;
}

void Edge::SetWeight(float value) {
	weight = value;
}

Vertex* Edge::GetInputVertex() {
	return InputVertex;
}

Vertex* Edge::GetOutputVertex() {
	return OutputVertex;
}


Edge::~Edge() {
}
