#pragma once
#include "Vertex.h"
class Edge
{
private:
	Vertex From;
	Vertex To;
	int Weight;
public:

	void SetWeight(int weight)
	{
		Weight = weight;
	}

	int GetWeight()
	{
		return Weight;
	}

	void SetFrom(Vertex from)
	{
		From = from;
	}

	Vertex GetFrom()
	{
		return From;
	}

	void SetTo(Vertex to)
	{
		To = to;
	}

	Vertex GetTo()
	{
		return To;
	}

	Edge(Vertex from, Vertex to, int weight = 1)
	{
		From = from;
		To = to;
		Weight = weight;
	}

	string ToString()
	{
		return "From " + From.ToString() + " to " + To.ToString();
	}
};

