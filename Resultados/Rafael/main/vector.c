#include "vector.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

typedef void *DataType; // void pointer

struct Vector
{
    DataType* data;
    int qtd;
    int capacidade;
};


/**
 * @brief Cria um vetor vazio
 * 
 * @return A estrutura Vector inicializada. Caso não seja possível alocar memória, o programa é encerrado.
*/
Vector *VectorConstruct()
{
    Vector* v = (Vector*)malloc(sizeof(Vector));
    assert(v && "erro ao alocar vetor");

    v->capacidade = 10;
    v->qtd = 0;

    v->data = malloc(sizeof(DataType) * v->capacidade);
    assert(v->data && "erro ao alocar dados");

    return v;
}

/**
 * @brief Adiciona um elemento no final do vetor
 * 
 * @param v Ponteiro para o vetor
 * @param val Valor a ser adicionado
*/
void VectorPushBack(Vector *v, DataType val)
{
    if (v->qtd == v->capacidade)
    {
        v->capacidade *= 2;
        v->data = realloc(v->data, sizeof(DataType)*v->capacidade);
    }
    ((DataType*)v->data)[v->qtd] = val;
    v->qtd++;
}

/**
 * @brief Remove o primeiro elemento do vetor e organiza os demais elementos, ou seja, 
 * o segundo elemento passa a ser o primeiro, o terceiro passa a ser o segundo, e assim por diante.
 * 
 * @param v Ponteiro para o vetor
 * @return DataType Elemento removido
*/
DataType VectorPopFront(Vector *v)
{
    DataType first = ((DataType*)v->data)[0];
    for (int i = 0; i < v->qtd-1; i++)
    {
        v->data[i] = v->data[i+1];
    }
    //free(v->data[v->qtd]);
    //v->data[v->qtd] = NULL;
    v->qtd--;
    return first;
}

/**
 * @brief Retorna o i-ésimo elemento do vetor
 * 
 * @param v Ponteiro para o vetor
 * @param i Índice do elemento
 * @return DataType Elemento do vetor
*/
DataType VectorGet(Vector *v, int i)
{
    return ((DataType*)v->data)[i];
}

/**
 * @brief Retorna o tamanho do vetor
 * 
 * @param v Ponteiro para o vetor
 * @return int Tamanho do vetor
*/
int VectorSize(Vector *v)
{
    return v->qtd;
}

/**
 * @brief Libera a memória alocada para o vetor
 * 
 * @param v Ponteiro para o vetor
 * @param destroy Função que libera a memória alocada para cada elemento do vetor
*/
void VectorDestroy(Vector *v, void (*destroy)(DataType))
{
    if (v)
    {
        if (v->data)
        {
            for (int i = 0; i < v->qtd; i++)
            {
                if (v->data[i])
                {
                    destroy(((DataType*)v->data)[i]);
                }
            }
            free(v->data);
        }
        free(v);
    }
}

