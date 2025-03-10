#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#include "tecnico.h"

struct Tecnico
{
    Ator* ator;
    char area[MAX_TAM_AREA];
    int disponibilidade;
    float salario;
    int tempoTrabalhado;
};

Tecnico* criaTecnico(Ator* ator, char* area, int disponibilidade, float salario)
{
    Tecnico* t = (Tecnico*)malloc(sizeof(Tecnico));

    t->ator = ator;
    strcpy(t->area, area);
    t->disponibilidade = disponibilidade;
    t->salario = salario;
    t->tempoTrabalhado = 0;

    return t;
}

Tecnico* leTecnico()
{
    Ator* a = leAtor();
    char area[MAX_TAM_AREA];
    int disponibilidade;
    float salario;
    int tempoTrabalhado;

    scanf("%[^\n]", area);
    scanf("%*c");

    scanf("%d\n", &disponibilidade);
    scanf("%f\n", &salario);

    Tecnico* t = criaTecnico(a, area, disponibilidade, salario);

    return t;
}

void imprimeTecnico(Tecnico* t)
{
    imprimeAtor(t->ator);

    // - Area de Atuacao: GERAL
    // - Salario: 2000.00
    // - Disponibilidade: 7h
    // - Tempo Trabalhado: 0h
    printf("- Area de Atuacao: %s\n- Salario: %.2f\n- Disponibilidade: %dh\n- Tempo Trabalhado: %dh\n", t->area, t->salario, t->disponibilidade, t->tempoTrabalhado);
}

void desalocaTecnico(Tecnico* t)
{
    if (t)
    {
        if (t->ator)
        {
            desalocaAtor(t->ator);
        }
        free(t);
    }
    t = NULL;
}

int comparaTecnicos(Tecnico* t1, Tecnico* t2)
{
    return ehMesmoAtor(t1->ator, t2->ator);
}
