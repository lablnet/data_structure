#include <iostream>
#include "../Graph/Graphs/AdjacencyListGraph/AdjacencyListGraph.h"

int main()
{
    AdjacencyListGraph g;

    for (int i = 0; i < 3; i++) {
        g.addVertex(i);
    }

    g.addEdge(0, 1, 5);
    g.addEdge(0, 5, 2);
    g.addEdge(1, 2, 4);
    g.addEdge(2, 3, 9);
    g.addEdge(1, 4, 7);
    g.addEdge(2, 5, 3);

    std::cout << g << std::endl;

    std::cout << "Hello adjacency list Graph\n";
    return 0;
}
