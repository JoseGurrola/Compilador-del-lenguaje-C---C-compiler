#include <iostream>
#include "Scanner.h"

using namespace std;

int main ()
{
    try{
        ifstream entrada;
        char nom_archivo[30];
        for(int i=0;i<100;++i) cout<<char(223); cout<<endl;
        cout<<"\t\t\t\t\t  EL PARSER de C\n";
        for(int i=0;i<100;++i) cout<<char(220); cout<<endl;
        cout<<"\n\t\t\t\t   Ingresa el archivo a leer\n\t\t\t\t\t   ";
        cin>>nom_archivo;
        entrada.open(nom_archivo,ifstream::in);
        Scanner S(entrada);
        entrada.close();
        //Scanner S(input);
        S.Leer();
        //cout<<endl; S.ImprimirTokens(); cout<<endl;

        S.Parser();

    }catch(Excepciones &ex) {
        cout << ex.what() << endl;
    }

    return 0;
}
