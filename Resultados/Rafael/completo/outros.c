#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include "outros.h"

struct Outros
{
    char descricao[MAX_TAM_DESC_OUTROS];
    char local[MAX_TAM_LOCAL_OUTROS];
    int dificuldade;
    int tempoEstimado;
};

Outros *criaOutros(char *descricao, char *local, int dificuldade)
{
    Outros* o = (Outros*)malloc(sizeof(Outros));

    strcpy(o->descricao, descricao);
    strcpy(o->local, local);
    o->dificuldade = dificuldade;
    o->tempoEstimado = dificuldade;

    return o;
}

Outros *lerOutros()
{
    char descricao[MAX_TAM_DESC_OUTROS];
    char local[MAX_TAM_LOCAL_OUTROS];
    int dificuldade = -1;

    scanf("%[^\n]", descricao);
    scanf("%*c");

    scanf("%[^\n]", local);
    scanf("%*c");

    scanf("%d\n", &dificuldade);

    Outros* o = criaOutros(descricao, local, dificuldade);
    return o;
}

int getTempoEstimadoOutros(void *dado)
{
    Outros* o = (Outros*)dado;
    return o->tempoEstimado;
}

char getTipoOutros()
{
    return 'O';
}

void desalocaOutros(void *o)
{
    if (o)
    {
        free(o);
    }
    o = NULL;
}

void notificaOutros(void *dado)
{
    Outros* o = (Outros*)dado;
    printf("- Tipo: Outros\n- Descricao: %s\n- Local: %s\n- Nivel de Dificuldade: %d\n- Tempo Estimado: %dh\n", o->descricao, o->local, o->dificuldade, getTempoEstimadoOutros(dado));
}

