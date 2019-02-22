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
	void SetError(float value);
	float GetInput();
	float GetError();
	float GetActivation();

	~Vertex();
private:
	std::list<Edge*> InputEdges;
	std::list<Edge*> OutputEdges;
	float Error = 0.0f;
	float Input = 0.0f;
	float Activation = 0.0f;
};

