#include "stdafx.h"
#include "Vertex.h"
#include "Edge.h"

Vertex::Vertex()
{
}

std::list<Edge*> Vertex::GetInputEdges()
{
	return InputEdges;
}


std::list<Edge*> Vertex::GetOutputEdges()
{
	return OutputEdges;
}

void Vertex::AddInputEdge(Edge * edge)
{
	InputEdges.push_back(edge);
}

void Vertex::AddOutputEdge(Edge * edge)
{
	InputEdges.push_back(edge);
}

void Vertex::SetInput(float value)
{
	Input = value;
}

void Vertex::SetActivation(float value)
{
	Activation = value;
}

float Vertex::GetInput()
{
	return Input;
}

float Vertex::GetActivation()
{
	return Activation;
}

Vertex::~Vertex()
{
}
