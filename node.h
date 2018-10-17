#ifndef NODE_H
#define NODE_H

template <typename G>
class Node {
public:
    typedef typename G::N N;
    typedef typename G::E E;
    typedef typename G::edge edge;
    typedef typename G::EdgeSeq EdgeSeq;
    Node(double x, double y,N dat):data(dat),x(x),y(y){};
    N get(){
        return data;
    }
    ~Node(){};
    EdgeSeq edges;

private:
    N data;
    double x;
    double y;
};

#endif
