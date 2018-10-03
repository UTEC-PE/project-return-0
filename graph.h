#ifndef GRAPH_H
#define GRAPH_H
#include<iostream>
#include <vector>
#include <list>

#include "node.h"
#include "edge.h"

using namespace std;

class Traits {
	public:
		typedef char N;
		typedef int E;
};

template <typename Tr>
class Graph {
    public:
        typedef Graph<Tr> self;
        typedef Node<self> node;
        typedef Edge<self> edge;
        typedef vector<node*> NodeSeq;
        typedef list<edge*> EdgeSeq;
        typedef typename Tr::N N;
        typedef typename Tr::E E;
        typedef typename NodeSeq::iterator NodeIte;
        typedef typename EdgeSeq::iterator EdgeIte;

        void insertar_nodo(double x, double y,N vertice){
            node* temp=new node(x,y,vertice);
            nodes.push_back(temp);
        };
        void insertar_arista(N v1,N v2,E peso, bool dir){
            edge* temp1=new edge(peso,dir);
            edge* temp2=new edge(peso,dir);
            for (ni=nodes.begin();ni!=nodes.end();++ni){
                if ((*ni)->get()==v1){
                    temp1->nodes[0]=(*ni);
                    temp2->nodes[1]=(*ni);
                }
                if ((*ni)->get()==v2){
                    temp1->nodes[1]=(*ni);
                    temp2->nodes[0]=(*ni);
                }
            }
            temp1->nodes[0]->edges.push_back(temp1);
            temp2->nodes[0]->edges.push_back(temp2);
        }
        void print(){
            for (ni=nodes.begin();ni!=nodes.end();++ni){
                cout <<(*ni)->get()<<endl;
                for(ei=(*ni)->edges.begin();ei!=(*ni)->edges.end();++ei){
                    cout <<"peso : ";
                    cout<<(*ei)->get()<<" nodo :";
                    cout<<(*ei)->nodes[1]->get();
                    cout <<" ";
                }
                cout <<endl;
            }
        }

    private:
        NodeSeq nodes;
        NodeIte ni;
        EdgeIte ei;
};

typedef Graph<Traits> graph;

#endif
