#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#include "fila.h"
#include "ticket.h"
#include "outros.h"
#include "tecnico.h"
#include "usuario.h"
#include "vector.h"

int main(int argc, char const *argv[])
{
    char comando = '\0';
    Vector *vTec = VectorConstruct();
    Vector *vUser = VectorConstruct();

    char cpf[MAX_TAM_CPF];
    char tipo[15];

    int repetido = 0;

    scanf("%c", &comando);
    scanf("[^\n]");
    scanf("%*c");

    while (1)
    {
        repetido = 0;

        if (comando == 'F')
            break;

        switch (comando)
        {
        case 'T':
            Tecnico *t = leTecnico();
            for (int i = 0; i < VectorSize(vTec); i++)
            {
                Tecnico* aux = VectorGet(vTec, i);
                if (comparaTecnicos(t, aux))
                {
                    desalocaTecnico(t);
                    repetido = 1;
                    break;
                }
            }
            if (!repetido)
            {
                VectorPushBack(vTec, t);
            }
            break;
    
        case 'U':
            Usuario *u = leUsuario();
            for (int i = 0; i < VectorSize(vUser); i++)
            {
                Usuario* aux = VectorGet(vUser, i);
                if (comparaUsuarios(u, aux))
                {
                    desalocaUsuario(u);
                    repetido = 1;
                    break;
                }
            }
            if (!repetido)
            {
                VectorPushBack(vUser, u);
            }

            break;
    
        case 'A':
            scanf("%[^\n]", cpf);
            scanf("%*c");
            
            scanf("[^\n]", tipo);
            scanf("%*c");
            
            
    
        default:
            printf("Comando inválido!");
            break;
        }
    }

    return 0;
}
