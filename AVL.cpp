#include<iostream>
#include<iomanip>
using namespace std;

struct nodo
{
    int inf, fe;
    nodo *izq, *der;
};

void insertar_AVL(nodo *&raiz, int dato, bool &cen);
void buscar_AVL(nodo *raiz, int dato);
void eliminar_AVL(nodo *&raiz, int cen, int dato);
void borra(int aux, int q, int cen);
void reestructura1(nodo *&raiz, int cen);
void reestructura2(nodo *&raiz, int cen);
void preorden(nodo *raiz);
void inorden(nodo *raiz);
void postorden(nodo *raiz);
void imprimirArbol(nodo *raiz, int espacio);

int main(void)
{
    nodo *raiz = NULL;
    int dato, op;
    char opc;
    system("cls");
    do
    {
        system("cls");
        cout << "\n\n\n\tMENU - ARBOLES BINARIOS BALANCEADOS\n";
        cout << "\t===================================\n\n";
        cout << "\t1. INSERCION\n\n";
        cout << "\t2. ELIMINACION\n\n";
        cout << "\t3. BUSQUEDA\n\n";
        cout << "\t4. RECORRIDO PREORDEN\n\n";
        cout << "\t5. RECORRIDO EN INORDEN\n\n";
        cout << "\t6. RECORRIDO EN POSTORDEN\n\n";
        cout << "\t7. IMPRESION COMO ARBOL\n\n";
        cout << "\t8. SALIR\n\n";
        cout << "\t\t\tOPCION : "; cin >> op;
        system("cls");
        switch (op)
        {
        case 1:
            do
            {
                system("cls");
                cout << " \n\n\tINGRESE EL DATO A INSERTAR: ";
                cin >> dato;
                bool cen = false;
                insertar_AVL(raiz, dato, cen);
                cout << " \n\n\t\tMAS DATOS? (s/n): ";
                cin >> opc;
            } while (opc == 's');
            system("pause");
            break;
        case 2:
            system("cls");
            cout << "\nINGRESE EL DATO A ELIMINAR: \n";
            cin >> dato;
            eliminar_AVL(raiz, 1, dato);
            system("pause");
            break;
        case 3:
            system("cls");
            cout << "\n\n\tINGRESE EL DATO A BUSCAR: ";
            cin >> dato;
            buscar_AVL(raiz, dato);
            cout << "\n";
            system("pause");
            break;
        case 4:
            system("cls");
            cout << "\n\nRECORRIDO EN PREORDEN: ";
            cout << "\n========================";
            preorden(raiz);
            cout << "\n";
            system("pause");
            break;
        case 5:
            system("cls");
            cout << "\n\nRECORRIDO EN INORDEN: ";
            cout << "\n========================";
            inorden(raiz);
            cout << "\n";
            system("pause");
            break;
        case 6:
            system("cls");
            cout << "\n\nRECORRIDO EN POSTORDEN: ";
            cout << "\n========================";
            postorden(raiz);
            cout << "\n";
            system("pause");
            break;
        case 7:
            system("cls");
            cout << "\n\nIMPRESION COMO ARBOL: ";
            cout << "\n========================";
            imprimirArbol(raiz, 0);
            cout << "\n";
            system("pause");
            break;
        case 8:
            break;
        }

    } while (op < 8);

    return(1);
}

void insertar_AVL(nodo *&raiz, int dato, bool &cen)
{
    nodo *raiz1, *raiz2, *x;
    if (raiz != NULL)
    {
        if (dato < raiz->inf)
        {
            insertar_AVL(raiz->izq, dato, cen);
            if (cen)
            {
                switch (raiz->fe)
                {
                case 1: raiz->fe = 0; cen = false; break;
                case 0: raiz->fe = -1; cen = true; break;
                case -1:
                    raiz1 = raiz->izq;
                    if (raiz1->fe <= 0)
                    {
                        // Rotaci?n II
                        raiz->izq = raiz1->der;
                        raiz1->der = raiz;
                        raiz->fe = 0;
                        raiz = raiz1;
                    }
                    else
                    {
                        // Rotaci?n ID
                        raiz2 = raiz1->der;
                        raiz->izq = raiz2->der;
                        raiz2->der = raiz;
                        raiz1->der = raiz2->izq;
                        raiz2->izq = raiz1;
                        if (raiz2->fe == -1) {
                            raiz->fe = 1;
                        }
                        else {
                            raiz->fe = 0;
                        }
                        if (raiz2->fe == 1) {
                            raiz1->fe = -1;
                        }
                        else {
                            raiz1->fe = 0;
                        }
                        raiz = raiz2;
                    }
                    raiz->fe = 0;
                    cen = false;
                    break;
                }
            }
        }
        else if (dato > raiz->inf)
        {
            insertar_AVL(raiz->der, dato, cen);
            if (cen)
            {
                switch (raiz->fe)
                {
                case -1: raiz->fe = 0; cen = false; break;
                case 0: raiz->fe = 1; cen = true; break;
                case 1:
                    raiz1 = raiz->der;
                    if (raiz1->fe >= 0)
                    {
                        // Rotaci?n DD
                        raiz->der = raiz1->izq;
                        raiz1->izq = raiz;
                        raiz->fe = 0;
                        raiz = raiz1;
                    }
                    else
                    {
                        // Rotaci?n DI
                        raiz2 = raiz1->izq;
                        raiz->der = raiz2->izq;
                        raiz2->izq = raiz;
                        raiz1->izq = raiz2->der;
                        raiz2->der = raiz1;

                        if (raiz2->fe == 1) {
                            raiz->fe = -1;
                        }
                        else {
                            raiz->fe = 0;
                        }

                        if (raiz2->fe == -1) {
                            raiz1->fe = 1;
                        }
                        else {
                            raiz1->fe = 0;
                        }
                        raiz = raiz2;
                    }
                    raiz->fe = 0;
                    cen = false;
                    break;
                }
            }
        }
        else {
            cout << "EL DATO YA EXISTE..." << endl;
        }
    }
    else
    {
        x = new(nodo);
        x->inf = dato;
        x->der = NULL;
        x->izq = NULL;
        x->fe = 0;
        raiz = x;
        cen = true;
    }
}

