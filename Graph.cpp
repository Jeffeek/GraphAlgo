#include <iostream>
#include "GraphV.h"

using namespace std;
void main()
{
    setlocale(0, "");
    GraphV<int> piska;
    piska.AddVertex(*new Vertex<int>(1));
    piska.AddVertex(*new Vertex<int>(2));

}


