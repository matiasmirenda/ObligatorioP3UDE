#include "../include/Fecha.h"
#include <stdio.h>

Fecha CrearFecha(int dia, int mes, int anio)
{
    Fecha f;

    f.dia = dia;
    f.mes = mes;
    f.anio = anio;

    return f;
}

void CargarFecha(Fecha &f)
{
    printf("\nDia [Formato DD]: ");
    scanf("%d", &f.dia);

    printf("Mes [Formato MM]: ");
    scanf("%d", &f.mes);

    printf("Anio [Formato AAAA]: ");
    scanf("%d", &f.anio);
}

Boolean EsBisiesto(Fecha f)
{
    Boolean bisiesto = FALSE;

    if ((f.anio % 400 == 0) ||
        (f.anio % 4 == 0 && f.anio % 100 != 0))
    {
        bisiesto = TRUE;
    }

    return bisiesto;
}

void DarFecha(Fecha f)
{
    printf("%02d/%02d/%04d", f.dia, f.mes, f.anio);
}

Boolean EsMismaFecha(Fecha f1, Fecha f2)
{
    Boolean igual = FALSE;

    if (f1.dia == f2.dia &&
        f1.mes == f2.mes &&
        f1.anio == f2.anio)
    {
        igual = TRUE;
    }

    return igual;
}

Boolean EsFechaMayor(Fecha f1, Fecha f2)
{
    Boolean mayor = FALSE;

    if ((f1.anio > f2.anio) ||
        (f1.anio == f2.anio && f1.mes > f2.mes) ||
        (f1.anio == f2.anio && f1.mes == f2.mes && f1.dia > f2.dia))
    {
        mayor = TRUE;
    }

    return mayor;
}

Boolean EsFechaValida(Fecha f)
{
    Boolean valida = FALSE;
    int diasMes;

    if (f.mes >= 1 && f.mes <= 12)
    {
        switch (f.mes)
        {
        case 4:
        case 6:
        case 9:
        case 11:
            diasMes = 30;
            break;

        case 2:
            if (EsBisiesto(f))
                diasMes = 29;
            else
                diasMes = 28;
            break;

        default:
            diasMes = 31;
        }

        if (f.dia >= 1 && f.dia <= diasMes)
            valida = TRUE;
    }

    return valida;
}