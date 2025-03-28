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

#define MAX_TAMANHO_ACAO 20
#define REF_DIA 18
#define REF_MES 2
#define REF_ANO 2025

int main(int argc, char const *argv[])
{
    //Declaração de variáveis
    char comando = '\0';
    Vector *vTec = VectorConstruct();
    Vector *vUser = VectorConstruct();
    Vector *copia = VectorConstruct();
    Fila *f = criaFila();
    Tecnico *t = NULL;
    Usuario *u = NULL;
    Outros *o = NULL;
    Manutencao *m = NULL;
    Software *s = NULL;
    char *setor;
    char cpf[MAX_TAM_CPF];
    char tipo[15];
    char acao[MAX_TAMANHO_ACAO];
    int repetido = 0;
    int cadastro = 0;
    Data *dtRef = CriaData(REF_DIA, REF_MES, REF_ANO);


    //Inicio do programa
    while (1)
    {
        repetido = 0;
        cadastro = 0;

        scanf("%c", &comando);
        scanf("[^\n]");
        scanf("%*c");

        //'F' finaliza o programa
        if (comando == 'F')
            break;

        switch (comando)
        {
        //Cadastro de um técnico
        case 'T':
            t = leTecnico();
            for (int i = 0; i < VectorSize(vTec); i++)
            {
                Tecnico *aux = VectorGet(vTec, i);
                if (ehMesmoTecnico(t, aux))
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

        //Cadastro de um usuário
        case 'U':
            u = leUsuario();
            for (int i = 0; i < VectorSize(vUser); i++)
            {
                Usuario *aux = VectorGet(vUser, i);
                if (ehMesmoUsuario(u, aux))
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
        //Cadastro de um ticket
        case 'A':
            scanf("%[^\n]", cpf);
            scanf("%*c");

            scanf("%[^\n]", tipo);
            scanf("%*c");

            // Checando se o cpf foi cadastrado
            for (int i = 0; i < VectorSize(vUser); i++)
            {
                if (comparaCPFUser(VectorGet(vUser, i), cpf))
                {
                    Usuario *aux = VectorGet(vUser, i);
                    aumentaTicketsUser(aux);
                    cadastro = 1;
                    break;
                }
            }

            //Atribuindo os tickets na fila (caso o cpf esteja cadastrado) dependendo do tipo do ticket
            //Se o ticket não foi cadastrado, ele ja é desalocado.

            if (!strcmp(tipo, "OUTROS"))
            {
                o = lerOutros();
                // ticket = criaTicket(cpf, o, getTempoEstimadoOutros, getTipoOutros, notificaOutros, desalocaOutros);
                if (cadastro)
                {
                    insereTicketFila(f, cpf, o, getTempoEstimadoOutros, getTipoOutros, notificaOutros, desalocaOutros);
                }
                else 
                {
                    desalocaOutros(o);
                }
            }
            else if (!strcmp(tipo, "MANUTENCAO"))
            {
                m = lerManutencao();

                if (cadastro)
                {
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
                else 
                {
                    desalocaManutencao(m);
                }
            }
            else if (!strcmp(tipo, "SOFTWARE"))
            {
                s = lerSoftware();

                if (cadastro)
                {
                    setTempoEstimadoSoftware(s);
                    insereTicketFila(f, cpf, s, getTempoEstimadoSoftware, getTipoSoftware, notificaSoftware, desalocaSoftware);
                }
                else 
                {
                    desalocaSoftware(s);
                }
            }

            break;

        //'Ação a ser executada'
        case 'E':
            scanf("%[^\n]", acao);
            scanf("%*c");

            //Lista de usuários
            if (!strcmp(acao, "USUARIOS"))
            {
                printf("----- BANCO DE USUARIOS -----\n");
                VectorPrint(vUser, imprimeUsuario);
                printf("----------------------------\n");
                printf("\n");
            }

            //Lista de técnicos
            else if (!strcmp(acao, "TECNICOS"))
            {
                printf("----- BANCO DE TECNICOS -----\n");
                VectorPrint(vTec, imprimeTecnico);
                printf("----------------------------\n");
                printf("\n");
            }

            //Distribuindo os tickets
            else if (!strcmp(acao, "DISTRIBUI"))
            {

                int indice = 0;
                for (int i = 0; i < getQtdTicketsNaFila(f); i++)
                {
                    // Vendo se o ticket está em aberto
                    if (getStatusTicket(getTicketNaFila(f, i)) == 'A')
                    {
                        Ticket* ticket = getTicketNaFila(f, i);
                        char tipo = getTipoTicket(ticket);
                        //Atribuindo o ticket a um técnico (a depender do tipo dele)
                        if (tipo == 'S')
                        {
                            for (int j = 0; j < VectorSize(vTec); j++)
                            {
                                Tecnico *aux = VectorGet(vTec, indice);
                                if (getAreaAtuacao(aux) == 'T')
                                {
                                    if (getDisponibilidade(aux) >= getTempoEstimadoTicket(ticket))
                                    {
                                        atribuiTicket(aux, ticket);
                                        //Reseta o indice caso ele chegue ao tamanho do vetor
                                        indice = (indice+1) % VectorSize(vTec);
                                        break;
                                    }
                                }
                                indice = (indice+1) % VectorSize(vTec);
                            }
                        }
                        else if (tipo == 'O' || 'M')
                        {
                            for (int j = 0; j < VectorSize(vTec); j++)
                            {
                                Tecnico *aux = VectorGet(vTec, indice);

                                if (getAreaAtuacao(aux) == 'G')
                                {
                                    if (getDisponibilidade(aux) >= getTempoEstimadoTicket(ticket))
                                    {
                                        atribuiTicket(aux, ticket);
                                        //Reseta o indice caso ele chegue ao tamanho do vetor
                                        indice = (indice+1) % VectorSize(vTec);
                                        break;
                                    }
                                }
                                indice = (indice+1) % VectorSize(vTec);
                            }
                        }
                    }
                }
            }

            else if (!strcmp(acao, "NOTIFICA"))
            {
                printf("----- FILA DE TICKETS -----\n");
                notificaFila(f);
                printf("---------------------------\n\n");
            }

            else if (!strcmp(acao, "RELATORIO"))
            {
                printf("----- RELATORIO GERAL -----\n");

                // Pegando a soma das idades dos usuarios
                int somaIdadeUser = 0;
                for (int i = 0; i < VectorSize(vUser); i++)
                {
                    somaIdadeUser += getIdadeUser(VectorGet(vUser, i), dtRef);
                }
                int mediaIdadeUser = somaIdadeUser / VectorSize(vUser);

                // Pegando a soma das idades dos tecnicos
                int somaIdadeTec = 0;
                for (int i = 0; i < VectorSize(vTec); i++)
                {
                    somaIdadeTec += getIdadeTec(VectorGet(vTec, i), dtRef);
                }
                int mediaIdadeTec = somaIdadeTec / VectorSize(vTec);

                // Pegando a quantidade de trabalhos dos tecnicos
                int qtd = 0;
                for (int i = 0; i < VectorSize(vTec); i++)
                {
                    qtd += getTempoTrabalhado(VectorGet(vTec, i));
                }
                int mediaTrabalhoTec = qtd / VectorSize(vTec);

                printf("- Qtd tickets: %d\n- Qtd tickets (A): %d\n- Qtd tickets (F): %d\n- Qtd usuarios: %d\n- Md idade usuarios: %d\n- Qtd tecnicos: %d\n- Md idade tecnicos: %d\n- Md trabalho tecnicos: %d\n",
                       getQtdTicketsNaFila(f), getQtdTicketsPorStatusNaFila(f, 'A'), getQtdTicketsPorStatusNaFila(f, 'F'),
                       VectorSize(vUser), mediaIdadeUser, VectorSize(vTec), mediaIdadeTec, mediaTrabalhoTec);

                printf("---------------------------\n");
                printf("\n");
            }

            //Ranking de técnicos
            else if (!strcmp(acao, "RANKING TECNICOS"))
            {
                printf("----- RANKING DE TECNICOS -----\n");
                VectorCopy(vTec, copia);
                VectorSort(copia, comparaTecnicos);
                VectorPrint(copia, imprimeTecnico);
                printf("-------------------------------\n\n");
            }

            //Ranking de usuários
            else if (!strcmp(acao, "RANKING USUARIOS"))
            {
                printf("----- RANKING DE USUARIOS -----\n");
                VectorCopy(vUser, copia);
                VectorSort(copia, comparaUsuarios);
                VectorPrint(copia, imprimeUsuario);
                printf("-------------------------------\n\n");
            }

            break;

        default:
            printf("Comando inválido! (%c)\n", comando);
            break;
        }
    }

    //Desalocando todos os vetores e variáveis que foram alocados dinamicamente
    VectorDestroy(vTec, desalocaTecnico);
    VectorDestroy(vUser, desalocaUsuario);
    VectorDestroyCopy(copia);
    desalocaFila(f);
    LiberaData(dtRef);

    return 0;
}