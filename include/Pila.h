#ifndef PILA_H
#define PILA_H

#include <iostream>
#include <cstdlib>
#include <cstring>

template <class Tipo>
class Pila;
//*****************Clase Elemento***********************************************
template <class Tipo>
class Elemento{
	friend class Pila<Tipo>;
public:
    Elemento(Tipo _valor, Elemento<Tipo> *_Sig = NULL): valor(_valor),Sig(_Sig){}

    Tipo valor;
    Elemento<Tipo> *Sig;
};
//*************************Clase Pila con plantillas****************************
template <class Tipo>
class Pila{
    friend std::ostream & operator<<(std::ostream &salida,const Pila &P) {
        Elemento<Tipo> *aux = P.Tope;
        while(aux){
            salida<<aux->valor.int2string()<<" ";
            aux = aux->Sig;
        }
        return salida;
    }
public:
    Pila() : Tope(NULL) {}
    Pila(const Pila<Tipo> &P): Tope(NULL){ *this=P; }
    ~Pila();
    void Push(Tipo);
    Tipo Pop();
    bool PilaVacia(){ return !Tope; }
    Tipo ValorTope(){ return Tope->valor; }
    void Imprimir();
	Pila<Tipo> & operator=( Pila<Tipo> &);
private:
    Elemento<Tipo> *Tope;
    int NumElementos; //Numero de elementos de la pila
};
//-------------------------------------------------------------------------------
// Destructor
template <class Tipo>
Pila<Tipo>::~Pila()
{
	while(!PilaVacia()) Pop();
}
//-------------------------------------------------------------------------------
template <class Tipo>
void Pila<Tipo>::Push(Tipo _valor)
{
    try{
        Tope = new Elemento<Tipo>(_valor,Tope);
        ++NumElementos; //Incrementando en 1 el número de elementos de la pila
    }catch(...){
        std::cout<<"no hay memoria...\n";
    }
}
//-------------------------------------------------------------------------------
template <class Tipo>
Tipo Pila<Tipo>::Pop()
{
    if (PilaVacia()) std::cout<<"la pila esta vacia...\n";;
	Elemento<Tipo> *aux = Tope;
	Tope = Tope->Sig;
	Tipo valorAux = aux->valor;
	delete (aux);
	--NumElementos;//disminuyendo en 1 el número de elementos de la pila
	return valorAux;
}
//------------------------------------------------------------------------------
template <class Tipo>
Pila<Tipo> & Pila<Tipo>::operator=( Pila<Tipo> &A)
{
    Pila<Tipo> PAux;  //Pila auxiliar donde se guardará los datos de la pila
    Tipo a; //Variable auxiliar donde se guarda el valor del dato
    while(!PilaVacia())   PAux.Push(Pop()); //Copiamos en la pila auxiliar la instancia pila

    while(PAux.PilaVacia()==false){ //ciclo para pasar la pila auxiliar a la instancia y a la pila parametro
        a=PAux.Pop();
        A.Push(a);
        Push(a);
    };
    return A;

}
//------------------------------------------------------------------------------
template <class Tipo>
void Pila<Tipo>::Imprimir()
{
	Elemento<Tipo> *aux = Tope;
	while(aux){
		std::cout<<aux->valor.int2string()<<" ";
		aux = aux->Sig;
	}
	std::cout<<std::endl;
}


#endif // PILA_H
