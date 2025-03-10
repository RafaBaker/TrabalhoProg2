#include "data.h"
#include <stdlib.h>
#include <stdio.h>

struct Data
{
    int dia;
    int mes;
    int ano;
};

/**
 * @brief Aloca dinamicamente uma estrutura do tipo Data, e a retorna.
 * Os campos dessa estrutura devem ser preenchidos inicialmente com -1.
 *
 * @return Data - Data "Vazia"
 */
Data *CriaData()
{
    Data *data = (Data *)malloc(sizeof(Data));
    if (data != NULL)
    {
        data->ano = -1;
        data->mes = -1;
        data->dia = -1;
        return data;
    }
    else
    {
        printf("Erro ao alocar data\n");
        exit(0);
    }
}

/**
 * @brief Lê o dia, mês e ano e armazena em uma estrutura Data alocada dinamicamente.
 *
 * @param data - Ponteiro para a estrutura onde os dados serão armazenados. Lembre-se: Não pode ter valor NULL.
 */
void LeData(Data *data)
{
    scanf("%d/%d/%d", &data->dia, &data->mes, &data->ano);
    scanf("%*c");
}

/**
 * @brief Libera a memória alocada dinamicamente para uma estrutura do tipo Data, passada como parâmetro
 * @param data - Ponteiro para a estrutura onde os dados estão armazenados.
 */
void LiberaData(Data *data)
{
    if (data != NULL)
    {
        free(data);
        data = NULL;
    }
}

/**
 * @brief Verifica se uma data é válida.
 *
 * @param data Data a ser verificada.
 * @return int 1 se a data é válida, 0 caso contrário.
 */
int VerificaDataValida(Data *data)
{
    if (data->dia > 31)
        return 0;
    if (data->mes > 12)
        return 0;

    int dias = NumeroDiasMes(data);
    if (data->dia > dias)
        return 0;

    return 1;
}

/**
 * @brief Imprime o mês de uma data em formato extenso.
 *
 * @param data Data cujo mês será impresso em formato extenso.
 */
void ImprimeMesExtenso(Data *data)
{
    switch (data->mes)
    {
    case 1:
        printf("Janeiro");
        break;
    case 2:
        printf("Fevereiro");
        break;
    case 3:
        printf("Março");
        break;
    case 4:
        printf("Abril");
        break;
    case 5:
        printf("Maio");
        break;
    case 6:
        printf("Junho");
        break;
    case 7:
        printf("Julho");
        break;
    case 8:
        printf("Agosto");
        break;
    case 9:
        printf("Setembro");
        break;
    case 10:
        printf("Outubro");
        break;
    case 11:
        printf("Novembro");
        break;
    case 12:
        printf("Dezembro");
        break;
    default:
        break;
    }
}

/**
 * @brief Imprime uma data em formato extenso.
 *
 * @param data Data a ser impressa em formato extenso.
 */
void ImprimeDataExtenso(Data *data)
{
    printf("%02d de ", data->dia);
    ImprimeMesExtenso(data);
    printf(" de %4d\n", data->ano);
}

void ImprimeData(Data* data)
{
    printf("%d/%d/%d\n", data->dia, data->mes, data->ano);
}

/**
 * @brief Verifica se um ano é bissexto.
 *
 * @param data Data cujo ano será verificado.
 * @return int 1 se o ano é bissexto, 0 caso contrário.
 */
int VerificaBissexto(Data *data)
{
    return (data->ano % 400 == 0) || ((data->ano % 4 == 0) && (data->ano % 100 != 0));
}

/**
 * @brief Retorna o número de dias de um determinado mês.
 *
 * @param data Data cujo mês terá o número de dias retornado.
 * @return int Número de dias do mês da data.
 */
int NumeroDiasMes(Data *data)
{
    if (data->mes == 2)
    {
        if (VerificaBissexto(data))
        {
            return 29;
        }
        else
        {
            return 28;
        }
    }

    if (data->mes == 1 || data->mes == 3 || data->mes == 5 || data->mes == 7 || data->mes == 8 || data->mes == 10 || data->mes == 12)
        return 31;
    else
        return 30;
}

/**
 * @brief Compara duas datas.
 *
 * @param data1 Primeira data a ser comparada.
 * @param data2 Segunda data a ser comparada.
 * @return int 1 se data1 é maior que data2, -1 se data1 é menor que data2, 0 se as datas são iguais.
 * A data ser maior significa que ela é mais recente.
 */
int ComparaData(Data *data1, Data *data2)
{
    if (data1->ano > data2->ano)
        return 1;
    if (data1->ano < data2->ano)
        return -1;
    if (data1->mes > data2->mes)
        return 1;
    if (data1->mes < data2->mes)
        return -1;
    if (data1->dia > data2->dia)
        return 1;
    if (data1->dia < data2->dia)
        return -1;
    return 0;
}

/**
 * @brief Calcula o número de dias até o início do mês de uma determinada data.
 *
 * @param data Data cujo número de dias até o início do mês será calculado.
 * @return int Número de dias até o início do mês da data.
 */
int CalculaDiasAteMes(Data *data)
{
    int i, dias, total = 0;
    Data d;
    d.ano = data->ano;
    for (i = 1; i < data->mes; i++)
    {
        d.mes = i;
        dias = NumeroDiasMes(&d);
        total += dias;
    }
    return total;
}

/**
 * @brief Calcula a diferença em dias entre duas datas.
 *
 * @param data1 Primeira data a ser comparada.
 * @param data2 Segunda data a ser comparada.
 * @return int Número de dias entre as duas datas.
 */
int CalculaDiferencaDias(Data *data1, Data *data2)
{

    int dias1 = data1->dia, dias2 = data2->dia;
    Data i;

    // dias no ano
    dias1 += CalculaDiasAteMes(data1);
    dias2 += CalculaDiasAteMes(data2);

    int difAnos = 0;
    if (data1->ano > data2->ano)
    {
        //difAnos = data1->ano - data2->ano;
        for (i = *data2; i.ano < data1->ano; i.ano++)
        {
            difAnos += VerificaBissexto(&i) ? 366 : 365;
        }
    }
    else if (data2->ano > data1->ano)
    {
        //difAnos = data2->ano - data1->ano;
        for (i = *data1; i.ano < data2->ano; i.ano++)
        {
            difAnos += VerificaBissexto(&i) ? 366 : 365;
        }
    }
    int dif = dias2 - dias1;
    if (dif >= 0)
    {
        return dif + difAnos;
    }
    else
    {
        dif = dif*(-1);
        return dif+difAnos;
    }

}
