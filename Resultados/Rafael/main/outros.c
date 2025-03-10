#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include "outros.h"

/**
 * Estrutura de um Ticket Outros contendo os parametros especificos de um ticket do tipo OUTROS
 */
struct Outros
{
    char descricao[MAX_TAM_DESC_OUTROS];
    char local[MAX_TAM_LOCAL];
    int dificuldade;
    int tempoEstimado;
};

/**
 * @brief Aloca uma estrutura Outros na memória e inicializa os parâmetro necessários
 * @param descricao Descricao do ticket
 * @param local local do ticket
 * @param dificuldade dificuldade estimada pelo usuário
 * @return  Uma estrutura Outros inicializada.
 */
Outros *criaOutros(char *descricao, char *local, int dificuldade)
{
    Outros* o = (Outros*)malloc(sizeof(Outros));

    strcpy(o->descricao, descricao);
    strcpy(o->local, local);
    o->dificuldade = dificuldade;
    o->tempoEstimado = dificuldade;

    return o;
}

/**
 * @brief Lê da entrada padrão um  ticket do TIPO outros
 * @return  Um chamado do Tipo Outros
 */
Outros *lerOutros()
{
    char descricao[MAX_TAM_DESC_OUTROS];
    char local[MAX_TAM_LOCAL];
    int dificuldade = -1;

    scanf("%[^\n]", descricao);
    scanf("%*c");

    scanf("%[^\n]", local);
    scanf("%*c");

    scanf("%d\n", &dificuldade);

    Outros* o = criaOutros(descricao, local, dificuldade);
    return o;
}

/**
 * @brief  Retorna o tempo estimado para resolver um ticket do tipo Outros.
 * @param dado  Ticket do tipo Outros
 * @return  Tempo estimado para resolver um ticket do tipo Outros
 */
int getTempoEstimadoOutros(void *dado)
{
    Outros* o = (Outros*)dado;
    return o->tempoEstimado;
}

/**
 * @brief  Retorna o tipo do ticket
 * @return  'O' para Outros
 */
char getTipoOutros()
{
    return 'O';
}

/**
 * @brief  Desaloca um ticket do tipo Outros da memória
 * @param o  Ticket do tipo Outros
 */
void desalocaOutros(void *o)
{
    if (o)
    {
        free(o);
    }
    o = NULL;
}

/**
 * @brief  Imprime um ticket do tipo Outros
 * @param dado  Ticket do tipo Outros
 */
void notificaOutros(void *dado)
{
    Outros* o = (Outros*)dado;
    printf("- Tipo: Outros\n- Descricao: %s\n- Local: %s\n- Nivel de Dificuldade: %d\n- Tempo Estimado: %dh\n", o->descricao, o->local, o->dificuldade, getTempoEstimadoOutros(dado));
}

