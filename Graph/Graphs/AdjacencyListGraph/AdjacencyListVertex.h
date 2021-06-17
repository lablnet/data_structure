//
// Created by Umer on 6/4/2021.
//

#ifndef DOUBLYLINKEDLIST_H_VERTEX_H
#define DOUBLYLINKEDLIST_H_VERTEX_H

#include <map>
#include <vector>
#include <ostream>

template <typename K, typename V>
class AdjacencyListVertex {
protected:
    K id;
    std::map<K, V> connectedTo;
public:

    // default
    AdjacencyListVertex() {}

    /**
     * Constructor.
     *
     * @since 1.0.0
     */
    AdjacencyListVertex(K key) {
        this->id = key;
    }

    /**
     * Add Neighbour.
     *
     * @param int nbr.
     * @param int weight.
     *
     * @since 1.0.0
     * @return void
     */
    void addNeighbor(K nbr, V weight = 0) {
        this->connectedTo[nbr] = weight;
    }

    /**
     * Get id.
     *
     * @since 1.0.0
     * @param <K>
     */
    K getId() { return this->id;}

    /**
     * Get all connections.
     *
     * @since 1.0.0
     * @return vector<K>
     */
    std::vector<K> getConnections() {
        std::vector<K> keys;
        for (typename std::map<K, V>::iterator it = connectedTo.begin(); it != connectedTo.end(); ++it) {
            keys.push_back(it->first);
        }
        return keys;
    }

    /**
     * Get weight from vertex.
     *
     * @param int nbr.
     *
     * @since 1.0.0
     * @return int
     */
    V getWeight(K nbr) {
        return connectedTo[nbr];
    }

    /**
     * Operator overloading to print.
     *
     * @since 1.0.0
     */
    friend std::ostream &operator<<(std::ostream &os, AdjacencyListVertex &vert) {
        std::vector<K> connects = vert.getConnections();
        for (unsigned int i = 0; i < connects.size(); i++) {
            os << "( " << vert.id << " , " << connects[i] << " ) \n";
        }

        return os;
    }
};

#endif //DOUBLYLINKEDLIST_H_VERTEX_H
