#include <iostream>
#include <vector>
#include "unit.h"
#include "unterklassen.h"

int main()
{
    Graph g;
    g(1,2);
    std::cout<< g[1][1];
    return 0;
}

