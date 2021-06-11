//
// Created by Umer on 6/11/2021.
//

#ifndef DOUBLYLINKEDLIST_H_DFSGRAPH_H
#define DOUBLYLINKEDLIST_H_DFSGRAPH_H

#include "../../Graphs/AdjacencyListGraph/AdjacencyListGraph.h"
#include "../../../Queue/Queue.cpp"
#include "DFSVertex.h"

class DFSGraph : public AdjacencyListGraph<int, DFSVertex, int> {

};


void traverse(DFSVertex *y) {
    DFSVertex *x = y;

    while (x->pred) {
        std::cout << x->getId() << std::endl;
        x = x->pred;
    }
    std::cout << x->getId() << std::endl;
}

#endif //DOUBLYLINKEDLIST_H_DFSGRAPH_H
