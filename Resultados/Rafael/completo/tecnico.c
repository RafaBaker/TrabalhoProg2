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

    scanf("%[^\n]", area);
    scanf("%*c");

    scanf("%d\n", &disponibilidade);
    scanf("%f\n", &salario);

    Tecnico* t = criaTecnico(a, area, disponibilidade, salario);

    return t;
}

void imprimeTecnico(void* t)
{
    Tecnico* tec = (Tecnico*)t;

    imprimeAtor(tec->ator);

    // - Area de Atuacao: GERAL
    // - Salario: 2000.00
    // - Disponibilidade: 7h
    // - Tempo Trabalhado: 0h
    printf("- Area de Atuacao: %s\n- Salario: %.2f\n- Disponibilidade: %dh\n- Tempo Trabalhado: %dh\n", tec->area, tec->salario, tec->disponibilidade, tec->tempoTrabalhado);
}

void desalocaTecnico(void* t)
{
    if (t)
    {
        Tecnico* tec = (Tecnico*)t;
        if (tec->ator)
        {
            desalocaAtor(tec->ator);
        }
        tec->ator = NULL;
        free(t);
    }
    t = NULL;
}

int ehMesmoTecnico(Tecnico* t1, Tecnico* t2)
{
    return ehMesmoAtor(t1->ator, t2->ator);
}

int getTempoTrabalhado(Tecnico* t)
{
    return t->tempoTrabalhado;
}

int getDisponibilidade(Tecnico* t)
{
    return t->disponibilidade;
}

int getIdadeTec(Tecnico* t, Data* dtRef)
{
    return getIdadeAtor(t->ator, dtRef);
}

char getAreaAtuacao(Tecnico* t)
{
    if (!strcmp(t->area, "GERAL"))
        return 'G';

    if (!strcmp(t->area, "TI"))
    {
        return 'T';
    }
}

char* getNomeTecnico(Tecnico* t)
{
    return getNomeAtor(t->ator);
}

int numBytesTecnico()
{
    return sizeof(Tecnico);
}

void atribuiTicket(Tecnico* t, Ticket* ticket)
{
    t->disponibilidade -= getTempoEstimadoTicket(ticket);
    t->tempoTrabalhado += getTempoEstimadoTicket(ticket);
    finalizaTicket(ticket);
}

//Função que vai ser usado no qsort
int comparaTecnicos(const void* t1, const void* t2)
{
    Tecnico* tec1 = *(Tecnico**)t1;
    Tecnico* tec2 = *(Tecnico**)t2;

    if (tec1->tempoTrabalhado > tec2->tempoTrabalhado)
    {
        return -1;
    }
    else if (tec1->tempoTrabalhado < tec2->tempoTrabalhado)
    {
        return 1;
    }
    else 
    {
        return strcmp(getNomeTecnico(tec1), getNomeTecnico(tec2));
    }
}