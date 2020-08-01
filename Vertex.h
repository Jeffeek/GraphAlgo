#pragma once
#include <string>
using namespace std;
template <typename T>
/// <summary>
/// class of vertex in graph
/// </summary>
/// <typeparam name="T">any type</typeparam>
class Vertex
{
private:
	/// <summary>
	/// data
	/// </summary>
	T Data;
	/// <summary>
	/// id for vertex
	/// </summary>
	int Number = 1;
public:
	/// <summary>
	/// constructor for initializing
	/// </summary>
	/// <returns></returns>
	Vertex()
	{
		
	};

	/// <summary>
	/// constructor with number(id) of this vertex
	/// </summary>
	/// <param name="number">id of this vertex</param>
	Vertex(int number)
	{
		Number = number;
	}

	/// <summary>
	/// setter for Data of this vertex
	/// </summary>
	/// <param name="data"></param>
	void SetData(T data)
	{
		Data = data;
	}

	/// <summary>
	/// getter for Data of this vertex
	/// </summary>
	/// <returns></returns>
	T GetData()
	{
		return Data;
	}

	/// <summary>
	/// getter for number(id)
	/// </summary>
	/// <returns>Number</returns>
	int GetNumber() const
	{
		return Number;
	}

	/// <summary>
	/// setter for number(not recommended)
	/// </summary>
	/// <param name="number"></param>
	void SetNumber(int number)
	{
		Number = number;
	}

	string ToString() const
	{
		return to_string(Number);
	}
};

