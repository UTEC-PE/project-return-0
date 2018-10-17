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

    Graph(){};
    void tipo(bool tipo){
        dir=tipo;
    };
    void insertar_nodo(double x, double y, N vertice){
        if (buscar_vertice(vertice)!=nullptr){
            cout<<"Nodo "<<vertice <<" ya existente"<<endl;
            system("pause");
            return;
        }
        node* temp=new node(x,y,vertice);
        nodes.push_back(temp);
    };
    void insertar_arista(N v1,N v2,E peso){
        if (buscar_arista(v1,v2)!=nullptr){
            cout<<"Arista "<<v1<<"-"<<v2<<" ya existe"<<endl;
            system("pause");
            return;
        }
        edge* temp1=new edge(peso);
        for (ni=nodes.begin();ni!=nodes.end();++ni){
            if ((*ni)->get()==v1){
                temp1->nodes[0]=(*ni);
            }
            if ((*ni)->get()==v2){
                temp1->nodes[1]=(*ni);
            }
        }
        if(dir==false){
            temp1->nodes[0]->edges.push_back(temp1);
            temp1->nodes[1]->edges.push_back(temp1);
        }
        else{temp1->nodes[0]->edges.push_back(temp1);}
    }
    EdgeIte eliminar_arista(N v1,N v2){
        EdgeIte ers;
        edge* temp;
        for (ni=nodes.begin();ni!=nodes.end();++ni){
            if ((*ni)->get()==v1){
                for(ei=(*ni)->edges.begin();ei!=(*ni)->edges.end();++ei){
                    if((*ei)->nodes[1]->get()==v2){
                        temp=(*ei);
                        ei=(*ni)->edges.erase(ei);
                        ers=ei;
                    }
                }
            }
            if(dir==false){
                if ((*ni)->get()==v2){
                    for(ei=(*ni)->edges.begin();ei!=(*ni)->edges.end();++ei){
                        if((*ei)->nodes[0]->get()==v1){
                            ei=(*ni)->edges.erase(ei);
                        }
                    }
                }
            }
        }
        delete temp;
        return ers;
    }
    void eliminar_nodo(N v1){
        NodeIte nii;
        EdgeIte eii;
        for (nii=nodes.begin();nii!=nodes.end();++nii){
            if ((*nii)->get()==v1){
                for(eii=(*nii)->edges.begin();eii!=(*nii)->edges.end();++eii){
                    eii=eliminar_arista((*eii)->nodes[0]->get(),(*eii)->nodes[1]->get());

                }
                delete (*nii);
                nii=nodes.erase(nii);
            }
        }
    }
    node* buscar_vertice(N v1){
        for (ni=nodes.begin();ni!=nodes.end();++ni){
            if ((*ni)->get()==v1){
                return (*ni);
            }
        }
        return nullptr;
    }
    edge* buscar_arista(N v1,N v2){
        for (ni=nodes.begin();ni!=nodes.end();++ni){
            if ((*ni)->get()==v1){
                for(ei=(*ni)->edges.begin();ei!=(*ni)->edges.end();++ei){
                    if((*ei)->nodes[1]->get()==v2){
                        return (*ei);
                    }
                }
            }
        }
        return nullptr;
    }
    void print(){
        for (ni=nodes.begin();ni!=nodes.end();++ni){
            cout <<(*ni)->get()<<endl;
            for(ei=(*ni)->edges.begin();ei!=(*ni)->edges.end();++ei){
                cout <<"peso : ";
                cout<<(*ei)->get()<<" nodo :";
                if((*ni)->get()!= (*ei)->nodes[1]->get()){
                    cout<<(*ei)->nodes[1]->get();
                }else{
                    cout<<(*ei)->nodes[0]->get();
                }
                cout <<" / ";
            }
            cout <<endl;
        }
    }

private:
    bool dir;
    NodeSeq nodes;
    NodeIte ni;
    EdgeIte ei;
};

typedef Graph<Traits> graph;

#endif