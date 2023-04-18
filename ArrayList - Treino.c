#include <stdio.h>
#include <stdlib.h>

struct arrayList
{
    int *vetor;
    int quantidade;
    int capacidade;
};

struct arrayList *inicializar(int capacidade)
{
    struct arrayList *lista = (struct arrayList *)malloc(sizeof(struct arrayList));

    lista->vetor = (int *)calloc(capacidade, sizeof(int));

    lista->quantidade = 0;

    lista->capacidade = capacidade;

    return lista;
}

void duplicarCapacidade(struct arrayList *lista)
{
    lista->vetor = (int *)realloc(lista->vetor, 2 * lista->capacidade * sizeof(int));
    lista->capacidade = lista->capacidade * 2;
}

void inserirNoFim(struct arrayList *lista, int valor)
{
    if (lista->quantidade == lista->capacidade)
    {
        duplicarCapacidade(lista);
    }
    lista->vetor[lista->quantidade] = valor;
    lista->quantidade++;
}

voint inserirEmPosicao(struct arrayList *lista, int valor, int posicao)
{
    if (lista->quantidade == lista->capacidade)
    {
        duplicarCapacidade(lista);
    }
    for (int i = posicao; i < lista->quantidade; i++)
    {
        lista->vetor[i + 1] = lista->vetor[i];
    }
    lista->vetor[posicao] = valor;
    lista->quantidade++;
}

int obterValor(struct arrayList *lista, int posicao)
{
    if (posicao < lista->quantidade && posicao >= 0)
    {
        return lista->vetor[posicao];
    }
}

int main()
{
    struct arrayList *lista = inicializar(8);

    duplicarCapacidade(lista);

    for (int i = 0; i < lista->capacidade; i++)
    {
        printf("%d", lista->vetor[i]);
    }

    printf("%d", lista->capacidade);
}