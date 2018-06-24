#include "unterklassen.h"
#include "unit.h"
#include <vector>
#include <iostream>
#include <fstream>

CostT Graph::cost( VertexT from, VertexT to) const
{
#ifndef NDEBUG
  if (from >= vertexCount || to >= vertexCount)
    std::cerr << "Der Graph hat nur " << vertexCount << " Knoten." << std::endl;
    exit(1);
#endif
    if (from == to)
    {
        return 0;
    }
    else
    {
        NeighborT g = graph[from];
        for (std::size_t i=0; i < g.size();i++)
        {
            LocalEdgeT L = g[i];
            if (L.first == to)
            {
                return L.second;
                break;
            }  
        }  
    }
    return infty;
}

void Graph::einlesen(std::ifstream &ifs)
{
    ifs >> vertexCount;
    ifs >> EdgeCount;
    graph.resize(vertexCount);
    std::size_t kanten = EdgeCount;
    
    if (kanten >= 1)
    {
    while (kanten > 1)
    {
        CostT c;
        VertexT a,b;
        ifs >> a >> b >> c;
        LocalEdgeT L(b,c);
        graph[a].push_back(L);
        kanten--;
    }
        CostT c;
        VertexT a,b;
        ifs >> a >> b >> c;
        LocalEdgeT L(b,c);
        graph[a].push_back(L);
    }
}