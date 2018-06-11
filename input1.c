#include <stdio.h>
#include "compiladores.h"
#include <math.h>

#define CALIFICACION 100
#define PROYECTO 1

struct estructura {
    int x;
    int y;
    float w;
    char x;
};




static int VARIABLESTATICA = 10;

struct estructura2{
    int a;
};

float Funcion1(int l);

void main()
{
    int a;
    double b;
    float c;

    c = (a/b);

    while(a==5){
        c = (a+b);
    }

    a = (a+b*c+f);
    (1+b+d+3*j+l)/(d+df*d);

    if(a <= b)  printf("a<=b");
    else printf("b<a");

    printf("hola mundo");

    return;
}

float Funcion1(int l=0)
{
    l*l;
    return (l+12.5f);
}
