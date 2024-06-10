#ifndef BEBIDA_H
#define BEBIDA_H

#include "Comida.h"
using namespace std;
#include <iostream>
#include <vector>
#include <sstream>

class Bebida : public Comida {
private:
    string sabor;
    float caloriasMLitros;
    int mililitros;
    bool alcohol;
    
public:
    Bebida() : Comida("", "", 0.0), sabor(""), caloriasMLitros(0), mililitros(0), alcohol(false) {} 
    Bebida(const string& nombre, const string& tipo, float precio, const string& sabor, float caloriasMLitros, int mililitros, bool alcohol)
        : Comida(nombre, tipo, precio), sabor(sabor), caloriasMLitros(caloriasMLitros), mililitros(mililitros), alcohol(alcohol){}

    string getSabor() const { 
        return sabor; 
    }
    float calcularCalorias() const override {
        float calorias = caloriasMLitros * mililitros;
        if (alcohol == true){
            calorias += (calorias * .20);
        }
        return calorias;
    }

    string toString() const override {
        stringstream ss;
        ss << "Bebida: " << nombre << ", Descripción: " << tipo << ", Precio: " << precio << ", Sabor: " << sabor << ", Calorías: " << calcularCalorias();
        return ss.str();
    }
};
#endif
