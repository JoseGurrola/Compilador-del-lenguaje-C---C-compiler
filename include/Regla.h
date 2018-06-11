#ifndef REGLA_H
#define REGLA_H

#include "Simbolo.h"

class Regla
{
    friend class Scanner;
    friend std::ostream & operator<<(std::ostream &salida, Regla &C) {
        salida<<C.Izq.int2string()<<" -> ";
        //for(int i=0; i<C.numDeriva;++i) salida<<C.Der[i];
        for(int i=0; i<C.numDeriva;++i) salida<<C.Der[i].int2string()<<" ";
        salida<<std::endl;
        return salida;
    }
public:
    Regla(Simbolo _Izq, int _numDeriva, Simbolo* _Der): Izq(_Izq) , numDeriva(_numDeriva)
    {
        Der = new Simbolo[_numDeriva];
        for(int i=0;i<_numDeriva;++i) Der[i] = _Der[i];
    }

    Regla() : Izq(Simbolo(0)), numDeriva(10){ Der = new Simbolo[10];
    }

    Regla(const Regla &C): Der(NULL) { *this=C; }

    ~Regla(){delete[] Der;}

    Regla& operator= (const Regla &R)
    {
        numDeriva = R.numDeriva;
        Izq = R.Izq;
        for(int i=0;i<numDeriva;++i) Der[i] = R.Der[i];
        return *this;
    }

    Simbolo* Deriva()const { return Der; }

    void Imprimir() const
    {
        std::cout<<Izq<<" -> ";
        for(int i=0; i<numDeriva;++i) std::cout<<Der[i];
        std::cout<<std::endl;
    }

private:
    Simbolo Izq;
    Simbolo* Der;
    int numDeriva;
};

#endif // REGLA_H
