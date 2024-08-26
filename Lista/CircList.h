#ifndef U02_LISTAS_LISTA_CIRCLIST_H_
#define U02_LISTAS_LISTA_CIRCLIST_H_
#include "nodo.h"

template <class T>
class CircList
{
private:
    Nodo<T> *inicio;

public:
    CircList();

    CircList(const CircList<T> &li);

    ~CircList();

    bool esVacia();

    int getTamanio();

    void insertar(int pos, T dato);

    void insertarPrimero(T dato);

    void insertarUltimo(T dato);

    T getDato(int pos);

    void eliminarPorValor(const T& valor);

    void imprimir();
};

/**
 * Constructor de la clase CircList
 * @tparam T
 */
template <class T>
CircList<T>::CircList() { inicio = nullptr; }

/**
 * Constructor por copia de la clase CircList
 * @tparam T
 * @param li
 */
template <class T>
CircList<T>::CircList(const CircList<T> &li) { inicio = li.inicio; }

/**
 * Destructor de la clase CircList, se encarga de liberar la memoria de todos los
 * nodos utilizados en la Circlist
 * @tparam T
 */
template <class T>
CircList<T>::~CircList() {}

template <class T>
bool CircList<T>::esVacia()
{
    return inicio == nullptr;
}

template <class T>
int CircList<T>::getTamanio()
{
    Nodo<T> *aux = inicio;
    int tam = 0;

    if (esVacia())
    {
        return tam;
    }

    while (aux->getSiguiente() != inicio)
    {
        aux = aux->getSiguiente();
        tam++;
    }

    tam++;
    return tam;
}
template <class T>
void CircList<T>::insertar(int pos, T dato)
{
    if (pos < 0) {
        throw std::out_of_range("Posición negativa no válida");
    }

    if (pos != 0 && esVacia()) {
        throw 400;  // No se puede insertar en una posición diferente a 0 si la lista está vacía
    }

    Nodo<T> *nuevo = new Nodo<T>();
    nuevo->setDato(dato);

    if (pos == 0) {
        if (esVacia()) {
            nuevo->setSiguiente(nuevo);
            inicio = nuevo;
        } else {
            Nodo<T> *aux = inicio;
            while (aux->getSiguiente() != inicio) {
                aux = aux->getSiguiente();
            }
            nuevo->setSiguiente(inicio);
            aux->setSiguiente(nuevo);
            inicio = nuevo;  // El nuevo nodo se convierte en el inicio
        }
        return;
    }

    Nodo<T> *aux = inicio;
    int posActual = 0;

    while (aux->getSiguiente() != inicio && posActual < pos - 1) {
        aux = aux->getSiguiente();
        posActual++;
    }

    if (posActual < pos - 1) {
        throw std::out_of_range("Posición fuera del rango de la lista");
    }

    nuevo->setSiguiente(aux->getSiguiente());
    aux->setSiguiente(nuevo);
}

template <class T>
void CircList<T>::insertarPrimero(T dato)
{
    insertar(0, dato);
}
template <class T>
void CircList<T>::insertarUltimo(T dato)
{
    Nodo<T> *nuevo = new Nodo<T>;
    nuevo->setDato(dato);

    if (esVacia())
    {
        nuevo->setSiguiente(nuevo);
        inicio = nuevo;
        return;
    }

    Nodo<T> *aux = inicio;
    while (aux->getSiguiente() != inicio)
    {
        aux = aux->getSiguiente();
    }

    nuevo->setSiguiente(inicio); // Simplificación del código
    aux->setSiguiente(nuevo);
}

template <class T>
T CircList<T>::getDato(int pos) {
    if (pos < 0 || esVacia()) {
        throw 404;  // Posición inválida
    }

    Nodo<T> *aux = inicio;
    int posActual = 0;

    do {
        if (posActual == pos) {
            return aux->getDato();
        }
        aux = aux->getSiguiente();
        posActual++;
    } while (aux != inicio);

    throw 404;  // Posición fuera del rango de la lista
}


template <class T>
void CircList<T>::imprimir()
{
    if (esVacia()) {
        std::cout << "La lista está vacía." << std::endl;
        return;
    }

    Nodo<T> *aux = inicio;

    do {
        std::cout << aux->getDato() << "->";
        aux = aux->getSiguiente();
    } while (aux != inicio);

    std::cout << "..." << std::endl;
}
template <class T>
void CircList<T>::eliminarPorValor(const T& valor) {
    if (esVacia()) {
        return;
    }

    Nodo<T> *actual = inicio;
    Nodo<T> *previo = nullptr;
    Nodo<T> *ultimo = inicio;

    // Encontrar el último nodo
    while (ultimo->getSiguiente() != inicio) {
        ultimo = ultimo->getSiguiente();
    }

    do {
        if (actual->getDato() == valor) {
            if (actual == inicio) {
                // Caso especial cuando se elimina el primer nodo
                if (inicio == inicio->getSiguiente()) { // Un solo nodo en la lista
                    delete inicio;
                    inicio = nullptr;
                    return;
                } else { // Más de un nodo
                    ultimo->setSiguiente(inicio->getSiguiente());
                    Nodo<T>* temp = inicio;
                    inicio = inicio->getSiguiente();
                    delete temp;
                    actual = inicio; // Continuar con el siguiente nodo
                }
            } else {
                // Nodo en cualquier otra posición
                previo->setSiguiente(actual->getSiguiente());
                delete actual;
                return;
            }
        } else {
            previo = actual;
            actual = actual->getSiguiente();
        }
    } while (actual != inicio);
}


#endif // U02_LISTAS_LISTA_CIRCLIST_H_