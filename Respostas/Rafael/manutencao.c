#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include "manutencao.h"

struct Manutencao
{
    char nome[MAX_TAM_NOME_MANUTENCAO];
    char estado[MAX_TAM_ESTADO_MANUTENCAO];
    char local[MAX_TAM_LOCAL_MANUTENCAO];
    int tempoEstimado;
};

Manutencao *criaManutencao(char *nome, char* estado, char *local)
{
    Manutencao* m = (Manutencao*)malloc(sizeof(Manutencao));

    strcpy(m->nome, nome);
    strcpy(m->local, estado);
    strcpy(m->local, local);
    m->tempoEstimado = 0;

    return m;
}

Manutencao *lerManutencao()
{
    char nome[MAX_TAM_NOME_MANUTENCAO];
    char estado[MAX_TAM_ESTADO_MANUTENCAO];
    char local[MAX_TAM_LOCAL_MANUTENCAO];

    scanf("%[^\n]", nome);
    scanf("%*c");

    scanf("%[^\n]", estado);
    scanf("%*c");

    scanf("%[^\n]", local);
    scanf("%*c");


    Manutencao* m = criaManutencao(nome, estado, local);
    return m;
}

void setTempoEstimadoManutencao(Manutencao *m, char* setor)
{
    int fator = 0;
    if (!strcmp(setor, "MARKETING"))
    {
        fator = FATOR_SETOR_MARKETING;
    }
    else if (!strcmp(setor, "VENDAS"))
    {
        fator = FATOR_SETOR_VENDAS;
    }
    else if (!strcmp(setor, "P&D"))
    {
        fator = FATOR_SETOR_PD;
    }
    else if (!strcmp(setor, "RH"))
    {
        fator = FATOR_SETOR_RH;
    }
    else if (!strcmp(setor, "FINANCEIRO"))
    {
        fator = FATOR_SETOR_FINANCEIRO;
    }

    if (!strcmp(m->estado, "RUIM"))
    {
        m->tempoEstimado = fator*TEMPO_RUIM;
    }
    else if (!strcmp(m->estado, "REGULAR"))
    {
        m->tempoEstimado = fator*TEMPO_REGULAR;
    }
    else if (!strcmp(m->estado, "BOM"))
    {
        m->tempoEstimado = fator*TEMPO_BOM;
    }
}

int getTempoEstimadoManutencao(void *dado)
{
    Manutencao* m = (Manutencao*)dado;
    return m->tempoEstimado;
}

char getTipoManutencao()
{
    return 'M';
}

void desalocaManutencao(void *m)
{
    if (m)
    {
        free(m);
    }
    m = NULL;
}

void notificaManutencao(void *dado)
{
    Manutencao* m = (Manutencao*)dado;
    printf("- Tipo: Manutencao\n- Nome do item: %s\n- Estado de conservacao: %s\n- Local: %s\n- Tempo Estimado: %dh\n", m->nome, m->estado, m->local, getTempoEstimadoManutencao(dado));
}

