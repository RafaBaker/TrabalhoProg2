#include "fila.h"
#include "ticket.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
struct Fila
{
    Ticket** elementos;
    int qtd;
    int capacidade;
};

Fila *criaFila()
{
    Fila* f = (Fila*)malloc(sizeof(Fila));
    assert(f && "Erro ao alocar fila");

    f->capacidade = 10;
    f->qtd = 0;

    f->elementos = (Ticket**)malloc(sizeof(Ticket*)*f->capacidade);
    
    return f;
}

void desalocaFila(Fila *f)
{
    if (f)
    {
        if (f->elementos)
        {
            for (int i = 0; i < f->qtd; i++)
            {
                desalocaTicket(f->elementos[i]);
            }
            free(f->elementos);
            f->elementos = NULL;
        }
        free(f);
    }
    f = NULL;
}

void insereTicketFila(Fila *f, char *cpfSol, void *dado, func_ptr_tempoEstimado getTempo,
                      func_ptr_tipo getTipo, func_ptr_notifica notifica, func_ptr_desaloca desaloca)
{
    Ticket* t = criaTicket(cpfSol, dado, getTempo, getTipo, notifica, desaloca);

    //criando o id
    char id[MAX_TAM_ID];
    sprintf(id, "Tick-%d", f->qtd+1);
    setIDTicket(t, id);

    if (f->capacidade == f->qtd)
    {
        f->capacidade *= 2;
        f->elementos = realloc(f, sizeof(Ticket*)*f->capacidade);
    }
    f->elementos[f->qtd] = t;
    f->qtd++;
}

int getQtdTicketsNaFila(Fila *f)
{
    return f->qtd;
}

int getQtdTicketsPorStatusNaFila(Fila *f, char status)
{
    int qtd = 0;
    for (int i = 0; i < f->qtd; i++)
    {
        if (getStatusTicket(f->elementos[i]) == status)
        {
            qtd++;
        }
    }
    return qtd;
}

Ticket *getTicketNaFila(Fila *f, int i)
{
    return (f->elementos[i]);
}

void notificaFila(Fila *f)
{
    for (int i = 0; i < f->qtd; i++)
    {
        notificaTicket(getTicketNaFila(f, i));
    }
}
