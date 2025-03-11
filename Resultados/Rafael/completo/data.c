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
 * @brief Lê uma data da entrada padrão.
 * @return Um ponteiro para a data lida.
 */
Data* LeData()
{
    int dia, mes, ano;
    scanf("%d/%d/%d", &dia, &mes, &ano);
    scanf("%*c");

    Data* d = CriaData(dia, mes, ano);

    return d;
}

/**
 * @brief Cria uma data com o dia, mês e ano fornecidos. Se a alocação falhar, o programa é encerrado.
 * @param dia O dia da data.
 * @param mes O mês da data.
 * @param ano O ano da data.
 * @return Um ponteiro para a data criada.
 */
Data* CriaData(int dia, int mes, int ano)
{
    Data* d = (Data*)malloc(sizeof(Data));
    
    d->dia = dia;
    d->mes = mes;
    d->ano = ano;

    return d;
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

int CalculaIdadeData(Data* nascimento, Data* diacalc)
{
    int idade = diacalc->ano - nascimento->ano;

    if (diacalc->mes < nascimento->mes)
    {
        idade--;
    }
    else if (diacalc->mes == nascimento->mes)
    {
        if (diacalc->dia < nascimento->dia)
        {
            idade--;
        }
    }

    return idade;
}