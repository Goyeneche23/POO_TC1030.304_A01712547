#include "Menu.h" 
#include "Cuenta.h"
#include <iostream>
#include <vector>
#include <sstream>
using namespace std;

int main(){
    bool correr = 1;
    Cuenta cuenta;//Llama clase Cuenta
    Menu menu;//Llama clase Menu
    Comida* Carajillo = new Bebida("Carajillo", "CAfe con Licor 43", 230, "Carajillo", .20, 600, true); //Se guardan como pointer
    Comida* Cocacola = new Bebida("Cocacola", "Refresco Coca cola Norm", 20, "Carajillo", .30, 600, false); //Se elige el tipo para ver los datos a ingresar 
    Comida* pastelChocolate = new Postre("Pastel", "Pastel", 600, 2, 50, 200, "Chocolate");
    Comida* spaghetti = new Platillo("Spaghetti", "Spaghetti salsa de tomate", 290, 120.00, 1.89, true, false);
    //Todos estos son ejemplo para agregar desde consola y hacer mas facil su revision
    menu.agregarComida(Carajillo); //Esos pointers se agregan a listaComida
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
        cout << "5.- Ver direccion en programa " << endl;
        cout << "6.- Salir(No se guardara el menu)" << endl;
        cout << "Evitar el uso de espacion :) " << endl;
        cin >> accion;  //Usuario ingresa q hacer
        if(accion == 1){
            cuenta.seleccionarProductos(menu);
            bool opPropina;
            cout << "Propina | 1 = si - 0 = no | -->"; cin >>  opPropina;
            if (opPropina == 1){
                float porcentaje;
                cout << "ingrese el porcentaje(int): "; cin >> porcentaje;
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
            cout << "Que alimento desea buscar? (Ingrese el nombre del platiilo, Bebida o Postre) --> "; cin >> nombre;
            Comida* plato = menu.buscarNombre(nombre);
            if(plato != nullptr){
                cout << plato -> toString() << endl;
            }else{
                cout << "No se encontro el alimento" << endl;
            }
        }else if(accion == 5){
            cout << "Direcciones " << endl;
            menu.verDireccion();
        }else if(accion == 6){
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
}  // Realmente todo lo del main es mas que nada emplear las funciones de manera interactiva y ya es muy simple de enteder