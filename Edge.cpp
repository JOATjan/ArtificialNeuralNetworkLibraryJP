#include "stdafx.h"
#include "Edge.h"
#include "Vertex.h"

Edge::Edge(Vertex * In, Vertex * Out,float val) {
	InputVertex = In;
	OutputVertex = Out;
	In->AddOutputEdge(this);
	Out->AddInputEdge(this);
	InitializeWeight(val);
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

float Edge::GetOldWeight()
{
	return oldWeight;
}

void Edge::SetOldWeight(float value)
{
	oldWeight = value;
}

Vertex* Edge::GetInputVertex() {
	return InputVertex;
}

Vertex* Edge::GetOutputVertex() {
	return OutputVertex;
}

Edge::~Edge() {
}
