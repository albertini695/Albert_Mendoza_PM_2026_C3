#include <stdio.h>
#include <stdlib.h>

#define SALIR 0
#define SUMAR 1
#define RESTAR 2
#define MULTIPLICAR 3
#define DIVIDIR 4
// Nuevas opciones para el menú
#define RAIZ 5
#define CUADRADO 6

#define ERR_OK 0
#define ERR_SYNTAX 1
#define ERR_DivByZero 555
// Nuevo código de error para raíces negativas
#define ERR_NegRoot 556

// Declaracion de funciones
int suma(double s1, double s2, double *r);
int divicion(double dividendo, double divisor, double *r);
int multiplicacion(double multiplicando, double multiplicador, double *r);
int resta(double minuendo, double sustraendo, double *r);
// Declaración de las nuevas funciones
int raiz_cuadrada(double radicando, double *r);
int cuadrado(double base, double *r);

int main()
{
    int menu = -1;
    double n1 = 0.0;
    double n2 = 0.0;
    double result = 0.0; // variable global
    int err = ERR_OK;

    printf("\nCALCULADORA V1.1");

    do
    {
        printf("\n\n0-SALIR\n1-SUMAR\n2-RESTAR\n3-MULTIPLICAR\n4-DIVIDIR\n5-RAIZ CUADRADA\n6-ELEVACION AL CUADRADO\nElija una opcion: ");
        scanf("%i",&menu);

        if(menu == SUMAR)
        {
            printf("\nSUMA");
            printf("\nEscriba el primer numero:");
            scanf("%lf",&n1);
            printf("\nEscriba el segundo numero:");
            scanf("%lf",&n2);
            err = suma(n1,n2,&result);
            if(err == ERR_OK)
            {
                printf("\nResultado de la SUMA de %lf + %lf = %lf",n1,n2,result);
            }
        }

        if(menu == RESTAR)
        {
            printf("\nRESTA");
            printf("\nEscriba el minuendo:");
            scanf("%lf",&n1);
            printf("\nEscriba el sustraendo:");
            scanf("%lf",&n2);
            err = resta(n1,n2,&result);
            if(err == ERR_OK)
            {
                printf("\nResultado de la RESTA de %lf - %lf = %lf",n1,n2,result);
            }
        }

        if(menu == MULTIPLICAR)
        {
            printf("\nMULTIPLICACION");
            printf("\nEscriba el multiplicando:");
            scanf("%lf",&n1);
            printf("\nEscriba el multiplicador:");
            scanf("%lf",&n2);
            err = multiplicacion(n1,n2,&result);
            if(err == ERR_OK)
            {
                printf("\nResultado de la MULTIPLICACION de %lf * %lf = %lf",n1,n2,result);
            }
        }

        if(menu == DIVIDIR)
        {
            printf("\nDIVIDIR");
            printf("\nEscriba el Dividendo:");
            scanf("%lf",&n1);
            printf("\nEscriba el Divisor:");
            scanf("%lf",&n2);
            err = divicion(n1,n2,&result);
            if(err == ERR_OK)
            {
               printf("\nDivision %lf / %lf = %lf",n1,n2,result);
            }
            else if(err == ERR_DivByZero)
            {
               printf("\nError: No se puede dividir entre cero");
            }
        }

        if(menu == RAIZ)
        {
            printf("\nRAIZ CUADRADA (Algoritmo)");
            printf("\nEscriba el numero:");
            scanf("%lf",&n1);
            err = raiz_cuadrada(n1,&result);
            if(err == ERR_OK)
            {
               printf("\nLa raiz cuadrada de %lf es %lf",n1,result);
            }
            else if(err == ERR_NegRoot)
            {
               printf("\nError: No existen raices cuadradas de numeros negativos reales");
            }
        }

        if(menu == CUADRADO)
        {
            printf("\nELEVACION AL CUADRADO");
            printf("\nEscriba la base:");
            scanf("%lf",&n1);
            err = cuadrado(n1,&result);
            if(err == ERR_OK)
            {
               printf("\n%lf elevado al cuadrado es %lf",n1,result);
            }
        }

    }
    while(menu != SALIR);

    return 0;
}

int suma(double s1, double s2, double *r)
{
    *r = s1 + s2;
    return ERR_OK;
}

int resta(double minuendo, double sustraendo, double *r)
{
    *r = minuendo - sustraendo;
    return ERR_OK;
}

int multiplicacion(double multiplicando, double multiplicador, double *r)
{
    *r = multiplicando * multiplicador;
    return ERR_OK;
}

int divicion(double dividendo, double divisor, double *r)
{
    if(divisor != 0)
    {
        *r = dividendo / divisor;
        return ERR_OK;
    }
    else
    {
        return ERR_DivByZero;
    }
}

int raiz_cuadrada(double radicando, double *r)
{
    if(radicando < 0)
    {
        return ERR_NegRoot;
    }
    if(radicando == 0)
    {
        *r = 0;
        return ERR_OK;
    }

    double x = radicando;
    double y = 1.0;
    double precision = 0.000001;

    while (x - y > precision)
    {
        x = (x + y) / 2;
        y = radicando / x;
    }

    *r = x;
    return ERR_OK;
}

int cuadrado(double base, double *r)
{
    *r = base * base;
    return ERR_OK;
}
