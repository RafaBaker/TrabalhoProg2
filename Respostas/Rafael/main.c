#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#include "fila.h"
#include "ticket.h"
#include "outros.h"
#include "software.h"
#include "manutencao.h"
#include "tecnico.h"
#include "usuario.h"
#include "vector.h"

int main(int argc, char const *argv[])
{
    char comando = '\0';
    Vector *vTec = VectorConstruct();
    Vector *vUser = VectorConstruct();
    //Vector *vTickets = VectorConstruct();
    Fila* f = criaFila();
    Tecnico *t = NULL;
    Usuario *u = NULL;
    Outros *o = NULL; 
    Ticket *ticket = NULL;
    char setor[MAX_TAM_CPF];

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
            t = leTecnico();
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
            u = leUsuario();
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
            
            if (!strcmp(tipo, "OUTROS"))
            {
                o = lerOutros();
                //ticket = criaTicket(cpf, o, getTempoEstimadoOutros, getTipoOutros, notificaOutros, desalocaOutros);
                insereTicketFila(f, cpf, o, getTempoEstimadoOutros, getTipoOutros, notificaOutros, desalocaOutros);
            }
            else if (!strcmp(tipo, "MANUTENCAO"))
            {
                m = lerManutencao();

                for (int i = 0; i < VectorSize(vUser); i++)
                {
                    u = VectorGet(vUser, i);
                    if (comparaCPFUser(u, cpf))
                    {
                        setor = getSetorUser(u);
                    }
                }

                setTempoEstimadoManutencao(m, setor);
                insereTicketFila(f, cpf, m, getTempoEstimadoManutencao, getTipoManutencao, notificaManutencao, desalocaManutencao);
            }
            else if (!strcmp(tipo, "SOFTWARE"))
            {
                s = lerSoftware();
                insereTicketFila(f, cpf, s, getTempoEstimadoManutencao, getTipoManutencao, notificaManutencao, desalocaManutencao);
            }
            //fazer apenas um, insereTicketFila
    
        default:
            printf("Comando inválido!");
            break;
        }
    }


    VectorDestroy(vTec, desalocaTecnico);
    VectorDestroy(vUser, desalocaUsuario);
    desalocaFila(f);

    return 0;
}