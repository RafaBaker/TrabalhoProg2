
#ifndef _DATA_STRUCTURES_VECTOR_H_
#define _DATA_STRUCTURES_VECTOR_H_

typedef void *DataType; // void pointer
typedef struct Vector Vector;

/**
 * @brief Cria um vetor vazio
 * 
 * @return A estrutura Vector inicializada. Caso não seja possível alocar memória, o programa é encerrado.
*/
Vector *VectorConstruct();

/**
 * @brief Adiciona um elemento no final do vetor
 * 
 * @param v Ponteiro para o vetor
 * @param val Valor a ser adicionado
*/
void VectorPushBack(Vector *v, DataType val);

/**
 * @brief Remove o primeiro elemento do vetor e organiza os demais elementos, ou seja, 
 * o segundo elemento passa a ser o primeiro, o terceiro passa a ser o segundo, e assim por diante.
 * 
 * @param v Ponteiro para o vetor
 * @return DataType Elemento removido
*/
DataType VectorPopFront(Vector *v);

/**
 * @brief Retorna o i-ésimo elemento do vetor
 * 
 * @param v Ponteiro para o vetor
 * @param i Índice do elemento
 * @return DataType Elemento do vetor
*/
DataType VectorGet(Vector *v, int i);

/**
 * @brief Retorna o tamanho do vetor
 * 
 * @param v Ponteiro para o vetor
 * @return int Tamanho do vetor
*/
int VectorSize(Vector *v);

/**
 * @brief Libera a memória alocada para o vetor
 * 
 * @param v Ponteiro para o vetor
 * @param destroy Função que libera a memória alocada para cada elemento do vetor
*/
void VectorDestroy(Vector *v, void (*destroy)(DataType));

/**
 * @brief Imprime todos os elementos do vetor
 * 
 * @param v Ponteiro para o vetor
 * @param imprime Função que imprime os elementos do vetor
*/
void VectorPrint(Vector *v, void (*imprime)(DataType));

/**
 * @brief Ordena todos os elementos do vetor
 * 
 * @param v Ponteiro para o vetor
 * @param compare Compara a função que imrpime os elementos do vetor
*/
void VectorSort(Vector *v, int (*compare)(const void*, const void*));

/**
 * @brief Copia os elementos de src para dest
 * 
 * @param src Ponteiro para o vetor a ser copiado
 * @param dest Ponteiro para o vetor que será destinado as informações
*/
void VectorCopy(Vector *src,  Vector* dest);

/**
 * @brief Desaloca um vetor de copia
 * 
 * @param v Ponteiro para o vetor de copia
*/
void VectorDestroyCopy(Vector *v);

#endif
