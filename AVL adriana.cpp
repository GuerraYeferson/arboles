#include <bits/stdc++.h>
using namespace std;

struct nodo {
    int inf,fe;
    nodo *izq,*der;
};

void inserta_avl (nodo *& , int& , int);
void buscar_avl (nodo * , int );
void elimina_avl (nodo *& ,int&, int );
void borra (nodo *&, nodo *, int&);
void reestructura1 (nodo *&, int&);
void reestructura2 (nodo *&, int&);
void preorden (nodo *);
void inorden (nodo *);
void postorden (nodo *);

int main () {
    nodo *raiz = NULL;
    int op, dato;
    char opc;
    int cen = 1;

    do {
        system ("cls");
        cout<<"\n\n\tMENU - ARBOLES BINARIOS BALANCEADOS (AVL)\n";
        cout<<"\t================================================\n";
        cout<<"\t1. INSERCION\n";
        cout<<"\t2. ELIMINACION\n";
        cout<<"\t3. BUSQUEDA\n";
        cout<<"\t4. RECORRIDOS\n";
        cout<<"\t5. S A L I R\n"; 
        cout<<"\t\t\tOPCION: ";cin>>op;
        system ("cls");

        switch (op) {
            case 1:
                do {
                    system ("cls");
                    cout<<"\nINGRESE EL DATO A INSERTAR: ";cin>>dato;
                    inserta_avl(raiz,cen,dato);
                    cout<<"\n\n\t\tMAS DATOS (s/n)?: ";cin>>opc;
                } while (opc=='S' or opc=='s');
                system ("pause");
            break;
            case 2:
                system ("cls");
                cout<<"\nINGRESE EL DATO A ELIMINAR: ";cin>>dato;
                elimina_avl (raiz,cen,dato);
                system ("pause");
            break;
            case 3:
                system ("cls");
                cout<<"\nINGRESE EL DATO A BUSCAR: ";cin>>dato;
                buscar_avl(raiz,dato);
                system ("pause");
            break;
            case 4:
                system ("cls");
                cout<<"\n\tRECORRIDOS";
                cout<<"\n\t*\n\n";
                cout<<"PREORDEN: \n";
                cout<<"\t";preorden(raiz);
                cout<<"\n\n";
                cout<<"INORDEN: \n";
                cout<<"\t";inorden(raiz);
                cout<<"\n\n";
                cout<<"POSTORDEN: \n";
                cout<<"\t";postorden(raiz);
                cout<<"\n\n";
                system ("pause");  
            break;  
        }

    } while (op<5);

    return 0;
}

void inserta_avl (nodo *&raiz,int& cen, int dato) {
    nodo *raiz1,*raiz2,*x;
    if (raiz!=NULL) {
        if (dato<raiz->inf) {
            inserta_avl(raiz->izq,cen,dato);
            if (cen == 1) {
                switch (raiz->fe) {
                    case 1: 
                        raiz->fe = 0;
                        cen = 0;
                        break;
                    case 0:
                        raiz->fe = -1;
                        break;
                    case -1:
                        raiz1 = raiz->izq;
                        if (raiz1->fe<=0) {
                            //Izquierda Izquierda
                            raiz->izq = raiz1->der;
                            raiz1->der = raiz;
                            raiz->fe = 0;
                            raiz = raiz1;
                        }
                        else {
                            //Izquierda Derecha
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
                                raiz2->fe = 0;
                            }
                            raiz = raiz2;
                        }
                        raiz->fe = 0;
                        cen = 0;
                        break;
                }
            }
        }
        else if (dato>raiz->inf) {
            inserta_avl (raiz->der,cen,dato);
            if (cen == 1){
                switch (raiz->fe) {
                    case -1: 
                        raiz->fe = 0;
                        cen = 0;
                        break;
                    case 0:
                        raiz->fe = 1;
                        break;
                    case 1:
                        raiz1 = raiz->der;
                        if (raiz1->fe>=0) {
                            //Derecha Derecha
                            raiz->der = raiz1->izq;
                            raiz1->izq = raiz;
                            raiz->fe = 0;
                            raiz = raiz1;
                        }
                        else {
                            //Derecha Izquierda
                            raiz2 = raiz1->izq;
                            raiz->der = raiz2->izq;
                            raiz2->izq = raiz;
                            raiz1->izq = raiz2->der;
                            raiz2->der = raiz1;
                            if (raiz2->fe == 1)
                                raiz->fe = -1;
                            else   
                                raiz->fe = 0;
                            if (raiz2->fe == -1)
                                raiz1->fe = 1;
                            else   
                                raiz1->fe = 0;
                            raiz = raiz2;
                        }
                        raiz->fe = 0;
                        cen = 0;
                        break;
                }
            }
        }
        else {
            cout<<"\nEL DATO YA EXISTE EN EL ARBOL...\n\n";
        }
    }
    else {
        x = new (nodo);
        x->inf = dato;
        x->der = NULL;
        x->izq = NULL;
        x->fe = 0;
        raiz = x;
        cen = 1;
    }
}

