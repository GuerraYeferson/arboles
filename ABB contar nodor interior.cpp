#include <iostream>
using namespace std;

struct nodo 
{
    nodo *izq;
    nodo *der;
    int valor;
};

int contarNodosInteriores(nodo* raiz) {
    // Caso base: si el nodo es NULL, no hay nodos interiores
    if (raiz == NULL) {
        return 0;
    }

    // Si el nodo es una hoja (sin hijos), no es un nodo interior
    if (raiz->izq == NULL && raiz->der == NULL) {
        return 0;
    }

    // Si el nodo no es una hoja, contamos este nodo + nodos interiores en sus subárboles
    int contarIzq = contarNodosInteriores(raiz->izq);
    int contarDer = contarNodosInteriores(raiz->der);
    
    // El nodo actual es un nodo interior si tiene al menos un hijo
    return 1 + contarIzq + contarDer;
}

void insertarDatos(nodo*& raiz) {
    int valor;
    char respuesta;

    do {
        cout << "Ingrese el valor a agregar: ";
        cin >> valor;
        insertarDatos(raiz);

        cout << "¿Desea insertar otro valor? (s/n): ";
        cin >> respuesta;

    } while (respuesta == 's' || respuesta == 'S');
}

int main() {
    nodo* raiz = NULL; // Inicializa el árbol vacío

    cout << "Inserción de datos en el árbol binario de búsqueda:" << endl;
    insertarDatos(raiz);

    int cantidadInteriores = contarNodosInteriores(raiz);
    cout << "Numero de nodos interiores: " << cantidadInteriores << endl;

    // Liberar memoria
    // Aquí deberías liberar la memoria del árbol, pero por simplicidad se omite

    return 0;
}

