#include "data.h"
#include <stdlib.h>
#include <stdio.h>

struct Data
{
    int dia;
    int mes;
    int ano;
};

Data* LeData()
{
    int dia, mes, ano;
    scanf("%d/%d/%d", &dia, &mes, &ano);
    scanf("%*c");

    Data* d = CriaData(dia, mes, ano);

    return d;
}

Data* CriaData(int dia, int mes, int ano)
{
    Data* d = (Data*)malloc(sizeof(Data));
    
    d->dia = dia;
    d->mes = mes;
    d->ano = ano;

    return d;
}

void LiberaData(Data *data)
{
    if (data != NULL)
    {
        free(data);
        data = NULL;
    }
}

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

int VerificaBissexto(Data *data)
{
    return (data->ano % 400 == 0) || ((data->ano % 4 == 0) && (data->ano % 100 != 0));
}

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