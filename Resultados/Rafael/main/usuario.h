#include "ator.h"

#ifndef _USUARIO_H
#define _USUARIO_H

#define MAX_TAM_SETOR 15

typedef struct Usuario Usuario;

Usuario* criaUsuario(Ator* ator, char* setor);

Usuario* leUsuario();

void imprimeUsuario(Usuario* user);

void desalocaUsuario(Usuario* user);

int comparaUsuarios(Usuario* u1, Usuario* u2);

char* getCPFUser(Usuario* u);

int comparaCPFUser(Ator* u, char* cpf);

#endif