#ifndef _UNTERKLASSEN
#define _UNTERKLASSEN

#include <vector>
#include "unit.h"

class Graph : public DistanceGraph
{
    private:
    std::size_t EdgeCount;
    std::vector<NeighborT> graph;

public:
    Graph( int num_verts= 0, int num_edges=0 )
     : DistanceGraph(num_verts),EdgeCount(num_edges) {}
      
    ~Graph() {}

    const NeighborT& getNeighbors( VertexT v) const override {return graph[v];}
    
    CostT estimatedCost( VertexT from, VertexT to) const override;
    
    CostT cost( VertexT from, VertexT to) const override;

    void einlesen(std::ifstream &ifs);
};

/*class Maze : public DistanceGraph
{
    public:
 //   DistanceGraph( int num_verts= 0)
 //     : vertexCount(num_verts) {}
      
  //  virtual ~DistanceGraph() {}

    // Gibt die Nachbarknoten eines gegebenen Knotens v zurueck.
    const NeighborT& getNeighbors( VertexT v) const override;
    
    // Heuristik: Schaetzt die Kosten, um vom Knoten "from" zum Knoten "to" zu gelangen.
    CostT estimatedCost( VertexT from, VertexT to) const override;
    
    // Gibt die wahren Kosten c an, um vom Knoten "from" zum Knoten "to" zu gelangen.
    // Existiert zwischen den beiden Knoten keine Kante, werden die Kosten mit infty bewertet.
    CostT cost( VertexT from, VertexT to) const override;


};*/

// Ein Graph, der Koordinaten von Knoten speichert.
/*class CoordinateGraph : public DistanceGraph {
public:
    const NeighborT& getNeighbors( VertexT v) const override;
    
    CostT estimatedCost( VertexT from, VertexT to) const override;
    
    CostT cost( VertexT from, VertexT to) const override;
};*/

#endif