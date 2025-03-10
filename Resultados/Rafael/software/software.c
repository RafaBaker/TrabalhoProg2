#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include "software.h"

struct Software
{
    char nome[MAX_TAM_NOME_SOFTWARE];
    char categoria[MAX_TAM_CAT];
    int impacto;
    char motivo[MAX_TAM_MOTIVO];
    int tempoEstimado;
};

Software *criaSoftware(char *nome, char *categoria, int impacto, char *motivo)
{
    Software* s = malloc(sizeof(Software));

    strcpy(s->nome, nome);
    strcpy(s->categoria, categoria);
    strcpy(s->motivo, motivo);
    s->impacto = impacto;

    return s;
}

Software *lerSoftware()
{
    char nome[MAX_TAM_NOME_SOFTWARE];
    char categoria[MAX_TAM_CAT];
    char motivo[MAX_TAM_MOTIVO];
    int impacto;
    Software* s = NULL;

    scanf("%[^\n]", nome);
    scanf("%*c");

    scanf("%[^\n]", categoria);
    scanf("%*c");

    scanf("%d\n", &impacto);

    scanf("%[^\n]", motivo);
    scanf("%*c");

    s = criaSoftware(nome, categoria, impacto, motivo);
    return s;
}

void setTempoEstimadoSoftware(Software *s)
{
    if (!strcmp(s->categoria, "BUG"))
    {
        s->tempoEstimado = TEMPO_ESTIMADO_BUG + s->impacto;
    }

    else if (!strcmp(s->categoria, "OUTROS"))
    {
        s->tempoEstimado = TEMPO_ESTIMADO_OUTROS + s->impacto;
    }

    else if (!strcmp(s->categoria, "DUVIDA"))
    {
        s->tempoEstimado = TEMPO_ESTIMADO_DUVIDA + s->impacto;
    }
}

int getTempoEstimadoSoftware(void *dado)
{
    Software* s = (Software*)dado;
    return s->tempoEstimado;
}

char getTipoSoftware()
{
    return 'S';
}

void desalocaSoftware(void *s)
{
    if (s)
    {
        free(s);
    }
    s = NULL;
}

void notificaSoftware(void *dado)
{
    Software* s = (Software*)dado;
    printf("- Tipo: Software\n- Nome do software: %s\n- Categoria: %s\n- Nível do impacto: %d\n- Motivo: %s\n- Tempo estimado: %dh\n", s->nome, s->categoria, s->impacto, s->motivo, getTempoEstimadoSoftware(dado));
}
