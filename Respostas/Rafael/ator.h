#include "data.h"

#ifndef _ATOR_H
#define _ATOR_H

#define MAX_TAM_NOME_ATOR 100
#define MAX_TAM_CPF_ATOR 16
#define MAX_TAM_DATA_ATOR 15
#define MAX_TAM_TELEFONE_ATOR 15
#define MAX_TAM_GENERO_ATOR 10

typedef struct Ator Ator;

Ator* criaAtor(char* nome, char* cpf, Data* dtNasc, char* telefone, char* genero);

Ator* leAtor();

void desalocaAtor(Ator* a);

void imprimeAtor(Ator* a);

#endif