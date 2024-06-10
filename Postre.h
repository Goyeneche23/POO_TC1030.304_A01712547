#ifndef POSTRE_H
#define POSTRE_H

#include "Comida.h"
using namespace std;

#include <iostream>
#include <vector>
#include <sstream>

class Postre : public Comida {
private:
    float caloriasGramo;
    float caloriasIngrediente;
    float gramos;
    string sabor;
public:
    Postre() : Comida("", "", 0.0), caloriasGramo(0), caloriasIngrediente(0), gramos(0), sabor("") {} 
    Postre(const string& nombre, const string& tipo, float precio, float caloriasGramo, float caloriasIngrediente, float gramos, string sabor)
        : Comida(nombre, tipo, precio), caloriasGramo(caloriasGramo), caloriasIngrediente(caloriasIngrediente), gramos(gramos), sabor(sabor) {}

    float calcularCalorias() const override {
        float calorias = (caloriasGramo * gramos) + caloriasIngrediente;
        
        return calorias;
    }
    string toString() const override {
        stringstream ss;
        ss << "Postre: " << nombre << ", Descripción: " << tipo << ", Precio: " << precio  << ", Calorías: " << calcularCalorias();
        if (!sabor.empty()) {
            ss << ", Sabor: " << sabor;
        }
        return ss.str();
    }
};
#endif