void buscar_avl (nodo *raiz, int dato) {
    if (dato<raiz->inf) {
        if (raiz->izq==NULL)
            cout<<"\n\n\tEL DATO BUSCADO NO EXISTE EN EL ARBOL...\n\n";
        else   
            buscar_avl (raiz->izq,dato);
    }
    else {
        if (dato>raiz->inf) {
            if (raiz->der==NULL)
                cout<<"\n\n\tEL DATO BUSCADO NO EXISTE EN EL ARBOL...\n\n";
            else    
                buscar_avl (raiz->der,dato);
        }
        else {
                cout<<"\n\n\tEL DATO BUSCADO SI EXISTE EN EL ARBOL...\n\n";
        }
    }
}

void reestructura1 (nodo*&raiz, int& cen) {
    if (cen == 1) {
        switch (raiz->fe) {
            case -1: raiz->fe = 0; break;
            case 0: raiz->fe = 1; cen = 0; break;
            case 1:
                nodo *raiz1 = raiz->der;
                if (raiz1->fe >= 0) {
                    //Derecha Derecha
                    raiz->der = raiz1->izq;
                    raiz1->izq = raiz;
                    switch (raiz1->fe) {
                        case 0:
                            raiz->fe = 1;
                            raiz1->fe = -1;
                            cen = 0;
                        break;
                        case 1: 
                            raiz->fe = 0;
                            raiz1->fe = 0;
                        break;
                    }
                    raiz = raiz1;
                }
                else {
                    //Derecha Izquierda
                    nodo *raiz2 = raiz1->izq;
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
            break;    
        }
    }
}

void reestructura2 (nodo *&raiz, int& cen) {
    if (cen == 1) {
        switch (raiz->fe) {
            case 1: raiz->fe = 0; break;
            case 0: raiz->fe = -1; cen = 0; break;
            case -1:
                nodo *raiz1 = raiz->izq;
                if (raiz->fe <= 0) {
                    //Izquierda Izquierda
                    raiz->izq = raiz1->der;
                    raiz1->der = raiz;
                    switch (raiz1->fe) {
                    case 0:
                        raiz->fe = -1;
                        raiz1->fe = 1;
                        cen = 0;
                    break;
                    case -1:
                        raiz->fe = 0;
                        raiz1->fe = 0;
                    break;
                    }
                    raiz = raiz1;
                }
                else {
                    //Izquierda Derecha
                    nodo *raiz2 = raiz1->der;
                    raiz->izq = raiz2->der;
                    raiz2->der = raiz;
                    raiz1->der = raiz2->izq;
                    raiz2->izq = raiz1;
                    if (raiz->fe == -1) {
                        raiz->fe = 1;
                    }
                    else {
                        raiz->fe = 0;
                    }
                    raiz = raiz2;
                    raiz2->fe = 0;
                }
            break;
        }
    }
}

void borra (nodo *&aux, nodo *q, int& cen) {
    if (aux->der!=NULL) {
        borra(aux->der, q, cen);
        reestructura2 (aux, cen);
    }
    else {
        q->inf = aux->inf;
        aux = aux->izq;
        cen = 1;
    }
}

void elimina_avl (nodo *&raiz, int& cen, int dato) {
    if (raiz != NULL) {
        if (dato < raiz->inf) {
            elimina_avl (raiz->izq,cen, dato);
            reestructura1 (raiz,cen);
        }
        else {
            if (dato > raiz->inf) {
                elimina_avl (raiz->der, cen, dato);
                reestructura2 (raiz, cen);
            }
            else {
                nodo *q = raiz;
                if (q->der == NULL) {
                    raiz = q->izq;
                    cen = 1;
                }
                else if (q->izq == NULL) {
                    raiz = q->der;
                    cen = 1;
                }
                else {
                    borra(raiz->izq, q, cen);
                    reestructura1 (raiz, cen);
                }
            }
        }
    }
    else {
        cout<<"\n\nEL DATO NO EXISTE EN EL ARBOL...\n\n";
    }
}

void preorden (nodo *raiz) {
    if (raiz!=NULL) {
        cout<<"["<<raiz->inf<<"] ";
        preorden (raiz->izq);
        preorden (raiz->der);
    }
}

void inorden (nodo *raiz) {
    if (raiz!=NULL) {
        inorden (raiz->izq);
        cout<<"["<<raiz->inf<<"] ";
        inorden (raiz->der);
    }
}

void postorden (nodo *raiz) {
    if (raiz!=NULL) {
        postorden (raiz->izq);
        postorden (raiz->der);
        cout<<"["<<raiz->inf<<"] ";
		}
}
