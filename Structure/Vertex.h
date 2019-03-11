#pragma once
#include <list>

class Edge;

class Vertex {
public:
	Vertex();
	std::list<Edge*> GetInputEdges();
	std::list<Edge*> GetOutputEdges();
	void AddInputEdge(Edge* edge);
	void AddOutputEdge(Edge* edge);
	void SetInput(float value);
	void SetActivation(float value);
	void SetErrorActivationDeriv(float value);
	void SetActivationInputDeriv(float value);
	float GetErrorActivationDeriv();
	float GetActivationInputDeriv();
	float GetInput();
	float GetActivation();

	~Vertex();
private:
	std::list<Edge*> inputEdges;
	std::list<Edge*> outputEdges;
	float ErrorActivationDeriv = 0.0f;
	float ActivationInputDeriv = 0.0f;
	float Input = 0.0f;
	float Activation = 0.0f;
};

