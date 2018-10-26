#ifndef GRAPH_H
#define GRAPH_H
#include<iostream>
#include <vector>
#include <list>
#include <stack>
#include <map>
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
        double total_nodos(){
            return nodes.size();
        }
        double total_aristas(){
            if(nodes.empty()){
                return 0;
            }
            int c=0;
            for (ni=nodes.begin();ni!=nodes.end();++ni){
                c=c+(*ni)->edges.size();
            }
            if (dir==0){
                return c/2;
            }else{
                return c;
            }

        }
        void info_nodo(){
            N vertice;
            cout<<"Inserte el vertice del que quiere informacion: ";
            cin>>vertice;
            node* temp=buscar_vertice(vertice);
            int c=0;
            if(temp==nullptr){
                cout <<"El vertice no existe"<<endl;
                return;
            }
            if(dir==1){
                cout <<"El grado de salida es: "<<temp->edges.size()<<endl;
                for (ni=nodes.begin();ni!=nodes.end();++ni){
                    for(ei=(*ni)->edges.begin();ei!=(*ni)->edges.end();++ei){
                        if((*ei)->nodes[1]->get()==vertice){
                            c++;
                        }
                    }
                }
                cout <<"El grado de entrada es: "<<c<<endl;
                if(temp->edges.size()==0 && c==0){
                    cout<<"El vertice esta aislado"<<endl;
                }else if(temp->edges.size()==0){
                    cout<<"El vertice es hundido"<<endl;
                }else if(c==0){
                    cout<<"El vertice es fuente"<<endl;
                }
            }else{
                cout <<"El grado del vertice es: "<<temp->edges.size()<<endl;
                if(temp->edges.size()==0){
                    cout<<"El vertice esta aislado"<<endl;
                }
            }
        }
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
        double densidad(){
            if(dir==0){
                return (total_aristas()*2)/(total_nodos()*(total_nodos()-1));
            }else{
                return total_aristas()/(total_nodos()*(total_nodos()-1));
            }

        }

        list<char> dfs(){
            stack<node*> q;
            list<char> tt;
            if(total_aristas()==0){
                return tt;
            }
            node* temp;
            node* temp1;
            q.push(nodes[0]);
            nodes[0]->tool=1;
            while(!q.empty()){
                temp=q.top();
                for(ei=temp->edges.begin();ei!=temp->edges.end();++ei){
                    if(temp!= (*ei)->nodes[1]){
                        temp1=(*ei)->nodes[1];
                    }else{
                        temp1=(*ei)->nodes[0];
                    }
                    if(temp1->tool==0){
                        q.push(temp1);
                        temp1->tool=1;
                        goto endwhile;
                    }

                }

                tt.push_front(q.top()->get());
                q.pop();
            endwhile:;
            }
            for (ni=nodes.begin();ni!=nodes.end();++ni){
                (*ni)->tool=0;
            }
            return tt;
        }
        void conexo(){
            list<char> cierre=dfs();
            if(cierre.size()==nodes.size()){
                if(dir==0){
                    cout<<"El grafo es conexo"<<endl;
                }else{
                    Graph<Traits> g2;
                    g2.tipo(true);
                    for (ni=nodes.begin();ni!=nodes.end();++ni){
                        g2.insertar_nodo(1,1,(*ni)->get());
                    }
                    for (ni=nodes.begin();ni!=nodes.end();++ni){
                        for(ei=(*ni)->edges.begin();ei!=(*ni)->edges.end();++ei){
                            g2.insertar_arista((*ei)->nodes[1]->get(),(*ei)->nodes[0]->get(),1);
                        }
                    }
                    if(g2.dfs().size()==nodes.size()){
                        cout <<"El grafo es fuertemente conexo"<<endl;
                    }else{
                        cout <<"El grafo NO es fuertemente conexo"<<endl;
                    }
                }

            }else{
                cout <<"El grafo no es conexo"<<endl;
            }

        }

        void prim(){
            if(dir==1){
                cout<<"No se puede aplicar prim, el grafo es dirigido"<<endl;
            }else if(dfs().size()!=nodes.size()){
                cout<<"No se puede apliar prim, el grafo no es conexo"<<endl;
            }else{
                map<node*,bool> nodos;
                multimap<E,edge*> pesos;
                typename multimap<E,edge*>::iterator it;
                Graph<Traits> g2;
                g2.tipo(false);
                nodos.insert(pair<node*,bool>(nodes[0],0));
                g2.insertar_nodo(1,1,nodes[0]->get());
                for(ei=nodes[0]->edges.begin();ei!=nodes[0]->edges.end();++ei){
                    pesos.insert(pair<E,edge*>((*ei)->get(),(*ei)));
                }
                while(nodos.size()!=nodes.size()){
                    it=pesos.begin();
                    if(nodos.count(it->second->nodes[1])==0 || nodos.count(it->second->nodes[0])==0){
                        node* temp;
                        if(nodos.count(it->second->nodes[1])==0){
                            temp=it->second->nodes[1];
                        }else{
                            temp=it->second->nodes[0];
                        }
                        nodos.insert(pair<node*,bool>(temp,0));
                        g2.insertar_nodo(1,1,temp->get());
                        g2.insertar_arista(it->second->nodes[0]->get(),it->second->nodes[1]->get(),it->first);
                            pesos.erase(it);
                        for(ei=temp->edges.begin();ei!=temp->edges.end();++ei){
                            pesos.insert(pair<E,edge*>((*ei)->get(),(*ei)));
                        }
                    }else{
                        pesos.erase(it);
                    }
                }
                g2.print();
            }
        }

        void bipartito(){
            if(dfs().size()!=nodes.size()){
                cout <<"El grafo no es conexo"<<endl;
                return;
            }
            map<node*,bool> nodos;
            stack<node*> q;
            node* temp;
            node* temp1;
            q.push(nodes[0]);
            nodos.insert(pair<node*,bool>(nodes[0],0));
            nodes[0]->tool=1;
            while(!q.empty()){
                temp=q.top();
                for(ei=temp->edges.begin();ei!=temp->edges.end();++ei){
                    if(temp!= (*ei)->nodes[1]){
                        temp1=(*ei)->nodes[1];
                    }else{
                        temp1=(*ei)->nodes[0];
                    }
                    if(temp1->tool==0){
                        q.push(temp1);
                        nodos.insert(pair<node*,bool>(temp1,!nodos[temp]));
                        temp1->tool=1;
                        goto endwhile;
                    }else{
                        if(nodos[temp]==nodos[temp1]){
                            cout<<"El grafo no es bipartito"<<endl;
                            return;
                        }
                    }

                }
                q.pop();
            endwhile:;
            }
            for (ni=nodes.begin();ni!=nodes.end();++ni){
                (*ni)->tool=0;
            }
            cout<<"El grafo es bipartito"<<endl;

        }
        ~Graph(){

        }


    private:
        bool dir;
        NodeSeq nodes;
        NodeIte ni;
        EdgeIte ei;
};

typedef Graph<Traits> graph;

#endif
