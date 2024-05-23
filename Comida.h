
#ifndef COMIDA_H
#define COMIDA_H

#include <iostream>
#include <vector>
#include <string>
#include <sstream>
using namespace std;

class Comida {

  protected:
    string nombre;
    string tipo;
    float precio;
  public:
    Comida() : nombre(""), tipo(""), precio(0.0) {}             
    Comida(string nom, string tip, float num):
    nombre(nom), tipo(tip), precio(num) {};
    virtual ~Comida() {} 
    string get_nombre() {
      return nombre;
    }
    string get_tipo() {
      return tipo;
    }
    int get_precio() {
      return precio;
    }
   virtual float calcularCalorias() const = 0; 
    virtual string toString() const = 0; 
};
#endif
