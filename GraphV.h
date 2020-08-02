#pragma once
#include <vector>
#include "Vertex.h"
#include "Edge.h"
#include <algorithm>
#include <iostream>
using namespace std;
/// <summary>
/// class of Graph and algorithms for it
/// </summary>
template <typename T>
class GraphV
{
private:
	/// <summary>
	/// collection of vertexes of this graph
	/// </summary>
	vector<Vertex<T>> Vertexes;
	/// <summary>
	/// collection of edges of this graph
	/// </summary>
	vector<Edge<T>> Edges;
public:
	/// <summary>
	/// method for returning a vertex count
	/// </summary>
	/// <returns>Vertexes.size();</returns>
	int VertexCount() const
	{
		return Vertexes.size();
	}
	/// <summary>
	/// method for returning a edges count
	/// </summary>
	/// <returns>Edges.size()</returns>
	int EdgeCount() const
	{
		return Edges.size();
	}

	/// <summary>
	/// method for getting matrix for this graph
	/// </summary>
	/// <returns>matrix(int**)</returns>
	int** GetMatrix()
	{
		int** matrix = new int* [Vertexes.size()];
		for (int i = 0; i < Vertexes.size(); i++)
		{
			matrix[i] = new int[Vertexes.size()];
		}

		for (int i = 0; i < Vertexes.size(); i++)
		{
			for (int j = 0; j < Vertexes.size(); j++)
			{
				matrix[i][j] = 0;
			}
		}

		for (auto edge : Edges)
		{
			const auto row = edge.GetFrom().GetNumber();
			const auto column = edge.GetTo().GetNumber();

			matrix[row][column] = edge.GetWeight();
		}
		return matrix;
	}

	/// <summary>
	/// method for adding a new vertex to graph
	/// </summary>
	void AddVertex(T data)
	{
		Vertexes.push_back(*new Vertex<T>(VertexCount(), data));
	}

	/// <summary>
	/// method for adding a new edge between two vertexes
	/// </summary>
	/// <param name="from">vertex FROM</param>
	/// <param name="to">vertex TO</param>
	/// <param name="weight">weight between vertexes</param>
	void AddEdge(Vertex<T> from, Vertex<T> to, int weight = 1)
	{
		Edges.push_back(*new Edge<T>(from, to, weight));
	}

	Vertex<T> FindVertex(int number)
	{
		if (number >= VertexCount() || number < 0)
		{
			throw exception("Bad number");
		}
		return Vertexes[number];
	}

	/// <summary>
	/// getting a vector of vertexes witch are connected to given vertex
	/// </summary>
	/// <param name="vertex"></param>
	/// <returns></returns>
	vector<Vertex<T>> GetVertexList(Vertex<T> vertex)
	{
		vector<Vertex<T>> result;

		for (auto edge : Edges)
		{
			if (edge.GetFrom().GetNumber() == vertex.GetNumber())
			{
				result.push_back(edge.GetTo());
			}
		}
		return result;
	}

	/// <summary>
	/// method which is show is there a way from one vertex to another
	/// </summary>
	/// <param name="start">start vertex</param>
	/// <param name="finish">finish vertex</param>
	/// <returns>true/false</returns>
	bool Wave(Vertex<T> start, Vertex<T> finish)
	{
		vector<Vertex<T>>list;
		list.push_back(start);
		cout << "\nThe way: \n";
		for (int i = 0; i < list.size(); i++)
		{
			auto vertex = list[i];
			for (auto v : GetVertexList(vertex))
			{
				if (!CheckForAll(list, v))
				{
					list.push_back(v);
				}
			}
		}
		if (CheckForAll(list, finish))
		{
			//cout << finish.GetNumber();
			return true;
		}
		else
		{
			return false;
		}
	}

private:
		/// <summary>
		/// method for checking os there a vertex inside of given vector of vertexes
		/// </summary>
		/// <param name="V"></param>
		/// <param name="X"></param>
		/// <returns></returns>
	bool CheckForAll(vector<Vertex<T>> V, Vertex<T> X)
	{
		bool Check = false;
		for (int i = 0; i < V.size(); i++)
		{
			if (V[i].GetNumber() == X.GetNumber())
			{
				Check = true;
			}
		}
		return Check;
	}


	
public:
	/// <summary>
	/// Deixtra's algorithm
	/// </summary>
	/// <param name="start">start vertex</param>
	/// <param name="finish">finish vertex</param>
	void Deixtra(Vertex<T> start, Vertex<T> finish)
	{
		int StartNum = start.GetNumber();
		int FinishNum = finish.GetNumber();
		int WEIGHT = 0;
		const int INF = 1000000000;
		vector<int> Weights(VertexCount(), INF);
		Weights[StartNum] = 0;
		vector<int> Visited(VertexCount(), -1);
		for (;;) 
		{
			bool flagAny = false;
			for (int j = 0; j < EdgeCount(); ++j)
				if (Weights[Edges[j].GetFrom().GetNumber()] < INF) 
				{
					if (Weights[Edges[j].GetTo().GetNumber()] > Weights[Edges[j].GetFrom().GetNumber()] + Edges[j].GetWeight())
					{
						Weights[Edges[j].GetTo().GetNumber()] = Weights[Edges[j].GetFrom().GetNumber()] + Edges[j].GetWeight();
						Visited[Edges[j].GetTo().GetNumber()] = Edges[j].GetFrom().GetNumber();
						flagAny = true;
					}
				}

			if (!flagAny)  
				break;
		}

		if (Weights[FinishNum] == INF)
		{
			//if there is no path from start to finish
			return;
		}
		else 
		{
			vector<int> PathTo;
			for (int CurrentVertex = FinishNum; CurrentVertex != -1; CurrentVertex = Visited[CurrentVertex])
				PathTo.push_back(CurrentVertex);
			reverse(PathTo.begin(), PathTo.end());
			PathTo.push_back(0);
			cout << "The way from " << Vertexes[StartNum].GetNumber() << " to " << Vertexes[FinishNum].GetNumber()<< ": ";
			for (int i = 0; i < PathTo.size() - 1; i++)
			{
				for (int j = 0; j < EdgeCount(); j++)
				{
					if (Edges[j].GetFrom().GetNumber() == Vertexes[PathTo[i]].GetNumber() && Edges[j].GetTo().GetNumber() == Vertexes[PathTo[i + 1]].GetNumber())
					{
						WEIGHT += Edges[j].GetWeight();
						break;
					}
				}
				cout << Vertexes[PathTo[i]].GetNumber();
				if (i < PathTo.size() - 2)
				{
					cout << "->";
				}
			}
			cout << "\nWeight: " <<  WEIGHT << endl;
		}
	}
};

