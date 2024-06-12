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
    vector<Comida*> listaCuenta; //Igual se usara un vector de pointers q apunta hacia el tipo comida
    float propina;
public:
    Cuenta() : propina(0.0) {}

    Menu menu; //Llamas a menu porque lo usaras en una funcion
    void limpiar(){   //No se ocupa eliminar a lo que apuntan los pointers porque eso ya se hace en menu
        listaCuenta.clear();   //Elimina los vectores donde se almacenan los pointers que apuntan a los laimentos
    }
    void printProductos(){  //Igual que en menu (checar la explicacion de clase menu)
      int num = 0;
      for (int i = 0; i < listaCuenta.size(); i += 1){
        num = 1 + num;
        cout << num << ".- ---" << listaCuenta[i] ->get_nombre() << ": --- " << "$" <<  listaCuenta[i]-> get_precio() <<  endl;
      }
    }
    void agregarComida(Comida* comida) {//Igual que en menu 
        listaCuenta.push_back(comida);
    }
    void agregarPropina(float porcentaje) { //Funcion simple para calular la propina en base al porcentaje
        propina = calcularPrecioTotal() * (porcentaje / 100.0);
    }
    float calcularPrecioTotal()  {
        float total = 0.0; //Declara Total como float
        for (auto comida : listaCuenta) { //El for esta escrito diferente haciendo uso de la funcion auto que detecta directamente el tipo de dato que es
            total += comida->get_precio(); // Y usando un estilo de range loop comida usa -> por el uso de pointers y se usa get para no entrar en atributos directamente
        } //Con el for por cada elemento en la cuenta se buscara su precio con el getter y se sumara al total
        total += propina; //se le agrega la propina
        return total;
    }
    void seleccionarProductos(Menu& menu) {//Se usa una funcion de menu asi que usamos una referencia para acceder a este
        string nombre; 
        cout << "ingrese el producto consumido (escriba 0 si ya esta completa): ";
        cin >> nombre;   //El usuario introduce nombre
        while (nombre != "0") {  //Si el usuario introduce cero el code se acaba
            Comida* producto = menu.buscarNombre(nombre);  //el producto sera igual a lo que la funcion regrese
            if (producto != nullptr) { //Producto es puntero de Comida ps porque en teoria lo que va a regresar es un valor nombre de comida
                agregarComida(producto); //Se agrega a la cuenta
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