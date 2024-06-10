#ifndef MENU_H
#define MENU_H

#include "Platillo.h"
#include "Bebida.h"
#include "Postre.h"
#include <sstream>
#include <iostream>
#include <vector>

class Menu {
private:
    vector<Comida*> listaComida;

public:
    ~Menu() {
        for (Comida* comida : listaComida) {
            delete comida;
        }
    }
    void limpiar() {
        for (Comida* comida : listaComida) {
            delete comida;}
        listaComida.clear();
    }
    void agregarComida(Comida* comida) {
        listaComida.push_back(comida);
    }

    void mostrarMenu() const {
        for (const auto& item : listaComida) {
            cout << item->toString() << ", Calorías: " << item->calcularCalorias() << endl;
            cout << "-----------------------------------------" << endl;
        }
    }
    void nuevoPlato(int tipoPlato){
        int mililitros;
        string  nombre, tipo, sabor;
        float precio, caloriasIngrediente, caloriasMLitros, caloriasG, gramos, caloriasGramo;
        bool alcohol, salsa, vegetariano;

        cout << "ingrese el nombre(str): "; cin >> nombre;
        cout << "ingrese el tipo(str): "; cin >> tipo;
        cout << "ingrese el precio(float): "; cin >> precio;
        if(tipoPlato == 1){ //PlatilloFuerte
            cout << "ingrese los gramos(float): "; cin >> gramos;
            cout << "ingrese las calorias x gramo(float): "; cin >> caloriasG;
            cout << "salsa? 1 = si, 0 = No: "; cin >> salsa;
            cout << "Vegetariano? 1= si, 0= no: "; cin >> vegetariano;
            agregarComida(new Platillo(nombre,tipo,precio, gramos, caloriasG, salsa, vegetariano));
        }else if(tipoPlato == 2){//Bebida
            cout << "ingrese los mililitros(int): "; cin >> mililitros;
            cout << "ingrese las calorias x mililitro(float): "; cin >> caloriasMLitros;
            cout << "ingrese el sabor(str): "; cin >> sabor;
            cout << "Alcohol ? si = 1, no = 0 : "; cin >> alcohol;
            agregarComida(new Bebida(nombre,tipo,precio,sabor,caloriasMLitros,mililitros, alcohol));
        }else if(tipoPlato == 3){
            cout << "ingrese los gramos(float): "; cin >> gramos;
            cout << "ingrese las calorias x gramo(float): "; cin >> caloriasGramo;
            cout << "ingrese las calorias de los ingredientes(float): "; cin >> caloriasIngrediente;
            cout << "ingrese el sabor(str): "; cin >> sabor;
            agregarComida(new Postre(nombre,tipo,precio,caloriasGramo,caloriasIngrediente,gramos,sabor));
        }else{
            cout << "Opcion no valida." << endl;
        }
    }
    Comida* buscarNombre(const string& nombre) const {
        for (const auto& comida : listaComida) {
            if (comida->get_nombre() == nombre) {
                return comida;
            }
        }
        return nullptr;
    }
};
#endif

