#ifndef POSTRE_H
#define POSTRE_H

#include "Comida.h"
using namespace std;

#include <iostream>
#include <vector>
#include <sstream>


class Postre : public Comida {
private:
    int calorias;

public:
    Postre() : Comida("", "", 0.0), calorias(0) {} 
    Postre(const string& nombre, const string& tipo, float precio, int calorias)
        : Comida(nombre, tipo, precio), calorias(calorias) {}

    float calcularCalorias() const override {
        return calorias;
    }

    string toString() const override {
        stringstream ss;
        ss << "Postre: " << nombre << ", Descripción: " << tipo << ", Precio: " << precio
           << ", Calorías: " << calorias;
        return ss.str();
    }
};

#endif
