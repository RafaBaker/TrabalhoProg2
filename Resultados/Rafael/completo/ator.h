#include "data.h"

#ifndef _ATOR_H
#define _ATOR_H

#define MAX_TAM_NOME_ATOR 100
#define MAX_TAM_CPF_ATOR 16
#define MAX_TAM_DATA_ATOR 15
#define MAX_TAM_TELEFONE_ATOR 15
#define MAX_TAM_GENERO_ATOR 10

typedef struct Ator Ator;

/**
 *  @brief Aloca um ator na memória e inicializa os parâmetros necessários
 * 
 *  @param nome Nome do ator
 *  @param cpf CPF do ator
 *  @param dtNasc Data de nascimento do ator
 *  @param telefone Telefone do ator
 *  @param genero Genero do ator
 *  @return Uma estrutura de ator inicializada
*/
Ator* criaAtor(char* nome, char* cpf, Data* dtNasc, char* telefone, char* genero);

/**
 *  @brief Le as informações de um ator da entrada padrão e cria um ator
 *  
 * @return Uma estrutura de ator

*/
Ator* leAtor();

/**
 *  @brief Desaloca um ator da memória
 * 
 *  @param a O ator a ser desalocado
*/
void desalocaAtor(Ator* a);

/**
 *  @brief Imprime o ator no terminal
 * 
 *  @param a O ator a ser impresso
*/
void imprimeAtor(Ator* a);

/**
 *  @brief Retorna o CPF de um ator
 *  @param a O ator em questão
 * 
 *  @return O CPF do ator
*/
char* getCPFAtor(Ator* a);


/**
 *  @brief Retorna o nome de um ator
 * 
 *  @param a O ator em questão
 *  @return O nome do ator
*/
char* getNomeAtor(Ator* a);

/**
 *  @brief Compara um cpf com o cpf de um ator 
 * 
 *  @param a O ator em questão
 *  @param cpf O CPF a ser comparado
 *  @return Retorna 1 se o CPF do ator for igual ao cpf comparado. Caso o contrário retorna 0
*/
int comparaCPFAtor(Ator* a, char* cpf);

/**
 *  @brief Compara um ator com o outro
 *  @param a1 Um ator
 *  @param a2 Outro ator
 * 
 *  @return Retorna 1 se forem iguais e 0 caso o contrário
*/
int ehMesmoAtor(Ator* a1, Ator* a2);


/**
 *  @brief Calcula a idade de um ator
 * 
 *  @param a O ator a ser calculado a idade
 *  @param dtRef Uma data de referência
 *  @return A idade do ator
*/
int getIdadeAtor(Ator* a, Data* dtRef);

#endif