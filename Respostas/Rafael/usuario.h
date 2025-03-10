#include "ator.h"

#ifndef _USUARIO_H
#define _USUARIO_H

#define MAX_TAM_SETOR 15

typedef struct Usuario Usuario;

Usuario* criaUsuario(Ator* ator, char* setor);

Usuario* leUsuario();

void imprimeUsuario(Usuario* user);

void desalocaUsuario(Usuario* user);

#endif