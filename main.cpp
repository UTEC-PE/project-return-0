//#include <GL/glut.h>
#include <iostream>
#include "read.h"
#include "graph.h"

using namespace std;

int main(int argc, char *argv[]) {
//    cout<<"***************************************\n";
//    cout<<"******************GRAFO_1**************\n";
//    cout<<"***************************************\n\n";
    graph g1;
    g1.tipo(false);
    g1.insertar_nodo(1,1,'A');
    g1.insertar_nodo(2,2,'B');
    g1.insertar_nodo(3,3,'C');
    g1.insertar_nodo(4,4,'D');
    g1.insertar_nodo(4,4,'A');
    g1.insertar_nodo(2,2,'B');
    g1.insertar_nodo(2,5,'E');
    g1.insertar_nodo(2,6,'F');

    g1.insertar_arista('B','E',2);
    g1.insertar_arista('E','C',3);
    g1.insertar_arista('C','B',2);
    g1.insertar_arista('B','D',4);
    g1.insertar_arista('A','D',6);

    g1.insertar_arista('C','D',11);

    g1.insertar_arista('E','D',15);
    cout <<endl;
    g1.print();
    cout <<endl;
    cout <<endl;
//    g1.buscar_vertice('A');
//    g1.eliminar_nodo('A');
    cout <<endl;
//    g1.print();
    cout <<endl;
    cout <<endl;
//    cout<<"***************************************\n";
//    cout<<"******************GRAFO_2**************\n";
//    cout<<"***************************************\n\n";
//    graph g2;
//    rd gg;
//
//    gg.getGraph(&g2);
//    g2.print();
//    cout <<endl;
//    g2.dfs();
//    g1.BFS();
//    if (g1.BFS()==true){
//        cout << "es conchatumarte";
//    }
//    g1.conexo();
//    g1.prim();
    cout<<"kruskal";
    cout <<endl;   cout <<endl;
    g1.kruskal();
//    g1.bipartito();
//    cout<<g1.densidad()<<endl;
//    g1.info_nodo();
    system("PAUSE");
    return EXIT_SUCCESS;
}



//git checkout -b feature/prim
//git push origin feature/prim
