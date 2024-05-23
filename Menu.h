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
    std::vector<Comida*> listaComida;

public:
    ~Menu() {
        for (auto item : listaComida) {
            delete item;
        }
    }

    void agregarComida(Comida* comida) {
        listaComida.push_back(comida);
    }

    void mostrarMenu() const {
        for (const auto& item : listaComida) {
            std::cout << item->toString() << ", Calorías: " << item->calcularCalorias() << std::endl;
        }
    }
};
#endif

