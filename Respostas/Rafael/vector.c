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

DataType VectorGet(Vector *v, int i)
{
    return ((DataType*)v->data)[i];
}

int VectorSize(Vector *v)
{
    return v->qtd;
}

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
                    v->data[i] = NULL;
                }
            }
            free(v->data);
        }
        v->data = NULL;
        free(v);
    }
    v = NULL;
}

void VectorPrint(Vector *v, void (*imprime)(DataType))
{
    for (int i = 0; i < VectorSize(v); i++)
    {
        printf("--------------------\n");
        imprime(VectorGet(v, i));
    }
}


void VectorSort(Vector *v, int (*compare)(const void*, const void*))
{
    qsort(v->data, v->qtd, sizeof(void*), compare);

}

void VectorCopy(Vector *src,  Vector* dest)
{
    dest->capacidade = src->capacidade;
    dest->qtd = src->qtd;
    
    dest->data = realloc(dest->data, sizeof(DataType)*dest->capacidade);
    for (int i = 0; i < dest->qtd; i++)
    {
        dest->data[i] = VectorGet(src, i);
    }
}

void VectorDestroyCopy(Vector *v)
{
    if (v)
    {
        if (v->data)
        {
            free(v->data);
        }
        v->data = NULL;
        free(v);
    }
    v = NULL;
}