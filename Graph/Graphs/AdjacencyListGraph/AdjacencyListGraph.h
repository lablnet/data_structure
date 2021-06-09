//
// Created by Umer on 6/4/2021.
//

#ifndef DOUBLYLINKEDLIST_H_GRAPH_H
#define DOUBLYLINKEDLIST_H_GRAPH_H

#include "AdjacencyListVertex.h"

template <typename K, typename V>
class AdjacencyListGraph {
    std::map<K, AdjacencyListVertex<K, V>> vertList;
    int numVertices = 0;

public:

    /**
     * Add Vertex to graph.
     *
     * @param int key.
     *
     * @since 1.0.0
     * @return Vetrex
     */
    AdjacencyListVertex<K, V> addVertex(K key) {
        this->numVertices++;
        AdjacencyListVertex<K, V> vertex = AdjacencyListVertex<K, V>(key);
        this->vertList[key] = vertex;
        return vertex;
    }

    /**
     * Get the vertices from graph.
     *
     * @param int n.
     *
     * @since 1.0.0
     * @return <*>Vetrex
     */
    AdjacencyListVertex<K, V> *getVertex(K n) {
        for (typename std::map<K, AdjacencyListVertex<K, V>>::iterator it = vertList.begin(); it != vertList.end(); ++it) {
            if (it->first == n) {
                return &vertList[n];
            } else {
                return nullptr;
            }
        }
    }

    /**
     * Determine if the vertexes contains.
     *
     * @param int n.
     *
     * @since 1.0.0
     * @return bool
     */
    bool contains(K n) {
        for (typename std::map<K, AdjacencyListVertex<K, V>>::iterator it = vertList.begin(); it != vertList.end(); ++it) {
            if (it->first == n) {
                return true;
            }
        }
        return false;
    }

    /**
     * Add edge to graph.
     *
     * @param int f.
     * @param int t.
     * @param int weight.
     *
     * @since 1.0.0
     * @return void
     */
    void addEdge(K f, K t, V weight = 0)
    {
        if (!this->contains(f)) {
            this->addVertex(f);
        }

        this->vertList[f].addNeighbor(t, weight);
    }

    /**
     * Get all vertices.
     *
     * @since 1.0.0
     * @return vector<int>
     */
    std::vector<K> getVertices() {
        std::vector<K> verts;

        for (typename std::map<K, AdjacencyListVertex<K, V>>::iterator it = vertList.begin(); it != vertList.end();  ++it) {
            verts.push_back(it->first);
        }
        return verts;
    }

    /**
     * Operator overloading to print.
     *
     * @since 1.0.0
     */
    friend std::ostream &operator<<(std::ostream &stream, AdjacencyListGraph &g) {
        for (unsigned int i = 0; i < g.vertList.size(); i++) {
            stream << g.vertList[i];
        }

        return stream;
    }
};

#endif //DOUBLYLINKEDLIST_H_GRAPH_H
