#include <iostream>
#include <regex>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include "GraphV.h"
#include <boost\algorithm\string.hpp>

using namespace std;
using namespace boost;
bool IsAlreadyExist(string name, GraphV G);
void main()
{
    setlocale(0, "");
    GraphV graph;
    int countOfCities = 0;
    int countOfRoads = 0;
    int indexOfMinsk = 0;
    fstream file("file.txt");
    file >> countOfCities;
    file >> countOfRoads;
    file.close();
    fstream file2("file.txt");
    vector<string>Roads;
    string line;
    getline(file2, line);
    int ptr = 0;
    int num = 1;
    while (countOfRoads != 0)
    {
        getline(file2, line);
        istringstream stream(line);
        string ready;
        vector<string>temp;
        while (getline(stream, ready, '-'))
        {
            temp.push_back(ready);
        }
        stream.clear(false);

        int indFrom = -1, indTo = -1;

        istringstream stream2(temp[1]);
        string ready2;
        vector<string>temp2;
        while (getline(stream2, ready2, ' '))
        {
            temp2.push_back(ready2);
        }

        //temp[0] - название первого, temp2[0] - название второго, temp[1] - вес между
        Vertex V1, V2;
        if (!IsAlreadyExist(temp[0], graph) || !IsAlreadyExist(temp2[0], graph))
        {
            if (!IsAlreadyExist(temp[0], graph) && IsAlreadyExist(temp2[0], graph))
            {
                V1.SetName(temp[0]);
                V1.SetNumber(graph.VertexCount());
                graph.AddVertex(V1);
                
                for (int i = 0; i < graph.VertexCount(); i++)
                {
                    if (graph.Vertexes[i].GetName() == temp[0])
                    {
                        indFrom = i;
                    }
                    if (graph.Vertexes[i].GetName() == temp2[0])
                    {
                        indTo = i;
                    }
                }
                graph.AddEdge(graph.Vertexes[indFrom], graph.Vertexes[indTo], atoi(temp2[1].c_str()));
                graph.AddEdge(graph.Vertexes[indTo], graph.Vertexes[indFrom], atoi(temp2[1].c_str()));
                indFrom = -1, indTo = -1;
            }
            if (!IsAlreadyExist(temp2[0], graph) && IsAlreadyExist(temp[0], graph))
            {
                V2.SetName(temp2[0]);
                V2.SetNumber(graph.VertexCount());
                graph.AddVertex(V2);

                for (int i = 0; i < graph.VertexCount(); i++)
                {
                    if (graph.Vertexes[i].GetName() == temp[0])
                    {
                        indFrom = i;
                    }
                    if (graph.Vertexes[i].GetName() == temp2[0])
                    {
                        indTo = i;
                    }
                }
                graph.AddEdge(graph.Vertexes[indFrom], graph.Vertexes[indTo], atoi(temp2[1].c_str()));
                graph.AddEdge(graph.Vertexes[indTo], graph.Vertexes[indFrom], atoi(temp2[1].c_str()));
                indFrom = -1, indTo = -1;
            }
            else if (!IsAlreadyExist(temp[0], graph) && !IsAlreadyExist(temp2[0], graph))
            {
                V1.SetName(temp[0]);
                V1.SetNumber(graph.VertexCount());
                graph.AddVertex(V1);

                V2.SetName(temp2[0]);
                V2.SetNumber(graph.VertexCount());
                graph.AddVertex(V2);

                for (int i = 0; i < graph.VertexCount(); i++)
                {
                    if (graph.Vertexes[i].GetName() == temp[0])
                    {
                        indFrom = i;
                    }
                    if (graph.Vertexes[i].GetName() == temp2[0])
                    {
                        indTo = i;
                    }
                }
                graph.AddEdge(graph.Vertexes[indFrom], graph.Vertexes[indTo], atoi(temp2[1].c_str()));
                graph.AddEdge(graph.Vertexes[indTo], graph.Vertexes[indFrom], atoi(temp2[1].c_str()));
                indFrom = -1, indTo = -1;
            }
        }
        else
        {
            for (int i = 0; i < graph.VertexCount(); i++)
            {
                if (graph.Vertexes[i].GetName() == temp[0])
                {
                    indFrom = i;
                }
                if (graph.Vertexes[i].GetName() == temp2[0])
                {
                    indTo = i;
                }
            }
            graph.AddEdge(graph.Vertexes[indFrom], graph.Vertexes[indTo], atoi(temp2[1].c_str()));
            graph.AddEdge(graph.Vertexes[indTo], graph.Vertexes[indFrom], atoi(temp2[1].c_str()));
            indFrom = -1, indTo = -1;
        }
        countOfRoads--;
    }
    //file2.close();
    fstream file_output("output.txt");
    while (getline(file2, line))
    {
        istringstream stream(line);
        string ready;
        vector<string>temp;
        while (getline(stream, ready, '/'))
        {
            temp.push_back(ready);
        }

        for (int i = 0; i < graph.VertexCount(); i++)
        {
            if (temp[0] == graph.Vertexes[i].GetName())
            {
                graph.Vertexes[i].SetEmail(temp[1]);
            }
        }
        stream.clear(false);
    }


    regex email("^((([0-9A-Za-z]{1}[-0-9A-z\.]{1,}[0-9A-Za-z]{1})|([0-9А-Яа-я]{1}[-0-9А-я\.]{1,}[0-9А-Яа-я]{1}))@([-A-Za-z]{1,}\.){1,2}[-A-Za-z]{2,})$");
    for (int i = 0; i < graph.VertexCount(); i++)
    {
        if (graph.Vertexes[i].GetEmail() == "")
        {
            cout << "В городе " << graph.Vertexes[i].GetName() << " нет емэйла\n";
            file_output << "В городе " << graph.Vertexes[i].GetName() << " нет емэйла\n";
        }
        else
        {
            if (!regex_match(graph.Vertexes[i].GetEmail(), email))
            {
                cout << "\nВ городе " << graph.Vertexes[i].GetName() << " неправильно введен емэйл! : " << graph.Vertexes[i].GetEmail() << endl;
                file_output << "\nВ городе " << graph.Vertexes[i].GetName() << " неправильно введен емэйл! : " << graph.Vertexes[i].GetEmail() << "\n";
            }
        }
    }

    for (int i = 0; i < graph.VertexCount(); i++)
    {
        if (graph.Vertexes[i].GetEmail() != "" && strrchr(graph.Vertexes[i].GetEmail().c_str(), '@') != NULL)
        {
            string Server = "";
            for (int j = 0; j < graph.Vertexes[i].GetEmail().size(); j++)
            {
                if (graph.Vertexes[i].GetEmail()[j] == '@')
                {
                    for (int k = j; k < graph.Vertexes[i].GetEmail().size(); k++)
                    {
                        Server += graph.Vertexes[i].GetEmail()[k];
                    }
                    graph.Vertexes[i].SetServer(Server);
                    break;
                }
            }
        }
    }
    string PopularEmail;
    vector<string>SERVERS;
    for (int i = 0; i < graph.VertexCount(); i++)
    {
        if (graph.Vertexes[i].GetServer() != "" && find(SERVERS.begin(), SERVERS.end(), graph.Vertexes[i].GetServer()) == SERVERS.end())
        {
            SERVERS.push_back(graph.Vertexes[i].GetServer());
        }
    }

    int CountOf = 0;
    for (int i = 0; i < SERVERS.size(); i++)
    {
        if (CountOf < count(SERVERS.begin(), SERVERS.end(), SERVERS[i]))
        {
            PopularEmail = SERVERS[i];
            CountOf = count(SERVERS.begin(), SERVERS.end(), SERVERS[i]);
        }
    }

    cout << "\nСамый популярный email: " << PopularEmail << "\n";
    file_output << "\nСамый популярный email: " << PopularEmail << "\n";

    for (int i = 0; i < graph.VertexCount(); i++)
    {
        if (graph.Vertexes[i].GetServer() != PopularEmail)
        {
            graph.Vertexes[i].SetServer(PopularEmail);
        }
    }

    regex kok("@.+");
    for (int i = 0; i < graph.VertexCount(); i++)
    {
        if (graph.Vertexes[i].GetEmail() != "")
        {
            string email = graph.Vertexes[i].GetEmail();
            email = regex_replace(email, kok, PopularEmail);
            graph.Vertexes[i].SetEmail(email);
        }
    }

    for (int i = 0; i < graph.VertexCount(); i++)
    {
        if (graph.Vertexes[i].GetEmail() != "" && strrchr(graph.Vertexes[i].GetEmail().c_str(), '@') != NULL)
        {
            cout << endl << graph.Vertexes[i].GetName() << " : " << graph.Vertexes[i].GetEmail();
            file_output << "\n" << graph.Vertexes[i].GetName() << " : " << graph.Vertexes[i].GetEmail();
        }
    }

    file_output << "\n";
    cout << "\nВведите начальную точку: ";
    string start;
    cin >> start;
    ptr = -1;
    for (int i = 0; i < graph.VertexCount(); i++)
    {
        if (graph.Vertexes[i].GetName() == start)
        {
            ptr = i;
            break;
        }
    }

    if (ptr == -1)
    {
        cout << "Нет такого города";
        file_output << "Нет такого города\n";
        return;
    }
    else
    {
        for (int i = 0; i < graph.VertexCount(); i++)
        {
            if (graph.Vertexes[i].GetName() == start)
            {
                ptr = i;
            }
            if (graph.Vertexes[i].GetName() == "Minsk")
            {
                indexOfMinsk = i;
            }
        }
    }

    //graph.Wave(graph.Vertexes[ptr], graph.Vertexes[indexOfMinsk]);

    auto matrix = graph.GetMatrix();
    for (int i = 0; i < graph.VertexCount(); i++)
    {
        for (int j = 0; j < graph.VertexCount(); j++)
        {
            cout << matrix[i][j] << "\t";
            file_output << matrix[i][j] << "\t";
        }
        file_output << "\n";
        cout << endl;
    }

    file_output.close();
    graph.Deixtra(graph.Vertexes[ptr], graph.Vertexes[indexOfMinsk]);
}

bool IsAlreadyExist(string name, GraphV G)
{
    for (auto vertex : G.Vertexes)
    {
        if (name == vertex.GetName())
        {
            return true;
        }
    }
    return false;
}


