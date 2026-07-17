#include "Fecha.h"
#include <stdio.h>

void CargarFecha(Fecha &f)
{
    printf("\n    Dia [Formato DD]: ");
    scanf("%d", &f.dia);
    printf("    Mes [Formato MM]: ");
    scanf("%d", &f.mes);
    printf("    Anio [Formato AAAA]: ");
    scanf("%d", &f.anio);
}

void DarFecha(Fecha f)
{
    printf("%02d / %02d / %04d", f.dia, f.mes, f.anio);
}

Boolean EsFechaMayor(Fecha f1, Fecha f2)
{
    Boolean esMayor = FALSE;

    if ((f1.anio > f2.anio) ||
        (f1.anio == f2.anio && f1.mes > f2.mes) ||
        (f1.anio == f2.anio && f1.mes == f2.mes && f1.dia > f2.dia))
    {
        esMayor = TRUE;
    }
    return esMayor;
}

Boolean EsFechaValida(Fecha f)
{
    Boolean fechaValida = FALSE;
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
            if (f.anio % 4 == 0)
                diasMes = 29;
            else
                diasMes = 28;
            break;

        default:
            diasMes = 31;
        }

        if (f.dia >= 1 && f.dia <= diasMes)
        {
            fechaValida = TRUE;
        }
    }

    return fechaValida;
}