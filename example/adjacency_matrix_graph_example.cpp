#include <iostream>
#include "../Graph/Graphs/AdjacencyMatrixGraph/AdjacencyMatrixGraph.h"

int main()
{
    AdjacencyMatrixGraph g(4);

    g.addEdge(0, 0);
    g.addEdge(0, 1);
    g.addEdge(1, 1);
    g.addEdge(1, 1);

    std::cout << g;
    std::cout << "Hello Adjacency Matrix Graph";
    return 0;
}