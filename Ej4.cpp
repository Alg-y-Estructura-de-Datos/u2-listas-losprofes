#include <iostream>
#include "../Lista/Lista.h"
#include <cctype>  // Para usar la función tolower

using namespace std;

bool esVocal(char c) {
    c = tolower(c);
    return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
}

int contarVocal(Lista<char>& lista, char vocal) {
    int contador = 0;
    for (int i = 0; i < lista.getTamanio(); i++) {
        if (tolower(lista.getDato(i)) == tolower(vocal)) {
            contador++;
        }
    }
    return contador;
}

int main() {

    cout << "Ejercicio 02/04 Listas " << endl;

    Lista<char> lista;
    string frase;
    char vocal;

    // Solicitar al usuario la frase o palabra
    cout << "Ingrese una palabra o frase: ";
    getline(cin, frase);

    // Almacenar cada carácter en la lista
    for (char c : frase) {
        lista.insertarUltimo(c);
    }

    // Validar que la lista no esté vacía
    if (lista.esVacia()) {
        cout << "La lista está vacía. No hay nada que contar." << endl;
        return 0;
    }

    // Solicitar al usuario la vocal que desea contar
    cout << "Ingrese una vocal para contar en la frase: ";
    cin >> vocal;

    // Validar que el carácter ingresado sea una vocal
    if (!esVocal(vocal)) {
        cout << "El carácter ingresado no es una vocal." << endl;
        return 0;
    }

    // Imprimir la lista
    cout << "Lista: ";
    lista.print();

    // Contar la vocal en la lista
    int cantidad = contarVocal(lista, vocal);

    // Imprimir el número de veces que aparece la vocal
    cout << "La vocal '" << vocal << "' aparece " << cantidad << " veces en la lista." << endl;

    return 0;
}
