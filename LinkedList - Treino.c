#include <stdio.h>
#include <stdlib.h>

struct no{
    int valor;
    struct no* proximo;
};

struct linkedList{
    struct no* cabeca;
    int tamanho;
};

struct linkedList* inicializar(){
    struct linkedList* lista = (struct linkedList*) malloc(sizeof(struct linkedList));
    lista -> cabeca = NULL;
    lista -> tamanho = 0;
    return lista;
}

void inserirFinal(struct linkedList* lista, int valor){
    struct no* novoNo = (struct no*) malloc(sizeof(struct no));
    novoNo -> valor = valor;
    novoNo -> proximo = NULL;
    
    struct no* aux = lista -> cabeca;
    if(aux != NULL){
        while(aux -> proximo != NULL){
            aux = aux->proximo;
        }
        aux -> proximo = novoNo;
    }
    else{
        lista -> cabeca = novoNo;
    }
    lista->tamanho++;
}

void imprimir(struct linkedList* lista){
    if(lista->cabeca!=NULL){
        struct no* aux = lista->cabeca;
        do{
            printf("%d", aux -> valor);
            
            aux = aux->proximo;
        } while (aux!= NULL);
    }
    else{
        printf("lista vazia");
    }
}

int main()
{
    struct linkedList* lista = inicializar();
    inserirFinal(lista, 8);
    inserirFinal(lista, 9);
    inserirFinal(lista, 12);
    
    imprimir(lista);

    return 0;
}
