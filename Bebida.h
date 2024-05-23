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
    int calorias;

public:
    Bebida() : Comida("", "", 0.0), sabor(""), calorias(0) {} 
    Bebida(const string& nombre, const string& tipo, float precio, const string& sabor, int calorias)
        : Comida(nombre, tipo, precio), sabor(sabor), calorias(calorias) {}

    string getSabor() const { return sabor; }

    float calcularCalorias() const override {
        return calorias;
    }

    string toString() const override {
        stringstream ss;
        ss << "Bebida: " << nombre << ", Descripción: " << tipo << ", Precio: " << precio
           << ", Sabor: " << sabor << ", Calorías: " << calorias;
        return ss.str();
    }
};
#endif
