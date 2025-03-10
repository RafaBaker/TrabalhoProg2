#include "ator.h"

#ifndef _TECNICO_H
#define _TECNICO_H

#define MAX_TAM_AREA 10

typedef struct Tecnico Tecnico;

Tecnico* criaTecnico(Ator* ator, char* area, int disponibilidade, float salario);

Tecnico* leTecnico();

void imprimeTecnico(Tecnico* t);

void desalocaTecnico(Tecnico* t);

#endif