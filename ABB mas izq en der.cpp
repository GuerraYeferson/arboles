#include <iostream>

using namespace std;

struct Nodo {
    int inf;
    Nodo* izq;
    Nodo* der;
};

void insertar(Nodo *&raiz, int dato) {
    if (raiz != NULL) {
        if (dato < raiz->inf) {
            insertar(raiz->izq, dato);
        } else if (dato > raiz->inf) {
            insertar(raiz->der, dato);
        } else {
            cout << "El dato ya está en el árbol..." << endl;
        }
    } else {
        raiz = new Nodo;
        raiz->inf = dato;
        raiz->izq = NULL;
        raiz->der = NULL;
    }
}

bool buscar(Nodo* raiz, int dato) {
    if (raiz == NULL) {
        return false;
    } else if (dato < raiz->inf) {
        return buscar(raiz->izq, dato);
    } else if (dato > raiz->inf) {
        return buscar(raiz->der, dato);
    } else {
        return true;
    }
}

void eliminar(Nodo *&raiz, int dato) {
    if (raiz == NULL) return;

    if (dato < raiz->inf) {
        eliminar(raiz->izq, dato);
    } else if (dato > raiz->inf) {
        eliminar(raiz->der, dato);
    } else {
        Nodo *q = raiz;

        // Nodo con un solo hijo o sin hijos
        if (raiz->izq == NULL) {
            raiz = raiz->der;
        } else if (raiz->der == NULL) {
            raiz = raiz->izq;
        } else {
            // Nodo con dos hijos
            Nodo *aux = raiz->der;
            Nodo *aux1 = NULL;

            // Encontrar el nodo más a la izquierda en el subárbol derecho
            while (aux->izq != NULL) {
                aux1 = aux;
                aux = aux->izq; // Moverse al hijo izquierdo
            }

            // Reemplazar el valor del nodo a eliminar con el valor del sucesor inorden
            raiz->inf = aux->inf;

            // Reemplazar el nodo más a la izquierda en el subárbol derecho
            if (aux1 != NULL) {
                aux1->izq = aux->der; // Conectar el subárbol derecho del sucesor
            } else {
                raiz->der = aux->der; // Caso especial si el sucesor es el hijo derecho inmediato
            }

            q = aux;
        }
        delete q;
    }
}

int contarNodos(Nodo* raiz) {
    if (raiz == NULL) {
        return 0;
    }
    // Contar el nodo actual y luego contar nodos en los subárboles izquierdo y derecho
    return 1 + contarNodos(raiz->izq) + contarNodos(raiz->der);
}


int altura(Nodo *raiz) 
{
    if(raiz == NULL){
    	return 0;
	}
    
    int alturaizq = altura(raiz->izq);
	int alturader = altura(raiz->der);
	
	if (alturaizq > alturader) {
        return 1 + alturaizq;
    } else {
        return 1 + alturader;
    }
    
}

void recorridoInorden(Nodo* raiz) {
    if (raiz != NULL) {
        recorridoInorden(raiz->izq);
        cout << raiz->inf << " ";
        recorridoInorden(raiz->der);
    }
}

void recorridoPreorden(Nodo* raiz) {
    if (raiz != NULL) {
        cout << raiz->inf << " ";
        recorridoPreorden(raiz->izq);
        recorridoPreorden(raiz->der);
    }
}

void recorridoPostorden(Nodo* raiz) {
    if (raiz != NULL) {
        recorridoPostorden(raiz->izq);
        recorridoPostorden(raiz->der);
        cout << raiz->inf << " ";
    }
}



void menu() {
    cout << "\n--- Menu de operaciones para el ABB ---" << endl;
    cout << "1. Insertar un nodo" << endl;
    cout << "2. Buscar un nodo" << endl;
    cout << "3. Eliminar un nodo" << endl;
    cout << "4. Contar nodos" << endl;
    cout << "5. Calcular altura" << endl;
    cout << "6. Recorrido Inorden" << endl;
    cout << "7. Recorrido Preorden" << endl;
    cout << "8. Recorrido Postorden" << endl;
    cout << "9. Salir" << endl;
    cout << "Seleccione una opcion: ";
}

int main() {
    Nodo* raiz = NULL;
    int opcion, dato;
    char opc;

    do {
        menu();
        cin >> opcion;

        switch (opcion) {
            case 1:
                do {
                    system("cls");
                    cout << "Ingrese el valor a insertar: ";
                    cin >> dato;
                    insertar(raiz, dato);
                    cout << "Nodo insertado." << endl;
                    cout << "\n\nMAS DATOS ? (s/n): ";
                    cin >> opc;
                } while (opc == 's');
                system("pause");
                break;
            case 2:
                system("cls");
                cout << "Ingrese el valor a buscar: ";
                cin >> dato;
                if (buscar(raiz, dato)) {
                    cout << "El valor " << dato << " se encuentra en el árbol." << endl;
                } else {
                    cout << "El valor " << dato << " no se encuentra en el árbol." << endl;
                }
                system("pause");
                break;
            case 3:
                system("cls");
                cout << "Ingrese el valor a eliminar: ";
                cin >> dato;
                eliminar(raiz, dato);
                cout << "Nodo eliminado (si existía)." << endl;
                system("pause");
                break;
            case 4:
                system("cls");
                cout << "El número total de nodos es: " << contarNodos(raiz) << endl;
                system("pause");
                break;
            case 5:
                system("cls");
            	cout << " La altura del arbol es: " << altura(raiz) << endl;
                system("pause");
                break;
            case 6:
                system("cls");
                cout << "Recorrido Inorden: ";
                recorridoInorden(raiz);
                cout << endl;
                system("pause");
                break;
            case 7:
                system("cls");
                cout << "Recorrido Preorden: ";
                recorridoPreorden(raiz);
                cout << endl;
                system("pause");
                break;
            case 8:
                system("cls");
                cout << "Recorrido Postorden: ";
                recorridoPostorden(raiz);
                cout << endl;
                system("pause");
                break;
            case 9:
                system("cls");
                cout << "Saliendo del programa." << endl;
                break;
            default:
                cout << "Opción inválida. Intente de nuevo." << endl;
                system("pause");
        }
    } while (opcion != 9);

    return 0;
}

