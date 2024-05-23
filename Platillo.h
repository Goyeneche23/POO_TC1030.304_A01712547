#ifndef PLATILLO_H
#define PLATILLO_H

#include "Comida.h"
using namespace std;
#include <sstream>
#include <iostream>
#include <vector>


class Platillo : public Comida {
public:
    Platillo() : Comida("", "", 0.0) {} 
    Platillo(const string& nombre, const string& tipo, float precio) : Comida(nombre, tipo, precio) {}

    float calcularCalorias() const override {
        return 0.0;
    }

    string toString() const override {
        stringstream ss;
        ss << "Platillo: " << nombre << ", Descripción: " << tipo << ", Precio: " << precio;
        return ss.str();
    }
};

#endif
