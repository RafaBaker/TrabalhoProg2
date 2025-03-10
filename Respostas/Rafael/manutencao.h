#ifndef _MANUTENCAO_H
#define _MANUTENCAO_H

#define MAX_TAM_NOME_MANUTENCAO 100
#define MAX_TAM_LOCAL_MANUTENCAO 100
#define MAX_TAM_ESTADO_MANUTENCAO 10

#define FATOR_SETOR_MARKETING 1
#define FATOR_SETOR_VENDAS 1
#define FATOR_SETOR_PD 1
#define FATOR_SETOR_RH 2
#define FATOR_SETOR_FINANCEIRO 3

#define TEMPO_RUIM 3
#define TEMPO_REGULAR 2
#define TEMPO_BOM 1

/**
 * Estrutura de um Ticket Manutencao contendo os parametros especificos de um ticket do tipo MANUTENCAO
 */
typedef struct Manutencao Manutencao;

/**
 * @brief Aloca uma estrutura Manutencao na memória e inicializa os parâmetro necessários
 * @param nome nome do ticket
 * @param estado estado de conservação
 * @param local local do ticket
 * @return  Uma estrutura Manutencao inicializada.
 */
Manutencao *criaManutencao(char *nome, char* estado, char *local);

/**
 * @brief Lê da entrada padrão um  ticket do TIPO manutencao
 * @return  Um chamado do Tipo Manutencao
 */
Manutencao *lerManutencao();

/**
 * @brief  Calcula o tempo estimado para resolver um ticket do tipo Manutencao.
 * Tempo estimado depende da categoria e impacto
 * @param s  Ticket do tipo Manutencao
 */
void setTempoEstimadoManutencao(Manutencao *m, char* setor);

/**
 * @brief  Retorna o tempo estimado para resolver um ticket do tipo Manutencao.
 * @param dado  Ticket do tipo Manutencao
 * @return  Tempo estimado para resolver um ticket do tipo Manutencao
 */
int getTempoEstimadoManutencao(void *dado);

/**
 * @brief  Retorna o tipo do ticket
 * @return  'M' para Manutencao
 */
char getTipoManutencao();

/**
 * @brief  Desaloca um ticket do tipo Manutencao da memória
 * @param m  Ticket do tipo Manutencao
 */
void desalocaManutencao(void *m);

/**
 * @brief  Imprime um ticket do tipo Manutencao
 * @param dado  Ticket do tipo Manutencao
 */
void notificaManutencao(void *dado);

#endif