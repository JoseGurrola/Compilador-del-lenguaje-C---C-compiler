#ifndef SCANNER_H
#define SCANNER_H

#include <fstream>
#include "Pila.h"
#include "Simbolo.h"
#include "Regla.h"
#include "Excepciones.h"

using std::cout;
using std::string;
using std::ifstream;
using std::endl;

#define TAM_BUFFER 300

class Scanner{
public:
    Scanner(string);
    Scanner(ifstream &);
    ~Scanner(){delete Tokens;}
    void Leer();
    void getTokens(string);
    void ImprimirTokens(){
        for(int i=0;i<100;++i) cout<<char(223); cout<<endl;
        cout<<"\t\t\t\t\t  TOKENS ACEPTADOS\n";
        for(int i=0;i<100;++i) cout<<char(220); cout<<endl;
        for(int i=0; i<numTokens;++i) cout<<Tokens[i].int2string()<<" "<<Tokens[i].valor<<"\n";
        cout<<"\b\b\n";
        }
    void Parser();
private:
    void ImprimeBuffer(){
        cout<<char(186);
        for(unsigned int k=0;k<TAM_BUFFER;k++){
            if(!Buffer[k]) break;
            if(Buffer[k]=='\n') cout<<" "<<"|";
            else cout<<Buffer[k]<<"|";
        }
        cout<<char(186)<<"\n";
    }
    int safeLookAhead(int);
    char Buffer[TAM_BUFFER];
    string input;
    Simbolo* Tokens;//Arreglo de tokens
    int numTokens; //numero de tokens en el arreglo
};

#endif // SCANNER_H
