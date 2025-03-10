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
    Data* dtNasc = CriaData();
    char telefone[MAX_TAM_TELEFONE_ATOR];
    char genero[MAX_TAM_GENERO_ATOR];

    scanf("%[^\n]", nome);
    scanf("%*c");

    scanf("%[^\n]", cpf);
    scanf("%*c");

    LeData(dtNasc);

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