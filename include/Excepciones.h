#ifndef EXCEPCIONES_H_INCLUDED
#define EXCEPCIONES_H_INCLUDED

#include <iostream>

class Excepciones : public std::exception {
  public:
   Excepciones(int mot) : std::exception(), motivo(mot) {}
   const char* what() const throw() {
   switch(motivo) {
     case 1: return "Token inexistente";
     case 2: return "Error durante la construcción del parser";
   }
   return "Error inesperado";
}
  private:
   int motivo;
};


#endif // EXCEPCIONES_H_INCLUDED
