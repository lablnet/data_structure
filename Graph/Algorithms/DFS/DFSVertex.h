//
// Created by Umer on 6/11/2021.
//

#ifndef DOUBLYLINKEDLIST_H_DFSVERTEX_H
#define DOUBLYLINKEDLIST_H_DFSVERTEX_H

#include "../../Graphs/AdjacencyListGraph/AdjacencyListVertex.h"

enum VertexVisited {VISITED, UNVISITED, DONE};

class DFSVertex : public AdjacencyListVertex<int, int> {
public:
    VertexVisited status;
    DFSVertex *pred;
    float dist;

    DFSVertex(){
        this->status = UNVISITED;
        this->pred = nullptr;
        this->dist = 0;
    }
    explicit DFSVertex(int key) : DFSVertex()
    {
        this->id = key;
    }
};

#endif //DOUBLYLINKEDLIST_H_DFSVERTEX_H
