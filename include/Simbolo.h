#ifndef SIMBOLO_H
#define SIMBOLO_H

#include <iostream>

class Simbolo{
    friend class Scanner;
    friend class Regla;
    friend std::ostream & operator<<(std::ostream &salida,const Simbolo &C) {
        salida<<"|"<<C.valor<<" "<<C.tipo<<"|";
        return salida;
    }
public:
    Simbolo(char _tipo='N', int _valor=0): tipo(_tipo), valor(_valor){}
    Simbolo(int _valor): tipo('T'), valor(_valor){}
    Simbolo(const Simbolo &A){*this=A;}

    Simbolo& operator=(const Simbolo &R)
    {
        tipo = R.tipo;
        valor = R.valor;
        return *this;
    }

    bool operator == (const Simbolo &S){ return ((S.tipo == tipo) && (S.valor == valor) ); }
    bool operator != (const Simbolo &S){ return ((S.tipo != tipo) || (S.valor != valor) ); }

    bool esTerminal() const { return tipo=='T';}
    bool esNoTerminal() const { return tipo=='N';}
    void Imprimir() const {std::cout<<"|"<<valor<<" "<<tipo<<"|";}
    std::string int2string()
    {
    std::string simb;
    if(tipo=='N'){
        switch(valor){
            case 1: simb = "INICIO"; break;
            case 2: simb = "G"; break;
            case 3: simb = "A"; break;
            case 4: simb = "AP"; break;
            case 5: simb = "INCLUDE"; break;
            case 6: simb = "X"; break;
            case 7: simb = "DFUNCION"; break;
            case 8: simb = "ARGUMENTO"; break;
            case 9: simb = "F"; break;
            case 10: simb = "B"; break;
            case 11: simb = "DEFINE"; break;
            case 12: simb = "STRUCT"; break;
            case 13: simb = "ESTRUCTURA"; break;
            case 14: simb = "DECVAR"; break;
            case 15: simb = "I"; break;
            case 16: simb = "H"; break;
            case 17: simb = "CUERPO"; break;
            case 18: simb = "LISTASENTENCIAS"; break;
            case 19: simb = "LISTASENTENCIASP"; break;
            case 20: simb = "SENTENCIA"; break;
            case 21: simb = "WHILE"; break;
            case 22: simb = "R"; break;
            case 23: simb = "IFELSE"; break;
            case 24: simb = "S"; break;
            case 25: simb = "IF"; break;
            case 26: simb = "T"; break;
            case 27: simb = "CONDICION"; break;
            case 28: simb = "CONDICIONP"; break;
            case 29: simb = "M"; break;
            case 30: simb = "MP"; break;
            case 31: simb = "N"; break;
            case 32: simb = "O"; break;
            case 33: simb = "OPLOG"; break;
            case 34: simb = "V"; break;
            case 35: simb = "K"; break;
            case 36: simb = "KP"; break;
            case 37: simb = "P"; break;
            case 38: simb = "PP"; break;
            case 39: simb = "OP"; break;
            case 40: simb = "OP1"; break;
            case 41: simb = "Q"; break;
            case 42: simb = "CFUNCION"; break;
            case 43: simb = "PARAMETRO"; break;
            case 44: simb = "ASIGNACION"; break;
            case 45: simb = "U"; break;
            case 46: simb = "TIPODATO"; break;
            case 47: simb = "C"; break;
            case 48: simb = "D"; break;
            case 49: simb = "MODIF1"; break;
            case 50: simb = "MODIF2"; break;
            case 51: simb = "E"; break;
            case 52: simb = "J"; break;
            default: simb="NO DEFINIDO";break;
        }
    }
    else {
        switch(valor){
            case 1: simb = "T_ident"; break;
            case 2: simb = "T_Num"; break;
            case 3: simb = "T_Cadena"; break;
            case 4: simb = "T_Caracter"; break;
            case 5: simb = "T_Include"; break;
            case 6: simb = "T_Main"; break;
            case 7: simb = "T_Int"; break;
            case 8: simb = "T_Float"; break;
            case 9: simb = "T_Double"; break;
            case 10: simb = "T_Char"; break;
            case 11: simb = "T_AbrePar"; break;
            case 12: simb = "T_CierraPar"; break;
            case 13: simb = "T_AbreCor"; break;
            case 14: simb = "T_CierraCor"; break;
            case 15: simb = "T_AbreLlave"; break;
            case 16: simb = "T_CierraLLave"; break;
            case 17: simb = "T_Printf"; break;
            case 18: simb = "T_return"; break;
            case 19: simb = "T_PunComa"; break;
            case 20: simb = "T_Igual"; break;
            case 21: simb = "T_Mas"; break;
            case 22: simb = "T_Menos"; break;
            case 23: simb = "T_Entre"; break;
            case 24: simb = "T_Ast"; break;
            case 25: simb = "T_Coma"; break;
            case 26: simb = "T_Mayor"; break;
            case 27: simb = "T_Menor"; break;
            case 28: simb = "T_Not"; break;
            case 29: simb = "T_Punto"; break;
            case 30: simb = "T_BarraVer"; break;
            case 31: simb = "T_Ampersand"; break;
            case 32: simb = "T_Gorro"; break;
            case 33: simb = "T_Porciento"; break;
            case 34: simb = "T_Libreria"; break;
            case 35: simb = "T_Break"; break;
            case 36: simb = "T_Case"; break;
            case 37: simb = "T_Const"; break;
            case 38: simb = "T_Do"; break;
            case 39: simb = "T_Else"; break;
            case 40: simb = "T_Enum"; break;
            case 41: simb = "T_For"; break;
            case 42: simb = "T_If"; break;
            case 43: simb = "T_Long"; break;
            case 44: simb = "T_Short"; break;
            case 45: simb = "T_Signed"; break;
            case 46: simb = "T_Static"; break;
            case 47: simb = "T_Struct"; break;
            case 48: simb = "T_Switch"; break;
            case 49: simb = "T_Unsigned"; break;
            case 50: simb = "T_Void"; break;
            case 51: simb = "T_While"; break;
            case 52: simb = "T_Bool"; break;
            case 53: simb = "T_True"; break;
            case 54: simb = "T_False"; break;
            case 55: simb = "T_Define"; break;
            case 56: simb = "T_Fin"; break;
            case -1: simb = "e"; break;
            default: simb = "NO DEFINIDO"; break;
        }
    }
    return simb;

    }


private:
    char tipo;
    int valor;
};

#endif // SIMBOLO_H
