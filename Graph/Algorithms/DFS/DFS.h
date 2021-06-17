//
// Created by Umer on 6/11/2021.
//

#ifndef DOUBLYLINKEDLIST_H_DFS_H
#define DOUBLYLINKEDLIST_H_DFS_H

#include <iostream>
#include "DFSGraph.h"
#include "../../../Stack/Stack.cpp"

DFSGraph DFS(DFSVertex *start, DFSGraph g)
{
    start->status = UNVISITED;
    Stack<DFSVertex*> vertex;
    vertex.push(start);

    while (vertex.size() > 0) {
        DFSVertex *current = vertex.pop();
        for (int i = 0; i < current->getConnections().size(); i++) {
            if (g.vertList[current->getConnections()[i]].status == UNVISITED) {
                g.vertList[current->getConnections()[i]].status = VISITED;
                g.vertList[current->getConnections()[i]].dist = current->dist + 1;
                g.vertList[current->getConnections()[i]].pred = current;
                vertex.push(&g.vertList[current->getConnections()[i]]);
            }
        }
        current->status = DONE;
    }

    return g;
}

#endif //DOUBLYLINKEDLIST_H_DFS_H
