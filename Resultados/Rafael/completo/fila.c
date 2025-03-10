#include "fila.h"
#include "ticket.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
/**
 * Uma estrutura que armazenará os tickets que serão atribuidos aos técnicos.
 *
 * A estrutura seguirá a ideia de uma Fila, isto é, primeiro ticket deve ser o primeiro a ser tratado.
 */
struct Fila
{
    Ticket** elementos;
    int qtd;
    int capacidade;
};

/**
 * @brief Aloca uma estrutura Fila na memória e inicializa os parâmetro necessários
 * @return  Uma Fila inicializada.
 */
Fila *criaFila()
{
    Fila* f = (Fila*)malloc(sizeof(Fila));
    assert(f && "Erro ao alocar fila");

    f->capacidade = 10;
    f->qtd = 0;

    f->elementos = (Ticket**)malloc(sizeof(Ticket*)*f->capacidade);
    
    return f;
}

/**
 * @brief  Desaloca uma fila da memória
 * @param f estrutura do tipo Fila que deve ser liberada da memória
 * @return (void)
 */
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

/**
 * @brief  Insere um ticket na fila de processamento. Um ticket deve ser inserido sempre na última posição.
 * Obviamente, essa função também faz a manipulação de memória necessária para alocar um novo ticket.
 * @param f  Fila que receberá o novo ticket
 * @param cpfSol CPF de quem está solicitando a abertura do ticket
 * @param dado   Um ticket genérico  (considerando que existe mais de um tipo de ticket)
 * @param getTempo  Função de callback que retorna o tempo para aquele ticket ser resolvido (ver ticket.h)
 * @param getTipo   Função de callback que retorna o tipo do ticket ser resolvido (ver ticket.h)
 * @param notifica  Função de callback de notificação de um ticket (ver ticket.h)
 * @param desaloca  Função de callback que desaloca  um ticket da memória (ver ticket.h)
 */
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

/**
 * @brief Recupera a quantidade de tickets  em uma fila
 * @param f  Estrutura Fila inicializada.
 * @return Quantidade de Tickets na fila
 */
int getQtdTicketsNaFila(Fila *f)
{
    return f->qtd;
}

/**
 * @brief Recupera a quantidade de tickets em uma fila com um determinado status
 * @param f  Estrutura Fila inicializada.
 * @param status Status do ticket
 * @return Quantidade de Tickets na fila com o status informado
 */
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

/**
 * @brief Recupera um ticket na fila de processamento. Um ticket deve ser recuperado sempre na i-ésima posição.
 * @param f  Fila que contém o ticket
 * @param i  Posição do ticket na fila
 * @return  Ticket recuperado da fila
 */
Ticket *getTicketNaFila(Fila *f, int i)
{
    return (f->elementos[i]);
}

/**
 * @brief A função notificaFila imprime todos os tickets na Fila f
 * @param f  Fila inicializada contendo zero ou mais tickets.
 */
void notificaFila(Fila *f)
{
    for (int i = 0; i < f->qtd; i++)
    {
        notificaTicket(getTicketNaFila(f, i));
    }
}
