#ifndef PLATILLO_H
#define PLATILLO_H

#include "Comida.h"
using namespace std;
#include <sstream>
#include <iostream>
#include <vector>

class Platillo : public Comida {
private:
    float gramos;
    float caloriasG;
    bool salsa;
    bool vegetariano;
public:
    Platillo() : Comida("", "", 0.0), gramos(0.0), caloriasG(0), salsa(false), vegetariano(false) {} 
    Platillo(const string& nombre, const string& tipo, float precio, float gramos, float caloriasG, bool salsa, bool vegetariano) : Comida(nombre, tipo, precio), gramos(gramos), caloriasG(caloriasG), salsa(salsa), vegetariano(vegetariano) {}

    float calcularCalorias() const override {
        float calorias;
        if(vegetariano == true){
            calorias = (gramos/100)* 24; //Promedio de calorias en ensaladas segun tabla de calorias
        if(salsa == true){
            calorias += 105;
        }}else{
            calorias = caloriasG * gramos;
            if(salsa == true){
                calorias += 105;
            }
        } 
        return calorias;
    }
    string toString() const override {
        stringstream ss;
        ss << "Platillo: " << nombre << ", Descripción: " << tipo << ", Precio: " << precio << ", Calorias: " << calcularCalorias();
        return ss.str();
    }
};

#endif
