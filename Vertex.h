#pragma once
#include <string>
using namespace std;
class Vertex
{
private:
	int Number;
	string Name;
	string Email = "";
public:
	Vertex() {};

	Vertex(int number)
	{
		Number = number;
	}

	string GetEmail()
	{
		return Email;
	}

	void SetEmail(string email)
	{
		Email = email;
	}

	int GetNumber()
	{
		return Number;
	}
	void SetNumber(int number)
	{
		Number = number;
	}

	string GetName()
	{
		return Name;
	}

	void SetName(string name)
	{
		Name = name;
	}

	string ToString()
	{
		return (char*)Number;
	}
};

