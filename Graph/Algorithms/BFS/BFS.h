//
// Created by Umer on 6/11/2021.
//

#ifndef DOUBLYLINKEDLIST_H_BFS_H
#define DOUBLYLINKEDLIST_H_BFS_H

#include "../DFS/DFSGraph.h"

DFSGraph BFS(DFSVertex *start, DFSGraph g)
{
    start->status = UNVISITED;
    Queue<DFSVertex*> vertex;
    vertex.enqueue(start);
    while (vertex.size() > 0) {
        DFSVertex *current = vertex.dequeue();
        for (int i = 0; i < current->getConnections().size(); i++) {
            if (g.vertList[current->getConnections()[i]].status == UNVISITED) {
                g.vertList[current->getConnections()[i]].status = VISITED;
                g.vertList[current->getConnections()[i]].dist = current->dist + 1;
                g.vertList[current->getConnections()[i]].pred = current;
                vertex.enqueue(&g.vertList[current->getConnections()[i]]);
            }
        }
        current->status = DONE;
    }

    return g;
}

#endif //DOUBLYLINKEDLIST_H_BFS_H
