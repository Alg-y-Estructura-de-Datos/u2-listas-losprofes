#include <iostream>
#include "../Lista/ListaDoble.h"
#include <string>

using namespace std;

class Estudiante {
private:
    string nombre;
    int edad;

public:
    Estudiante(const string& nom, int ed) : nombre(nom), edad(ed) {}

    string getNombre() const { return nombre; }
    int getEdad() const { return edad; }

    void setNombre(const string& nom) { nombre = nom; }
    void setEdad(int ed) { edad = ed; }

    // Sobrecarga del operador << para imprimir Estudiante
    friend ostream& operator<<(ostream& os, const Estudiante& e) {
        os << "Nombre: " << e.nombre << ", Edad: " << e.edad;
        return os;
    }
};

// Agregar Estudiantes
void agregarEstudiantes(ListaDoble<Estudiante>& lista) {
    lista.insertarUltimo(Estudiante("Juan", 20));
    lista.insertarUltimo(Estudiante("Ana", 22));
    lista.insertarUltimo(Estudiante("Luis", 19));
    lista.insertarUltimo(Estudiante("María", 21));
    lista.insertarUltimo(Estudiante("Pedro", 23));
}

// Mostrar Estudiantes
void mostrarEstudiantes(const ListaDoble<Estudiante>& lista) {
    cout << "Lista de Estudiantes:" << endl;
    lista.imprimir();
}

// Buscar Estudiante por Nombre
Estudiante* buscarEstudiantePorNombre(const ListaDoble<Estudiante>& lista, const string& nombre) {
    int tamanio = lista.getTamanio();
    for (int i = 0; i < tamanio; ++i) {
        Estudiante est = lista.getDato(i);
        if (est.getNombre() == nombre) {
            return new Estudiante(est); // Devolvemos una copia del estudiante encontrado
        }
    }
    return nullptr; // No se encontró el estudiante
}

// Eliminar Estudiante por Nombre
void eliminarEstudiantePorNombre(ListaDoble<Estudiante>& lista, const string& nombre) {
    int tamanio = lista.getTamanio();
    for (int i = 0; i < tamanio; ++i) {
        Estudiante est = lista.getDato(i);
        if (est.getNombre() == nombre) {
            lista.remover(i);
            return; // Eliminar el estudiante y salir
        }
    }
    cout << "Estudiante no encontrado." << endl;
}

// Contar Estudiantes
void contarEstudiantes(const ListaDoble<Estudiante>& lista) {
    cout << "Número de estudiantes: " << lista.getTamanio() << endl;
}

int main() {

    cout << "Ejercicio 02/07 Listas " << endl;

    ListaDoble<Estudiante> listaEstudiantes;

    // Agregar estudiantes a la lista
    agregarEstudiantes(listaEstudiantes);

    // Mostrar estudiantes
    mostrarEstudiantes(listaEstudiantes);

    // Buscar un estudiante por nombre
    string nombreABuscar = "Ana";
    Estudiante* estudianteEncontrado = buscarEstudiantePorNombre(listaEstudiantes, nombreABuscar);
    if (estudianteEncontrado) {
        cout << "Estudiante encontrado: " << *estudianteEncontrado << endl;
        delete estudianteEncontrado; // Liberar la memoria
    } else {
        cout << "Estudiante no encontrado." << endl;
    }

    // Eliminar un estudiante por nombre
    string nombreAEliminar = "Luis";
    eliminarEstudiantePorNombre(listaEstudiantes, nombreAEliminar);
    mostrarEstudiantes(listaEstudiantes);

    // Contar estudiantes
    contarEstudiantes(listaEstudiantes);

    return 0;
}
