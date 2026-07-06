#include "../include/Fecha.h"

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

bool EsMismaFecha(Fecha f1, Fecha f2)
{
    bool igual = false;

    if (f1.dia == f2.dia && f1.mes == f2.mes && f1.anio == f2.anio)
        igual = true;

    return igual;
}

bool EsFechaMayor(Fecha f1, Fecha f2)
{
    return (f1.anio > f2.anio) ||
           (f1.anio == f2.anio && f1.mes > f2.mes) ||
           (f1.anio == f2.anio && f1.mes == f2.mes && f1.dia > f2.dia);
}

bool EsFechaValida(Fecha f)
{
    bool fechaValida = false;
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

        fechaValida = (f.dia >= 1 && f.dia <= diasMes);
    }

    return fechaValida;
}