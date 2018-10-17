#include <iostream>

#include "graph.h"
#include "read.h"

using namespace std;

int main(int argc, char *argv[]) {
    cout << "|||||||||||||||||||||||||||||||||||||||||||||||||||||||\n";
    cout << "||||||||||||||||||||||||Grafo 1||||||||||||||||||||||||\n";
    cout << "|||||||||||||||||||||||||||||||||||||||||||||||||||||||\n\n";
    graph g1;
    g1.tipo(false);
    g1.insertar_nodo(1,1,'A');
    g1.insertar_nodo(2,2,'B');
    g1.insertar_nodo(3,3,'C');
    g1.insertar_nodo(4,4,'D');
    g1.insertar_nodo(4,4,'C');

    g1.insertar_arista('A','B',2);
    g1.insertar_arista('A','C',3);
    g1.insertar_arista('A','D',4);
    g1.insertar_arista('A','B',4);

    cout <<endl;
    g1.print();
    cout <<endl;
    cout <<endl;
    g1.buscar_arista('A','B');
    g1.buscar_arista('C','A');
    g1.buscar_vertice('D');
    g1.eliminar_nodo('A');
    cout <<endl<<"here_2";
    g1.print();

    cout << "|||||||||||||||||||||||||||||||||||||||||||||||||||||||\n";
    cout << "||||||||||||||||||||||||Grafo 2||||||||||||||||||||||||\n";
    cout << "|||||||||||||||||||||||||||||||||||||||||||||||||||||||\n\n";

    rd gg;
    gg.getGraph();
    cout<<"\n\n";
    cout<<"Presione una tecla...";
    cin.get();

    return EXIT_SUCCESS;
}
