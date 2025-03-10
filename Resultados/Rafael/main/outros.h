#ifndef _OUTROS_H
#define _OUTROS_H

#define MAX_TAM_DESC_OUTROS 500
#define MAX_TAM_LOCAL 100

/**
 * Estrutura de um Ticket Outros contendo os parametros especificos de um ticket do tipo OUTROS
 */
typedef struct Outros Outros;

/**
 * @brief Aloca uma estrutura Outros na memória e inicializa os parâmetro necessários
 * @param descricao Descricao do ticket
 * @param local local do ticket
 * @param dificuldade dificuldade estimada pelo usuário
 * @return  Uma estrutura Outros inicializada.
 */
Outros *criaOutros(char *descricao, char *local, int dificuldade);

/**
 * @brief Lê da entrada padrão um  ticket do TIPO outros
 * @return  Um chamado do Tipo Outros
 */
Outros *lerOutros();


/**
 * @brief  Retorna o tempo estimado para resolver um ticket do tipo Outros.
 * @param dado  Ticket do tipo Outros
 * @return  Tempo estimado para resolver um ticket do tipo Outros
 */
int getTempoEstimadoOutros(void *dado);

/**
 * @brief  Retorna o tipo do ticket
 * @return  'O' para Outros
 */
char getTipoOutros();

/**
 * @brief  Desaloca um ticket do tipo Outros da memória
 * @param o  Ticket do tipo Outros
 */
void desalocaOutros(void *o);

/**
 * @brief  Imprime um ticket do tipo Outros
 * @param dado  Ticket do tipo Outros
 */
void notificaOutros(void *dado);

#endif