#include "ator.h"

#ifndef _USUARIO_H
#define _USUARIO_H

#define MAX_TAM_SETOR 15

/**
 * Estrutura de um usuario, contendo um ator (pessoa) e as informações exclusivas do tipo Usuario
 */
typedef struct Usuario Usuario;

/**
*  @brief Aloca um usuario na memória
 * 
*  @param ator O ator que será um usuário
*  @param setor O setor que trabalha o usuário
*  @return Uma estrutura de Usuario inicializada
 */
Usuario* criaUsuario(Ator* ator, char* setor);

/**
*  @brief Le as informações de um usuário da entrada padrão e retorna uma estrutura usuario inicializada
 * 
*  @return Um usuario inicializado
 */
Usuario* leUsuario();

/**
*  @brief Imprime um usuário na tela
 * 
*  @param user O usuário a ser impresso
 */
void imprimeUsuario(void* user);

/**
*  @brief Desaloca um usuário da memória
 * 
*  @param user Usuário a ser desalocado
 */
void desalocaUsuario(void* user);

/**
*  @brief Compara dois usuários e diz se eles são iguais ou não
 * 
*  @param u1 Primeiro usuário
*  @param u2 Segundo usuário
*  @return 1 se são iguais. Caso contrário, retorna 0
 */
int ehMesmoUsuario(Usuario* u1, Usuario* u2);


/**
*  @brief Pega o cpf de um usuário
 * 
*  @param u Usuário em questão
*  @return CPF do usuário u
 */
char* getCPFUser(Usuario* u);

/**
*  @brief Compara um CPF qualquer com um usuário
 * 
*  @param u Usuário a ser comparado
*  @param cpf CPF a ser comparado
*  @return 1 se o CPF do usuário for igual ao CPF passado. Caso contrário, retorna 0
 */
int comparaCPFUser(Usuario* u, char* cpf);

/**
*  @brief Pega o setor em que trabalha um usuário
 * 
*  @param u Usuário em questão
*  @return Uma string contendo o setor do usuário
 */
char* getSetorUser(Usuario* u);

/**
*  @brief Pega o nome de um usuário
 * 
*  @param u Usuário em questão
*  @return Uma string contendo o nome do usuário
 */
char* getNomeUser(Usuario* u);

/**
*  @brief Pega a idade de um usuário
 * 
*  @param u Usuário em questão
*  @param dtRef Data de referência para o cálculo da idade
*  @return A idade do usuário
 */
int getIdadeUser(Usuario* u, Data* dtRef);

/**
*  @brief Incrementa a quantidade de tickets solicitados pelo usuário
 * 
*  @param u Usuário a ser incrementado
 */
void aumentaTicketsUser(Usuario* u);

/**
*  @brief Compara dois usuário para a função qsort
 * 
*  @param u1 Primeiro usuário
*  @param u2 Segundo usuário
*  @return Retorna 1 se a quantidade de tickets de u1 for maior, -1 caso u2 seja maior.
*  Caso ambos empatem, o critério será ordem alfabética (1 para u1, -1 para u2)
 */
int comparaUsuarios(const void* u1, const void* u2);

#endif