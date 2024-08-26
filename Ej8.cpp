
using namespace std;
#include <iostream>
#include <string>
#include "Lista/CircList.h"
#include <thread>
#include <chrono>

// Función para mostrar las frases en el monitor de manera circular
template <typename T>
void mostrarFrasesCircular(CircList<T>& lista) {
    if (lista.esVacia()) {
        cout << "No hay frases para mostrar." << endl;
        return;
    }

    int pos = 0; // Empezamos desde la posición 0

    while (true) { // Bucle infinito para mostrar las frases circularmente
        cout << lista.getDato(pos) << endl; // Mostrar el dato en la posición actual
        pos = (pos + 1) % lista.getTamanio(); // Avanzar a la siguiente posición, circularmente

        // Introducir un retraso de 1 segundo
        this_thread::sleep_for(chrono::seconds(3)); // Retraso de 3 segundo
    }
}

// Función principal
int main() {
    CircList<string> lista;

    // Agregar frases a la lista
    lista.insertarUltimo("Gran venta de fin de temporada!");
    lista.insertarUltimo("50% de descuento en toda la tienda.");
    lista.insertarUltimo("Compra uno y llevate el segundo a mitad de precio.");
    lista.insertarUltimo("Visitanos hoy y obten un regalo sorpresa.");

    std::cout << "Mostrando frases de anuncios en el monitor:" << std::endl;

    // Mostrar las frases en el monitor de manera circular
    mostrarFrasesCircular(lista);

    return 0;
}
