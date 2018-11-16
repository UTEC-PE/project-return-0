#ifndef EDGE_H
#define EDGE_H

#include "node.h"

template <typename G>
class Edge {
    public:
        typedef typename G::E E;
        typedef typename G::node node;
        Edge(E data_):data(data_){};
        E get(){
            return data;
        }
        node* nodes[2];
        ~Edge(){}
    private:
        E data;
};

#endif
