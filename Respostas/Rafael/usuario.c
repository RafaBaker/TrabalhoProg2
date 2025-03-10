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

    Usuario* user = criaUsuario(ator, setor);
    return user;
}

void imprimeUsuario(Usuario* user)
{
    imprimeAtor(user->ator);
    printf("- Setor: %s\n", user->setor);
    printf("- Tickets solicitados: %d\n", user->qtdTickets);
}

void desalocaUsuario(Usuario* user)
{
    if (user)
    {
        if (user->ator)
        {
            desalocaAtor(user->ator);
        }
        free(user);
    }
    user = NULL;
}
