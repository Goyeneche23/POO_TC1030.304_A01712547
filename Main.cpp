#include "Menu.h" 
#include "Cuenta.h"
#include <iostream>
#include <sstream>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

int main(){
    bool correr = 1;
    Cuenta cuenta;
    Menu menu;
    Comida* Carajillo = new Bebida("Carajillo", "CAfe con Licor 43", 3.99, "Carajillo", .20, 600, true);
    Comida* Cocacola = new Bebida("Cocacola", "Refresco Coca cola Norm", 1.99, "Carajillo", .30, 600, false);
    Comida* pastelChocolate = new Postre("Pastel chocolate", "Pastel", 5.99, 2, 50, 200, "Chocolate");
    Comida* spaghetti = new Platillo("Spaghetti", "Spaghetti con salsa de tomate", 8.0, 120, 1.89, true, false);

    menu.agregarComida(Carajillo);
    menu.agregarComida(Cocacola);
    menu.agregarComida(pastelChocolate);
    menu.agregarComida(spaghetti);
    
    while (correr == 1){           
        int accion;
        cout << "------------------------------------------------------------" << endl;
        cout << "1.- Crear cuenta" << endl;
        cout << "2.- Crear alimento" << endl;
        cout << "3.- Mostrar menu" << endl;
        cout << "4.- Mostrar alimento" << endl;
        cout << "5.- Salir(No se guardara el menu)" << endl;
        cin >> accion;
        if(accion == 1){
            cuenta.seleccionarProductos(menu);
            bool opPropina;
            cout << "Propina | 1 = si - 0 = no | -->"; cin >>  opPropina;
            if (opPropina == 1){
                float porcentaje;
                cout << "ingrese el porcentaje: "; cin >> porcentaje;
                cuenta.agregarPropina(porcentaje);
                }
            cout << "----------------------------- " << endl;
            cuenta.printProductos();
            cout << "Precio Total: $" << cuenta.calcularPrecioTotal() << endl;
            cuenta.limpiar();
        } else if(accion == 2){
            int tipoPlato;
            cout << "seleccione el tipo de plado" << endl;
            cout << "1.- Plato fuerte" << endl;
            cout << "2.- Bebida" << endl;
            cout << "3.- Postre" << endl;
            cin >> tipoPlato;
            menu.nuevoPlato(tipoPlato);
        }else if(accion == 3){
            menu.mostrarMenu();
        }else if(accion == 4){
            string nombre;
            cout << "Que alimento desea buscar? "; cin >> nombre;
            Comida* plato = menu.buscarNombre(nombre);
            if(plato != nullptr){
                cout << plato -> toString() << endl;
            }else{
                cout << "No se encontro el alimento" << endl;
            }
        }else if(accion == 5){
            menu.limpiar();
            cuenta.limpiar();
            cout << "Se han eliminado todos los alimentos del menu." << endl;
            cout << "Saliendo...";
            correr = 0;
        }else{
            cout << "Seleccione una opcion valida :)" << endl;
        }        
    }   
    return 0;
}