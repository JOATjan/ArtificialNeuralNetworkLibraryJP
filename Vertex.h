#pragma once
#include <list>

class Edge;

class Vertex
{
public:
	Vertex();
	std::list<Edge*> GetInputEdges();
	std::list<Edge*> GetOutputEdges();
	void AddInputEdge(Edge* edge);
	void AddOutputEdge(Edge* edge);
	void SetInput(float value);
	void SetActivation(float value);
	float GetInput();
	float GetActivation();
	~Vertex();
private:
	std::list<Edge*> InputEdges;
	std::list<Edge*> OutputEdges;
	float Input;
	float Activation;
};

