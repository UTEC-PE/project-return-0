#ifndef READ_H
#define READ_H

#include <iostream>
#include <fstream>
#include <cmath>
#include <cstdlib>
#include <string>
#include "graph.h"

using namespace std;
class Trts {
public:
    typedef char N;
    typedef int E;
};

template <typename Tr>
class Read {
    typedef typename Tr::N N;
    typedef typename Tr::E E;
    string file;

public:
    Read() {
            cout<<"Escriba el nombre del archivo a leer: ";
        cin>>file;
        ifstream theFile(file);
        if(!theFile.is_open()) {
            cout << "El archivo no existe...\n";
        }else{
            cout<<"Se logro abrir el archivo...\n\n";
        }
        // TODO
    }

    void getGraph(graph* g1) {
        ifstream theFile(file);

        if(theFile.is_open()){
        double x, y;
        N a, b, c;
        E m, peso;
        bool flag;
        int i=0;


        theFile >> flag;
        g1->tipo(flag);
        theFile >> m;

            while(i != m){
                    theFile >> x >> y >> c;
                    g1->insertar_nodo(x, y, c);
                    i++;
            }
            while(theFile){
                theFile>>a>>b>>peso;
                if(a==';')
                    break;
                g1->insertar_arista(a, b, peso);
            }



    }
    }
    ~Read(){

    }
};
typedef Read<Trts> rd;

#endif
