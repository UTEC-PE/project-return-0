//#include <GL/glut.h>
#include <iostream>
#include "read.h"
#include "graph.h"

using namespace std;

int main(int argc, char *argv[]) {
    graph g1;
    /*g1.tipo(false);
    g1.insertar_nodo(1,1,'A');
    g1.insertar_nodo(2,2,'B');
    g1.insertar_nodo(3,3,'C');
    g1.insertar_nodo(4,4,'D');
    g1.insertar_nodo(4,4,'A');
    g1.insertar_arista('A','B',2);
    g1.insertar_arista('A','C',3);
    g1.insertar_arista('A','D',4);
    cout <<endl;
    g1.print();
    cout <<endl;
    cout <<endl;
    g1.eliminar_nodo('A');
    cout <<endl;
    g1.print();
    */
    rd gg;
    gg.getGraph(&g1);
    g1.print();
    cout <<endl;
    g1.conexo();
    g1.prim();
    system("PAUSE");
    return EXIT_SUCCESS;
}



//git checkout -b feature/prim
//git push origin feature/prim
