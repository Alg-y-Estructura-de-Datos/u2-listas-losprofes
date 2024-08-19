#include <iostream>
#include "../Lista/Lista.h"
#include <limits>

using namespace std;

// Función para encontrar los elementos repetidos en L1 y devolverlos en L2
Lista<int> encontrarRepetidos(Lista<int>& L1) {
    Lista<int> L2;
    Lista<int> yaVistos;

    for (int i = 0; i < L1.getTamanio(); i++) {
        int valor = L1.getDato(i);
        bool encontrado = false;

        // Verificar si el valor ya ha sido visto
        for (int j = 0; j < yaVistos.getTamanio(); j++) {
            if (yaVistos.getDato(j) == valor) {
                encontrado = true;
                break;
            }
        }

        // Si el valor ha sido visto y ya está en L2, lo ignoramos
        if (encontrado) {
            bool enL2 = false;
            for (int j = 0; j < L2.getTamanio(); j++) {
                if (L2.getDato(j) == valor) {
                    enL2 = true;
                    break;
                }
            }
            if (!enL2) {
                L2.insertarUltimo(valor);
            }
        } else {
            // Si el valor no ha sido visto antes, lo agregamos a la lista de vistos
            yaVistos.insertarUltimo(valor);
        }
    }

    return L2;
}

int main() {

    cout << "Ejercicio 02/05 Listas " << endl;

    Lista<int> L1;
    int num;

    // Solicitar al usuario ingresar elementos en L1
    cout << "Ingrese numeros enteros para la lista (ingrese 'q' para terminar):" << endl;
    while (true) {
        cout << "Numero: ";
        if (std::cin >> num) {
            L1.insertarUltimo(num);
        } else {
            cin.clear(); // Limpiar el estado de error del stream
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignorar entrada incorrecta
            break; // Salir del bucle cuando se ingresa algo que no es un número
        }
    }

    // Verificar si la lista no está vacía
    if (L1.esVacia()) {
        cout << "La lista está vacía. No se pueden encontrar elementos repetidos." << endl;
        return 0;
    }

    // Encontrar los elementos repetidos
    Lista<int> L2 = encontrarRepetidos(L1);

    // Imprimir las listas
    cout << "Lista L1: ";
    L1.print();

    if (L2.esVacia()) {
        cout << "No hay elementos repetidos en L1." << endl;
    } else {
        cout << "Lista L2 (elementos repetidos): ";
        L2.print();
    }

    return 0;
}
