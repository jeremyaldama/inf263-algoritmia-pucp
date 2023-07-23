#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef int TInfo;

typedef struct Nodo{
    TInfo info;
    struct Nodo* next;
} TNodo;

typedef struct Pila{
    TNodo* first;
    TNodo* last;
} TPila;


void push(TPila* L, TInfo x){
    TNodo* nuevo = (TNodo*)malloc(sizeof(TNodo));
    nuevo->info = x;
    nuevo->next = NULL;

    if(L->first == NULL)
        L->last = nuevo;
    nuevo->next = L->first;
    L->first = nuevo;
}

TInfo top(TPila* L){
    return L->first->info;
}

void pop(TPila* L){
    TNodo* aux = L->first;

    L->first = L->first->next;
    if(L->first==NULL)
        L->last = NULL;

    free(aux);
}

int empty(TPila *L){
    return (L->first==NULL);
}


int main(){
    char* cadena = "24*63/+";

    TPila P;
    P.first = P.last = NULL;

    int i;
    for(i = 0; i < strlen(cadena); i++){
        if(isdigit(cadena[i])){
            push(&P, (int)(cadena[i]-'0'));
        }else{
            int x1 = top(&P); pop(&P);
            int x2 = top(&P); pop(&P);
            int res;

            switch(cadena[i]){
                case '+': res = x1 + x2; break;
                case '-': res = x2 - x1; break;
                case '*': res = x1 * x2; break;
                case '/': res = x2 / x1; break;
            }

            push(&P, res);
        }
    }

    printf("El resultado es %d\n", top(&P));

    return 0;

}

