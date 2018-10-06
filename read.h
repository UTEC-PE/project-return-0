#ifndef READ_H
#define READ_H

#include <iostream>
#include <fstream>
#include <cmath>
#include <cstdlib>
#include <string>
#include "graph.h"

using namespace std;
/*
 * Clase de ayuda para leer el grafo desde un archivo,
 * no es necesario que la utilicen, podrían implementar su lector
 * desde su grafo o algún otro lado
 **/
template <typename G>
class Read {

private:
    string file;

public:
		Read() {
		    ;
            // TODO
        }

        void get(){
		    cout<<"ingrese el nombre del archivo: ";
            cin >> file;
            ifstream theFile(file);

            if(!theFile.is_open()){
                cout<<"El archivo no existe...\n";
            }else{
                double x;
                double y;
                int m, a, b, peso;
                bool flag;
                graph g1;
                    theFile>>m;
                    int i=0;

                    while(i!=m){

                        theFile >> x >> y;

                        g1.insertar_nodo(x, y, i);
                        i++;

                    }
                    while(theFile){
                        theFile>>a>>b>>peso>>flag;
                        g1.insertar_arista(a,b,peso,flag);
                    }

                g1.print();
//                g1.insertar_arista('A','C',3,0);
//                g1.insertar_arista('A','D',4,0);
//                cout <<endl;
//                    cout<<word<<" ";
//                    opn >> word;
                }

		};

		graph& getGraph() {
        }

};

#endif
