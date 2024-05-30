#ifndef CUENTA_H
#define CUENTE_H

#include "Comida.h"
using namespace std;
#include <sstream>
#include <iostream>
#include <vector>

class Cuenta {
private:
    vector<Comida*> listaComida;
    float propina;
    string comentario;

public:
    Cuenta() : propina(0.0), comentario("") {}

    //~Cuenta() {
        //for (auto comida : listaComida) {
            //delete comida;
        //}
    //}
    void printProductos(){
      int num = 0;
      for (auto comida: listaComida){
        num = 1 + num;
        cout << num << ".- ---" << comida ->get_nombre() << ": --- " << "$" <<  comida-> get_precio() <<  endl;
      }
    }
    void agregarComida(Comida* comida) {
        listaComida.push_back(comida);
    }

    void agregarPropina(float porcentaje) {
        propina = calcularPrecioTotal() * (porcentaje / 100.0);
    }

    void dejarComentario(const string& texto) {
        comentario = texto;
    }

    float calcularPrecioTotal() const {
        float total = 0.0;
        for (auto comida : listaComida) {
            total += comida->get_precio();
        }
        total += propina;
        return total;
    }

    string getComentario() const {
        return comentario;
    }
};
#endif