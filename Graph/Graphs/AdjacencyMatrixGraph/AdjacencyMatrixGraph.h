//
// Created by Umer on 6/5/2021.
//

#ifndef DOUBLYLINKEDLIST_H_ADJACENCYMATRIXGRAPH_H
#define DOUBLYLINKEDLIST_H_ADJACENCYMATRIXGRAPH_H

#include <iostream>

class AdjacencyMatrixGraph {
    bool **adjMatrix;
    int numVertices = 4;
public:

    /**
     * Default constructor.
     *
     * @since 1.0.0
     */
    AdjacencyMatrixGraph() {
        this->constructGraph();
    }

    /**
     * init the num of vertices.
     *
     * @since 1.0.0
     */
    explicit AdjacencyMatrixGraph(int numVertices) : AdjacencyMatrixGraph()
    {
        this->numVertices = numVertices;
    }

    /**
     * Construct Graph.
     *
     * @since 1.0.0
     * @return void
     */
    void constructGraph()
    {
        this->adjMatrix = new bool*[this->numVertices];
        for (int i = 0; i < this->numVertices; i++) {
            this->adjMatrix[i] = new bool[this->numVertices];
            for (int j = 0; j < this->numVertices; j++)
                this->adjMatrix[i][j] = false;
        }
    }

    /**
     * Add vertex from graph.
     *
     * @param int u
     * @param int v
     *
     * @since 1.0.0
     * @return void
     */
    void addEdge(int u, int v) {
        adjMatrix[u][v] = true;
        adjMatrix[v][u] = true;
    }

    /**
     * Remove vertex from graph.
     *
     * @param int u
     * @param int v
     *
     * @since 1.0.0
     * @return void
     */
    void removeEdge(int u, int v)
    {
        adjMatrix[u][v] = false;
        adjMatrix[v][u] = false;
    }

    /**
     * Operator overloading to print.
     *
     * @since 1.0.0
     */
    friend std::ostream &operator<<(std::ostream &stream, AdjacencyMatrixGraph &g) {
        std::cout << "    ";
        for (int i = 0; i < g.numVertices; i++) {
            std::cout << i << " ";
        }
        std::cout << std::endl;
        for (int i = 0; i < g.numVertices; i++) {
            std::cout << i << " : ";
            for (int j = 0; j < g.numVertices; j++)
                std::cout << g.adjMatrix[i][j] << " ";
            std::cout << std::endl;
        }

        return stream;
    }
};

#endif //DOUBLYLINKEDLIST_H_ADJACENCYMATRIXGRAPH_H
