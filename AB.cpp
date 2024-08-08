#include <iostream>

using namespace std;

struct Nodo {
    Nodo* izq;
    Nodo* der;
    int dato;
};

Nodo* creacion(Nodo* raiz) {
    char op;
    if (raiz == NULL) {
        raiz = new Nodo;
    }
    cout << "DATO: ";
    cin >> raiz->dato;

    cout << raiz->dato << " Tiene rama izquierda? (s/n): ";
    cin >> op;
    if (op == 's') {
        raiz->izq = new Nodo;
        creacion(raiz->izq);
    } else {
        raiz->izq = NULL;
    }

    cout << raiz->dato << " Tiene rama derecha? (s/n): ";
    cin >> op;
    if (op == 's') {
        raiz->der = new Nodo;
        creacion(raiz->der);
    } else {
        raiz->der = NULL;
    }

    return raiz;
}

void recorridoInorden(Nodo* nodo) {
    if (nodo != NULL) {
        recorridoInorden(nodo->izq);
        cout << nodo->dato << " ";
        recorridoInorden(nodo->der);
    }
}

void recorridoPreorden(Nodo* nodo) {
    if (nodo != NULL) {
        cout << nodo->dato << " ";
        recorridoPreorden(nodo->izq);
        recorridoPreorden(nodo->der);
    }
}

void recorridoPostorden(Nodo* nodo) {
    if (nodo != NULL) {
        recorridoPostorden(nodo->izq);
        recorridoPostorden(nodo->der);
        cout << nodo->dato << " ";
    }
}

int main() {
    Nodo* raiz = NULL;
    int opcion;

    do {
        cout << "\nMenu de opciones:" << endl;
        cout << "1. Crear arbol" << endl;
        cout << "2. Recorrido Inorden" << endl;
        cout << "3. Recorrido Preorden" << endl;
        cout << "4. Recorrido Postorden" << endl;
        cout << "5. Salir" << endl;
        cout << "Ingrese su opcion: ";
        cin >> opcion;

        switch (opcion) {
            case 1:
                raiz = creacion(raiz);
                break;
            case 2:
                cout << "Recorrido Inorden: ";
                recorridoInorden(raiz);
                cout << endl;
                break;
            case 3:
                cout << "Recorrido Preorden: ";
                recorridoPreorden(raiz);
                cout << endl;
                break;
            case 4:
                cout << "Recorrido Postorden: ";
                recorridoPostorden(raiz);
                cout << endl;
                break;
            case 5:
                cout << "Saliendo del programa." << endl;
                break;
            default:
                cout << "Opcion invalida. Intente de nuevo." << endl;
        }
    } while (opcion != 5);

    return 0;
}

