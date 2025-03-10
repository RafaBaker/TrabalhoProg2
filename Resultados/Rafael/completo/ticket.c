#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include "ticket.h"

/**
 * Estrutura de um Ticket contendo os parametros comuns entre todos os tipos de Tickets e um tipo genérico.
 */
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

/**
 * @brief Função de callback para notificar (imprimir) um ticket
 * @param dado um tipo genérico para representar os tipos de tickets.
 */
typedef void (*func_ptr_notifica)(void *dado);

/**
 * @brief Função de callback para desalocar da memória uma implementação especifica de  ticket
 * @param dado um tipo genérico para representar os tipos de tickets.
 */
typedef void (*func_ptr_desaloca)(void *dado);
/**
 * Função de callback para retornar o tempo estimado para resolver um ticket
 * @param dado um tipo genérico para representar os tipos de tickets.
 * @return tempo estimado para resolver um ticket
 *
 *  */
typedef int (*func_ptr_tempoEstimado)(void *dado);

/**
 * Função de callback para retornar o tipo de um ticket
 * @param dado um tipo genérico para representar os tipos de tickets.
 * @return tipo do Ticket
 */

typedef char (*func_ptr_tipo)();

/**
 * @brief Aloca uma estrutura Ticket na memória e inicializa os parâmetro necessários
 * @param cpfSol CPF de quem está solicitando a abertura do ticket
 * @param dado   Um ticket genérico  (considerando que existe mais de um tipo de ticket)
 * @param getTempo  Função de callback que retorna o tempo para aquele ticket ser resolvido
 * @param getTipo   Função de callback que retorna o tipo do ticket ser resolvido
 * @param notifica  Função de callback de notificação  (impressãode um ticket
 * @param desaloca  Função de callback que irá desalocar  um ticket da memória
 * @return  Uma estrutura Ticket inicializada.
 */
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

/**
 * @brief Atribui um ID a um ticket
 * @param d Ticket inicializado
 * @param id ID a ser atribuido ao ticket
 */
void setIDTicket(Ticket *d, char *id)
{
    strcpy(d->id, id);
}

/**
 * @brief Finaliza um ticket
 * @param t Ticket inicializado
 */
void finalizaTicket(Ticket *t)
{
    t->status = 'F';
}

/**
 * @brief Recupera o CPF de quem solicitou a abertura do ticket
 * @param t Ticket inicializado
 * @return CPF de quem solicitou a abertura do ticket
 */
char *getCPFSolicitanteTicket(Ticket *t)
{
    return t->cpf;
}

/**
 * @brief Recupera o tempo estimado para resolver um ticket
 * @param t Ticket inicializado
 * @return tempo estimado para resolver um ticket
 */
int getTempoEstimadoTicket(Ticket *t)
{
    return t->getTempo(t->ticket);
}

/**
 * @brief Recupera o tipo de um ticket
 * @param t Ticket inicializado
 * @return tipo do Ticket
 */
char getTipoTicket(Ticket *t)
{
    return t->getTipo();
}

/**
 * @brief Recupera o status de um ticket
 * @param t Ticket inicializado
 * @return status do Ticket
 */
char getStatusTicket(Ticket *t)
{
    return t->status;
}

/**
 * @brief  Desaloca um ticket da memória
 * @param doc estrutura do tipo Ticket que deve ser liberada da memória
 */
void desalocaTicket(Ticket *doc)
{
    if (doc)
    {
        doc->desaloca(doc->ticket);
        free(doc);
    }
    doc = NULL;
}

/**
 * @brief  Notifica (imprime) um ticket
 * @param doc Ticket a ser notificado
 */
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
