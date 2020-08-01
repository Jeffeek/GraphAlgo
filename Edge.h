#pragma once
#include "Vertex.h"
/// <summary>
/// the class of edge in graph between two vertexes
/// </summary>
template <typename T>
class Edge
{
private:
	/// <summary>
	/// vertex FROM
	/// </summary>
	Vertex<T> From;
	/// <summary>
	/// vertex TO
	/// </summary>
	Vertex<T> To;
	/// <summary>
	/// weight of this edge
	/// </summary>
	int Weight;
public:

	/// <summary>
	/// setter of weight for this edge
	/// </summary>
	/// <param name="weight">weight</param>
	void SetWeight(int weight)
	{
		Weight = weight;
	}

	/// <summary>
	/// getter for weight of this edge
	/// </summary>
	/// <returns>Weight</returns>
	int GetWeight() const
	{
		return Weight;
	}

	/// <summary>
	/// setter for vertex FROM
	/// </summary>
	/// <param name="from">vertex From</param>
	void SetFrom(Vertex<T> from)
	{
		From = from;
	}

	/// <summary>
	/// getter for vertex FROM
	/// </summary>
	/// <returns>vertex From</returns>
	Vertex<T> GetFrom()
	{
		return From;
	}

	/// <summary>
	/// setter for vertex TO
	/// </summary>
	/// <param name="to">vertex to</param>
	void SetTo(Vertex<T> to)
	{
		To = to;
	}

	/// <summary>
	/// getter for vertex TO
	/// </summary>
	/// <returns>To</returns>
	Vertex<T> GetTo() const
	{
		return To;
	}

	/// <summary>
	/// constructor for initializing all info about edge
	/// </summary>
	/// <param name="from">vertex from</param>
	/// <param name="to">vertex to</param>
	/// <param name="weight">weight(default value is 1)</param>
	/// <returns></returns>
	Edge(Vertex<T> from, Vertex<T> to, int weight = 1)
	{
		From = from;
		To = to;
		Weight = weight;
	}

	/// <summary>
	/// bringing to string format
	/// </summary>
	/// <returns>string</returns>
	string ToString()
	{
		return "From " + From.ToString() + " to " + To.ToString();
	}
};

