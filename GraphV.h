#pragma once
#include <vector>
#include "Vertex.h"
#include "Edge.h"
#include <string>
#include <algorithm>
#include <queue>
#include <fstream>
#include <iostream>
#include <boost\algorithm\string.hpp>
using namespace std;
class GraphV
{
private:
public:
	vector<Vertex> Vertexes;
	vector<Edge> Edges;


	int VertexCount()
	{
		return Vertexes.size();
	}

	int EdgeCount()
	{
		return Edges.size();
	}

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
			auto row = edge.GetFrom().GetNumber();
			auto column = edge.GetTo().GetNumber();

			matrix[row][column] = edge.GetWeight();
		}
		return matrix;
	}



	void AddVertex(Vertex vertex)
	{
		Vertexes.push_back(vertex);
	}

	void AddEdge(Vertex from, Vertex to, int weight = 1)
	{
		Edge edge(from, to, weight);
		Edges.push_back(edge);
	}

	vector<Vertex> GetVertexList(Vertex vertex)
	{
		vector<Vertex> result;

		for (auto edge : Edges)
		{
			if (edge.GetFrom().GetNumber() == vertex.GetNumber())
			{
				result.push_back(edge.GetTo());
			}
		}
		return result;
	}

	//есть ли путь из старт в финиш
	bool Wave(Vertex start, Vertex finish)
	{
		vector<Vertex>list;
		int JustForCast = 0;
		int weight = 0;
		list.push_back(start);
		cout << "\nПуть: \n";
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
			cout << finish.GetName();
			cout << "\nВес: " << weight << endl;
			return true;
		}
		else
		{
			return false;
		}
	}

private:
	//проверка того, есть ли элемент в списке вершин
		bool CheckForAll(vector<Vertex>V, Vertex X)
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
	void Deixtra(Vertex start, Vertex finish)
	{
		int StartNum = start.GetNumber();
		int FinishNum = finish.GetNumber();
		int WEIGHT = 0;
		int CountOfVertex = VertexCount();
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

		fstream file_output("output.txt", ios::app);
		if (Weights[FinishNum] == INF)
		{
			cout << "Пути нет с " << Vertexes[StartNum].GetName() << " к " << Vertexes[FinishNum].GetName() << ".";
			file_output << "Пути нет с " << Vertexes[StartNum].GetName() << " к " << Vertexes[FinishNum].GetName() << ".";
			file_output.close();
		}
		else {
			vector<int> PathTo;
			for (int CurrentVertex = FinishNum; CurrentVertex != -1; CurrentVertex = Visited[CurrentVertex])
				PathTo.push_back(CurrentVertex);
			reverse(PathTo.begin(), PathTo.end());
			PathTo.push_back(0);
			cout << "Путь от " << Vertexes[StartNum].GetName() << " к " << Vertexes[FinishNum].GetName() << ": ";
			file_output << "Путь от " << Vertexes[StartNum].GetName() << " к " << Vertexes[FinishNum].GetName() << ": \n";
			for (int i = 0; i < PathTo.size() - 1; i++)
			{
				for (int j = 0; j < EdgeCount(); j++)
				{
					if (Edges[j].GetFrom().GetName() == Vertexes[PathTo[i]].GetName() && Edges[j].GetTo().GetName() == Vertexes[PathTo[i + 1]].GetName())
					{
						WEIGHT += Edges[j].GetWeight();
						break;
					}
				}
				cout << Vertexes[PathTo[i]].GetName();
				file_output << Vertexes[PathTo[i]].GetName();
				if (i < PathTo.size() - 2)
				{
					cout << "->";
					file_output << "->";
				}
			}
			cout << "\nВес: " <<  WEIGHT << endl;
			file_output << "\nВес: " << WEIGHT << "\n";
			file_output.close();
		}
	}
};

