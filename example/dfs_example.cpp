#include <iostream>
#include <algorithm>
#include "../Graph/Algorithms/DFS/DFS.h"

int main()
{
    DFSGraph g;
    for (int i = 0; i < 7; i++) {
        g.addVertex(i);
    }
    g.addEdge(0, 2, 1);
    g.addEdge(0, 4, 1);
    g.addEdge(0, 6, 1);
    g.addEdge(1, 3, 1);
    g.addEdge(1, 4, 1);
    g.addEdge(2, 0, 1);
    g.addEdge(2, 3, 1);
    g.addEdge(2, 6, 1);
    g.addEdge(3, 1, 1);
    g.addEdge(3, 2, 1);
    g.addEdge(4, 0, 1);
    g.addEdge(4, 1, 1);
    g.addEdge(4, 5, 1);
    g.addEdge(5, 4, 1);
    g.addEdge(5, 6, 1);
    g.addEdge(6, 0, 1);
    g.addEdge(6, 2, 1);
    g.addEdge(6, 5, 1);

    DFSGraph g1 = DFS(g.getVertex(0), g);

    std::cout << g1;

    std::cout << std::endl;
    return 0;
}
