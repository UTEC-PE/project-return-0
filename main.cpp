//#include <GL/glut.h>
#include <iostream>
#include "read.h"
#include "graph.h"

using namespace std;

int main(int argc, char *argv[]) {
    cout<<"***************************************\n";
    cout<<"******************GRAFO_1**************\n";
    cout<<"***************************************\n\n";
    graph g1;
    rd gg;
    gg.getGraph(&g1);
    g1.print();
    cout <<endl;
    g1.conexo();
    g1.prim();
    g1.bipartito();
    cout<<"La densidad es: "<<g1.densidad()<<endl;
    g1.info_nodo();
    system("PAUSE");
    return EXIT_SUCCESS;
}



//git checkout -b feature/prim
//git push origin feature/prim
