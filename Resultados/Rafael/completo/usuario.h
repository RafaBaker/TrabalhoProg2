#include "ator.h"

#ifndef _USUARIO_H
#define _USUARIO_H

#define MAX_TAM_SETOR 15

typedef struct Usuario Usuario;

Usuario* criaUsuario(Ator* ator, char* setor);

Usuario* leUsuario();

void imprimeUsuario(void* user);

void desalocaUsuario(void* user);

int ehMesmoUsuario(Usuario* u1, Usuario* u2);

char* getCPFUser(Usuario* u);

int comparaCPFUser(Usuario* u, char* cpf);

char* getSetorUser(Usuario* u);

char* getNomeUser(Usuario* u);

int getIdadeUser(Usuario* u, Data* dtRef);

void aumentaTicketsUser(Usuario* u);

int comparaUsuarios(const void* u1, const void* u2);

#endif