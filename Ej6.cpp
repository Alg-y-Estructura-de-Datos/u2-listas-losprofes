#include <iostream>
#include "../Lista/CircList.h"
#include <string>

using namespace std;

// Definición de la clase Contacto aquí
class Contacto {
public:
    string nombre;
    string telefono;

    Contacto() : nombre(""), telefono("") {}
    Contacto(const string &n, const string &t) : nombre(n), telefono(t) {}

    // Sobrecarga del operador <<
    friend ostream& operator<<(ostream &os, const Contacto &c) {
        os << "Nombre: " << c.nombre << ", Teléfono: " << c.telefono;
        return os;
    }

    bool operator==(const Contacto& other) const {
        return nombre == other.nombre;
    }
};

// Función para mostrar todos los contactos
void mostrarContactos( CircList<Contacto> &lista) {
    if (lista.esVacia()) {
        cout << "La lista de contactos está vacía." << endl;
        return;
    }
    lista.imprimir();
}

// Función para buscar un contacto por nombre
bool buscarContacto(CircList<Contacto> &lista, string &nombre) {
    int tamanio = lista.getTamanio();
    for (int i = 0; i < tamanio; i++) {
        Contacto c = lista.getDato(i);
        if (c.nombre == nombre) {
            cout << "Contacto encontrado: " << c << endl;
            return true;
        }
    }
    cout << "Contacto no encontrado." << endl;
    return false;
}

// Función para eliminar un contacto por nombre
void eliminarContacto(CircList<Contacto> &lista, string &nombre) {
    int tamanio = lista.getTamanio();
    for (int i = 0; i < tamanio; i++) {
        Contacto c = lista.getDato(i);
        if (c.nombre == nombre) {
            // Suponiendo que implementarás eliminarPorValor en CircList
            lista.eliminarPorValor(c);
            cout << "Contacto eliminado: " << c << endl;
            return;
        }
    }
    cout << "Contacto no encontrado para eliminar." << endl;
}

int main() {
    CircList<Contacto> lista;

    // Agregar contactos a la lista
    lista.insertarUltimo(Contacto("Alice", "123456"));
    lista.insertarUltimo(Contacto("Bob", "654321"));
    lista.insertarUltimo(Contacto("Charlie", "789012"));
    lista.insertarUltimo(Contacto("Diana", "345678"));
    lista.insertarUltimo(Contacto("Eve", "901234"));

    // Mostrar contactos
    cout << "Lista de contactos:" << endl;
    mostrarContactos(lista);

    // Buscar contacto
    string nombreABuscar = "Charlie";
    cout << "Buscando contacto con nombre " << nombreABuscar << ":" << endl;
    buscarContacto(lista, nombreABuscar);

    // Eliminar contacto
    string nombreAEliminar = "Bob";
    cout << "Eliminando contacto con nombre " << nombreAEliminar << ":" << endl;
    eliminarContacto(lista, nombreAEliminar);

    // Mostrar contactos después de eliminar
    cout << "Lista de contactos después de la eliminación:" << endl;
    mostrarContactos(lista);

    // Contar contactos
    cout << "Número de contactos en la lista: " << lista.getTamanio() << endl;

    return 0;
}