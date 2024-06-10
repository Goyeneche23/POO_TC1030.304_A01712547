#ifndef CUENTA_H
#define CUENTE_H
#include "Menu.h"
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

    Menu menu;
    void limpiar(){
        listaComida.clear();
    }
    void printProductos()const{
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
    void seleccionarProductos(Menu& menu) {
        string nombre;
        cout << "ingrese el producto consumido (escriba 0 si ya esta completa): ";
        cin >> nombre;
        while (nombre != "0") {
            Comida* producto = menu.buscarNombre(nombre);
            if (producto != nullptr) {
                agregarComida(producto);
                cout << "Producto agregado a la cuenta." << endl;
            } else {
                cout << "Producto no existente." << endl;
            }
            cout << "ingrese el producto consumido (escriba 0 si ya esta completa): ";
            cin >> nombre;
        }
    }
};
#endif