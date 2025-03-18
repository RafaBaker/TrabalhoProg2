#include "ator.h"
#include "ticket.h"

#ifndef _TECNICO_H
#define _TECNICO_H

#define MAX_TAM_AREA 10

typedef struct Tecnico Tecnico;

/// @brief Aloca um tecnico na memória e inicializa os parâmetros necessários
/// @param ator O ator que será o técnico
/// @param area A área do técnico
/// @param disponibilidade A disponibilidade desse técnico
/// @param salario O salário do técnico
/// @return Uma estrutura de técnico inicializada
Tecnico* criaTecnico(Ator* ator, char* area, int disponibilidade, float salario);


/// @brief Le as informações do técnico na entrada padrão
/// @return O técnico lido
Tecnico* leTecnico();


/// @brief Imprime o técnico no terminal
/// @param t O técnico a ser impresso
void imprimeTecnico(void* t);


/// @brief Desaloca um técnico da memória
/// @param t O técnico a ser desalocado
void desalocaTecnico(void* t);


/// @brief Compara dois técnicos
/// @param t1 Um técnico
/// @param t2 Outro técnico
/// @return Retorna 1 se os dois técnicos forem iguais, e 0 caso contrário
int ehMesmoTecnico(Tecnico* t1, Tecnico* t2);


/// @brief Retorna o tempo trabalhado de um técnico
/// @param t Um técnico
/// @return O tempo trabalhado do técnico
int getTempoTrabalhado(Tecnico* t);


/// @brief Retorna o tempo disponivel do técnico
/// @param t Um técnico
/// @return O tempo trabalhado do técnico
int getDisponibilidade(Tecnico* t);


/// @brief Retorna a idade do técnico
/// @param t Um técnico
/// @param dtRef Uma data de referência
/// @return A idade do técnico
int getIdadeTec(Tecnico* t, Data* dtRef);


/// @brief Retorna a área de atuação de um técnico
/// @param t Um técnico
/// @return A área de atuação
char getAreaAtuacao(Tecnico* t);


/// @brief Retorna o nome de um técnico
/// @param t Um técnico
/// @return O nome do técnico em questão
char* getNomeTecnico(Tecnico* t);


/// @brief Retorna o número de bytes de um técnico
/// @return O número de bytes de uma struct técnico
int numBytesTecnico();


/// @brief Compara dois técnicos para função de qsort
/// @param t1 O primeiro técnico
/// @param t2 O segundo técnico
/// @return Retorna 1 se o t1 tiver mais horas, -1 se o t2. Caso sejam iguais, retorna a ordem alfabética
int comparaTecnicos(const void* t1, const void* t2);


/// @brief Atribui um ticket ao técnico
/// @param t O técnico
/// @param ticket O ticket a ser atribuido
void atribuiTicket(Tecnico* t, Ticket* ticket);

#endif