void buscar_AVL(nodo *raiz, int dato)
{
    if (raiz == NULL) {
        cout << "\n\tEL DATO BUSCADO NO EXISTE...\n\n";
        return;
    }

    if (dato < raiz->inf) {
        buscar_AVL(raiz->izq, dato);
    }
    else if (dato > raiz->inf) {
        buscar_AVL(raiz->der, dato);
    }
    else {
        cout << "\n\tEL DATO BUSCADO SI EXISTE...\n\n";
    }
}

void reestructura1(nodo *&raiz, int cen)
{
    nodo *raiz1, *raiz2;
    if (cen == 1)
    {
        switch (raiz->fe)
        {
        case -1: raiz->fe = 0; break;
        case 0: raiz->fe = 1; cen = 0; break;
        case 1:
            raiz1 = raiz->der;
            if (raiz1->fe >= 0) // DD
            {
                raiz->der = raiz1->izq;
                raiz1->izq = raiz;
                switch (raiz1->fe)
                {
                case 0: raiz->fe = 1; raiz2->fe = -1; cen = 0; break;
                case 1: raiz->fe = 0; raiz1->fe = 0; break;
                }
                raiz = raiz1;
            }
            else // DI
            {
                raiz2 = raiz1->izq;
                raiz->der = raiz2->izq;
                raiz2->izq = raiz;
                raiz1->izq = raiz2->der;
                raiz2->der = raiz1;
                if (raiz2->fe == 1) {
                    raiz->fe = -1;
                }
                else {
                    raiz->fe = 0;
                }
                if (raiz2->fe == -1) {
                    raiz1->fe = 1;
                }
                else {
                    raiz1->fe = 0;
                }
                raiz = raiz2;
                raiz2->fe = 0;
            }
        }
    }
}

void reestructura2(nodo *&raiz, int cen)
{
    nodo *raiz1, *raiz2;
    if (cen == 1)
    {
        switch (raiz->fe)
        {
        case 1: raiz->fe = 0; break;
        case 0: raiz->fe = -1; cen = 0; break;
        case -1:
            raiz1 = raiz->izq;
            if (raiz1->fe <= 0) // II
            {
                raiz->izq = raiz1->der;
                raiz1->der = raiz;
                switch (raiz1->fe)
                {
                case 0: raiz->fe = -1; raiz1->fe = 1; cen = 0; break;
                case -1: raiz->fe = 0; raiz1->fe = 0; break;
                }
                raiz = raiz1;
            }
            else // ID
            {
                raiz2 = raiz1->der;
                raiz->izq = raiz2->der;
                raiz2->der = raiz;
                raiz1->der = raiz2->izq;
                raiz2->izq = raiz1;

                if (raiz2->fe == -1) {
                    raiz->fe = 1;
                }
                else {
                    raiz->fe = 0;
                }
                if (raiz2->fe == 1) {
                    raiz1->fe = -1;
                }
                else {
                    raiz1->fe = 0;
                }
                raiz = raiz2;
                raiz2->fe = 0;
            }
        }
    }
}

void borra(nodo *&aux, nodo *& q, int cen)
{
    if (aux->der != NULL)
    {
        borra(aux->der, q, cen);
        reestructura2(aux, cen);
    }
    else
    {
        q->inf = aux->inf;
        aux = aux->izq;
        cen = 1;
    }
}

void eliminar_AVL(nodo *&raiz, int cen, int dato)
{
    nodo *q;
    if (raiz != NULL)
    {
        if (dato < raiz->inf)
        {
            eliminar_AVL(raiz->izq, cen, dato);
            reestructura1(raiz, cen);
        }
        else
        {
            if (dato > raiz->inf)
            {
                eliminar_AVL(raiz->der, cen, dato);
                reestructura2(raiz, cen);
            }
            else
            {
                q = raiz;
                if (q->der == NULL)
                {
                    raiz = q->izq;
                    cen = 1;
                }
                else
                {
                    if (q->izq == NULL)
                    {
                        raiz = q->der;
                        cen = 1;
                    }
                    else
                    {
                        borra(raiz->izq, q, cen);
                        reestructura1(raiz, cen);
                    }
                }
                //delete(q);
            }

        }
    }
    else
    {
        cout << " EL DATO NO EXISTE " << endl;
    }
}

void preorden(nodo *raiz)
{
    if (raiz != NULL)
    {
        cout << "\n" << " - " << raiz->inf << "\n";
        preorden(raiz->izq);
        preorden(raiz->der);
    }
}

void inorden(nodo *raiz)
{
    if (raiz != NULL)
    {
        inorden(raiz->izq);
        cout << "\n" << " - " << raiz->inf << "\n\n";
        inorden(raiz->der);
    }
}

void postorden(nodo *raiz)
{
    if (raiz != NULL)
    {
        postorden(raiz->izq);
        postorden(raiz->der);
        cout << "\n" << " - " << raiz->inf << "\n\n";
    }
}

void imprimirArbol(nodo *raiz, int espacio)
{
    if (raiz == NULL) {
        return;
    }

    espacio += 10;
    imprimirArbol(raiz->der, espacio);
    cout << endl;

    for (int i = 10; i < espacio; i++) {
        cout << " ";
    }
    cout << raiz->inf << "\n";

    imprimirArbol(raiz->izq, espacio);
}

