#include "stdafx.h"
#include "Vertex.h"
#include "Edge.h"

Vertex::Vertex() {
}

std::list<Edge*> Vertex::GetInputEdges() {
	return InputEdges;
}


std::list<Edge*> Vertex::GetOutputEdges() {
return OutputEdges;
}

void Vertex::AddInputEdge(Edge * edge) {
	InputEdges.push_back(edge);
}

void Vertex::AddOutputEdge(Edge * edge) {
	InputEdges.push_back(edge);
}

void Vertex::SetInput(float value) {
	Input = value;
}

void Vertex::SetActivation(float value) {
	Activation = value;
}

void Vertex::SetErrorActivationDeriv(float value)
{
	ErrorActivationDeriv = value;
}

void Vertex::SetActivationInputDeriv(float value)
{
	ActivationInputDeriv = value;
}

float Vertex::GetErrorActivationDeriv()
{
	return ErrorActivationDeriv;
}

float Vertex::GetActivationInputDeriv()
{
	return ActivationInputDeriv;
}

float Vertex::GetInput() {
	return Input;
}

float Vertex::GetActivation() {
	return Activation;
}

Vertex::~Vertex() {
}
