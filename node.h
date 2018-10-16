#ifndef NODE_H
#define NODE_H

template <typename G>
class Node {
    public:
        typedef typename G::N N;
        typedef typename G::E E;
        typedef typename G::edge edge;
        typedef typename G::EdgeSeq EdgeSeq;
        Node(double x, double y,int dat):data(dat),x(x),y(y){};
        int get(){
            return data;
        }
        ~Node(){};
        EdgeSeq edges;

    private:
        int data;
        double x;
        double y;
};

#endif
