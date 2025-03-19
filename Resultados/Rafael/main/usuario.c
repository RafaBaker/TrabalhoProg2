#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#include "usuario.h"

struct Usuario
{
    Ator* ator;
    char setor[MAX_TAM_SETOR];
    int qtdTickets;
};

Usuario* criaUsuario(Ator* ator, char* setor)
{
    Usuario* user = (Usuario*)malloc(sizeof(Usuario));

    user->ator = ator;
    strcpy(user->setor, setor);
    user->qtdTickets = 0;

    return user;
}

Usuario* leUsuario()
{
    char setor[MAX_TAM_SETOR];
    Ator* ator = leAtor();

    scanf("%[^\n]", setor);
    scanf("%*c");

    Usuario* user = criaUsuario(ator, setor);
    return user;
}

void imprimeUsuario(void* user)
{
    Usuario* u = (Usuario*)user;

    imprimeAtor(u->ator);
    printf("- Setor: %s\n", u->setor);
    printf("- Tickets solicitados: %d\n", u->qtdTickets);
}

void desalocaUsuario(void* user)
{
    if (user)
    {
        Usuario* u = (Usuario*)user;
        if (u->ator)
        {
            desalocaAtor(u->ator);
        }
        free(user);
    }
    user = NULL;
}

int ehMesmoUsuario(Usuario* u1, Usuario* u2)
{
    return ehMesmoAtor(u1->ator, u2->ator);
}

char* getCPFUser(Usuario* u)
{
    return getCPFAtor(u->ator);
}

int comparaCPFUser(Usuario* u, char* cpf)
{
    return comparaCPFAtor(u->ator, cpf);
}

char* getSetorUser(Usuario* u)
{
    return u->setor;
}

char* getNomeUser(Usuario* u)
{
    return getNomeAtor(u->ator);
}

int getIdadeUser(Usuario* u, Data* dtRef)
{
    return getIdadeAtor(u->ator, dtRef);
}

void aumentaTicketsUser(Usuario* u)
{
    u->qtdTickets++;
}

int comparaUsuarios(const void* u1, const void* u2)
{
    Usuario* user1 = *(Usuario**)u1;
    Usuario* user2 = *(Usuario**)u2;

    if (user1->qtdTickets > user2->qtdTickets)
    {
        return -1;
    }
    else if (user1->qtdTickets < user2->qtdTickets)
    {
        return 1;
    }
    else 
    {
        return strcmp(getNomeUser(user1), getNomeUser(user2));
    }
}