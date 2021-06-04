//
// Created by Umer on 6/4/2021.
//

#ifndef DOUBLYLINKEDLIST_H_VERTEX_H
#define DOUBLYLINKEDLIST_H_VERTEX_H

#include <map>
#include <vector>
#include <ostream>

class Vertex {
    int id;
    std::map<int, int> connectedTo;
public:

    // default
    Vertex() {}

    /**
     * Constructor.
     *
     * @since 1.0.0
     */
    Vertex(int key) {
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
    void addNeighbor(int nbr, int weight = 0) {
        this->connectedTo[nbr] = weight;
    }

    /**
     * Get id.
     *
     * @since 1.0.0
     * @param int
     */
    int getId() { return this->id;}

    /**
     * Get all connections.
     *
     * @since 1.0.0
     * @return vector<int>
     */
    std::vector<int> getConnections() {
        std::vector<int> keys;
        for (std::map<int, int>::iterator it = connectedTo.begin(); it != connectedTo.end(); ++it) {
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
    int getWeight(int nbr) {
        return connectedTo[nbr];
    }

    /**
     * Operator overloading to print.
     *
     * @since 1.0.0
     */
    friend std::ostream &operator<<(std::ostream &os, Vertex &vert) {
        std::vector<int> connects = vert.getConnections();
        for (unsigned int i = 0; i < connects.size(); i++) {
            os << "( " << vert.id << " , " << connects[i] << " ) \n";
        }

        return os;
    }
};

#endif //DOUBLYLINKEDLIST_H_VERTEX_H
