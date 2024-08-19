/*
Implementar una función llamada “printLista” que reciba una lista y una
 posición “p” eimprima los elementos de esa lista a partir de la posición “p”.
 No debe modificarse la lista original.
 Ej: listaOriginal: 1->2->3->4->5->6->7->8->9->10 con p=5 Por pantalla se verá:
5->6->7->8->9->10
 */

#include <iostream>
#include "Lista/Lista.h"

using namespace std;

void printLista(Lista<int> &lista, int p) {
    int tamanio = lista.getTamanio();

    if (p >= tamanio || p < 0) {
        cout << "La posición " << p << " está fuera de los límites de la lista." << endl;
        return;
    }

    for (int i = p; i < tamanio; i++) {
        cout << lista.getDato(i) << "->";
    }
    cout << "NULL" << endl;
}
/*
void printLista(Lista<int>& lista, int p) {
    Lista<T> listaAuxiliar;

    // Copiar elementos desde la posición p hasta el final en la lista auxiliar
    for (int i = p; i < lista.getTamanio(); i++) {
        listaAuxiliar.insertarUltimo(lista.getDato(i));
    }

    // Imprimir la lista auxiliar
    listaAuxiliar.print();
}
*/

int main() {
    cout << "Ejercicio 02/01 Listas " << endl;

    Lista<int> Lista;
    int n, d, p;

    cout<<"Ingrese el tamaño de la Lista: ";
    cin>>n;

    for (int i = 0; i < n; i++) {
        cout<<"Ingrese el valor de la lista en la posicion: "<<i<<endl;
        cin>>d;
        Lista.insertarUltimo(d);
    }

    cout<<"Ingrese la posicion desde donde desea imprimir la Lista: "<<endl;
    cin>>p;

    printLista(Lista, p);

    return 0;
}
