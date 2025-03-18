#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include "ticket.h"

struct Ticket
{
    void *ticket;
    char id[MAX_TAM_ID];
    char status;
    char cpf[MAX_TAM_CPF];
    func_ptr_notifica notifica;
    func_ptr_desaloca desaloca;
    func_ptr_tempoEstimado getTempo;
    func_ptr_tipo getTipo;
};

typedef void (*func_ptr_notifica)(void *dado);

typedef void (*func_ptr_desaloca)(void *dado);

typedef int (*func_ptr_tempoEstimado)(void *dado);

typedef char (*func_ptr_tipo)();

Ticket *criaTicket(char *cpfSol, void *dado, func_ptr_tempoEstimado getTempo,
                   func_ptr_tipo getTipo, func_ptr_notifica notifica, func_ptr_desaloca desaloca)
{
    Ticket* ticket = (Ticket*)malloc(sizeof(Ticket));
    assert(ticket && "Erro ao alocar ticket");

    ticket->status = 'A';
    strcpy(ticket->cpf, cpfSol);
    ticket->id[0] = '\0';

    ticket->getTipo = getTipo;
    ticket->getTempo = getTempo;
    ticket->desaloca = desaloca;
    ticket->notifica = notifica;
    ticket->ticket = dado;

    return ticket;
}

void setIDTicket(Ticket *d, char *id)
{
    strcpy(d->id, id);
}

void finalizaTicket(Ticket *t)
{
    t->status = 'F';
}

char *getCPFSolicitanteTicket(Ticket *t)
{
    return t->cpf;
}

int getTempoEstimadoTicket(Ticket *t)
{
    return t->getTempo(t->ticket);
}

char getTipoTicket(Ticket *t)
{
    return t->getTipo();
}

char getStatusTicket(Ticket *t)
{
    return t->status;
}

void desalocaTicket(Ticket *doc)
{
    if (doc)
    {
        doc->desaloca(doc->ticket);
        free(doc);
    }
    doc = NULL;
}

void notificaTicket(Ticket *doc)
{
    printf("---------TICKET-----------\n");
    printf("- ID: %s\n- Usuario solicitante: %s\n", doc->id, doc->cpf);
    doc->notifica(doc->ticket);

    switch (doc->status)
    {
    case 'F':
        printf("- Status: Finalizado\n"); 
        break;
    case 'A':
        printf("- Status: Aberto\n");
        break;
    default:
        break;
    }
    printf("-------------------------\n");
}
