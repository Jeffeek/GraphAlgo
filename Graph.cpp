#include <iostream>
#include "GraphV.h"

using namespace std;
void main()
{
    setlocale(0, "");
    GraphV<int> graph;
    graph.AddVertex(228); //add new vertex
    graph.AddVertex(1337); //add new vertex
    graph.AddEdge(graph.FindVertex(0), graph.FindVertex(1), 5); //add new edge between two added vertexes
    graph.Deixtra(graph.FindVertex(0), graph.FindVertex(1)); //show the shortest way from first vertex to another
    bool isWay = graph.Wave(graph.FindVertex(0), graph.FindVertex(1)); //checking is the a way from first vertex to another
}


