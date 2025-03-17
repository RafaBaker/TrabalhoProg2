#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#include "ator.h"

struct Ator
{
    char nome[MAX_TAM_NOME_ATOR];
    char cpf[MAX_TAM_CPF_ATOR];
    Data* dtNasc;
    char telefone[MAX_TAM_TELEFONE_ATOR];
    char genero[MAX_TAM_GENERO_ATOR];
};

Ator* criaAtor(char* nome, char* cpf, Data* dtNasc, char* telefone, char* genero)
{
    Ator* a = malloc(sizeof(Ator));

    strcpy(a->nome, nome);
    strcpy(a->cpf, cpf);
    strcpy(a->telefone, telefone);
    strcpy(a->genero, genero);
    a->dtNasc = dtNasc;

    return a;
}

Ator* leAtor()
{
    char nome[MAX_TAM_NOME_ATOR];
    char cpf[MAX_TAM_CPF_ATOR];
    Data* dtNasc = NULL;
    char telefone[MAX_TAM_TELEFONE_ATOR];
    char genero[MAX_TAM_GENERO_ATOR];

    scanf("%[^\n]", nome);
    scanf("%*c");

    scanf("%[^\n]", cpf);
    scanf("%*c");

    dtNasc = LeData();

    scanf("%[^\n]", telefone);
    scanf("%*c");

    scanf("%[^\n]", genero);
    scanf("%*c");

    Ator* a = criaAtor(nome, cpf, dtNasc, telefone, genero);
    return a;
}

void desalocaAtor(Ator* a)
{
    if (a)
    {
        if (a->dtNasc)
        {
            LiberaData(a->dtNasc);
        }
        a->dtNasc = NULL;
        free(a);
    }
    a = NULL;
}

void imprimeAtor(Ator* a)
{
    printf("- Nome: %s\n", a->nome);
    printf("- CPF: %s\n", a->cpf);
    printf("- Data de Nascimento: ");
    ImprimeData(a->dtNasc);
    printf("- Telefone: %s\n", a->telefone);
    printf("- Genero: %s\n", a->genero);
}

char* getCPFAtor(Ator* a)
{
    return a->cpf;
}

char* getNomeAtor(Ator* a)
{
    return a->nome;
}

int comparaCPFAtor(Ator* a, char* cpf)
{
    return !(strcmp(getCPFAtor(a), cpf));
}

int ehMesmoAtor(Ator* a1, Ator* a2)
{
    return !strcmp(getCPFAtor(a1), getCPFAtor(a2));
}

int getIdadeAtor(Ator* a, Data* dtRef)
{
    return CalculaIdadeData(a->dtNasc, dtRef);
}