#include <iostream>
#include "Lista/Lista.h"

using namespace std;

void eliminarElemento(Lista<int>& lista, int n) {
    int i = 0;

    // Recorremos la lista desde el inicio hasta el final
    while (i < lista.getTamanio()) {
        if (lista.getDato(i) == n) {
            lista.remover(i);  // Eliminar el elemento en la posición i
        } else {
            i++;  // Avanzar solo si no se eliminó un elemento
        }
    }
}

int main() {

    cout << "Ejercicio 02/02 Listas " << endl;

    Lista<int> Lista;
    int t, d, n;

    cout<<"Ingrese el tamaño de la Lista: ";
    cin>>t;

    for (int i = 0; i < t; i++) {
        cout<<"Ingrese el valor de la lista en la posicion: "<<i<<endl;
        cin>>d;
        Lista.insertarUltimo(d);
    }

    cout << "Lista original: ";
    Lista.print();

    cout<<"Ingrese el numero a eliminar de la Lista: "<<endl;
    cin>>n;

    eliminarElemento(Lista, n);

    cout << "Lista despues de eliminar al numero " << n << ": ";
    Lista.print();

    return 0;
}

