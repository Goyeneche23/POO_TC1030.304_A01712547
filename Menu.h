#ifndef MENU_H
#define MENU_H

#include "Platillo.h" //Hereda las comidas
#include "Bebida.h"
#include "Postre.h"
#include <sstream>
#include <iostream>
#include <vector> //Aca ya se usaran los vectores para hacer una lista digamos

class Menu {
private:
    vector<Comida*> listaComida; // Se crea el vector comida que el tipo de dato que almacenara sera los "Pointers" hacia comida
    //Esto ayuda q se almacenen directamente los pointers hacia los constructores y asi se accede directamente a ellos para manipular con mas funciones
public:
    ~Menu() { 
        for (Comida* comida : listaComida) {
            delete comida;
        }
    }
    void limpiar() { //Borrar memoria 
        for (Comida* comida : listaComida) { //Este for recorre los punteros que hay dentro del vector listaComida
            delete comida;} //Luego con el uso de punteros Elimina los objetos a los que apuntan estos osea los alimentos
        listaComida.clear(); // Ahora este se usa para .clear() para eliminar los elementos del vector
    } //Basicamente se elimina primero todo objeto al que apuntan lo pointers y luego se borran todas las direcciones almacenadas
    void agregarComida(Comida* comida) {//Esta funcion recibe "Comida* comida" Que es un alimento
        listaComida.push_back(comida);//Y luego .pushback() lo agrega a el final del vector listaComida en forma de direccion digamos
    }
    void mostrarMenu() {//Desplega Todos los alimentos
        for (int i = 0; i < listaComida.size(); i +=1) {//Recorre desde el valor inicial hasta el final de listaComida
            cout << listaComida[i]->toString() << ", Calorías: " << listaComida[i]->calcularCalorias() << endl;
            cout << "-----------------------------------------" << endl; 
        }//Para cada elemnto del menu usa la funcion toString() para imprimirlo como cadena de texto + sus calorias con otra funcion
    }//Se usa -> porque se manejan punteros
    void nuevoPlato(int tipoPlato){
        int mililitros;
        string  nombre, tipo, sabor;
        float precio, caloriasIngrediente, caloriasMLitros, caloriasG, gramos, caloriasGramo;
        bool alcohol, salsa, vegetariano;
        //Basicamente se pregunta al usario los valores y el los introfuce todo varia dependiendo el tipo de alimento
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
    Comida* buscarNombre(string nombre) { //en vez de void Comida* porque lo que se devuelve es un pointer 
        for (int i = 0; i < listaComida.size(); i+= 1) { //Mismo for de antes por la listaComida
            if (listaComida[i]->get_nombre() == nombre) { //Asegurar que el nombre existe en el constructor que se busca 
                return listaComida[i]; 
            }
        }
        return nullptr; // Si no se encuentra el nombre en el constructor se regresa nullptr que es como que no se regresa nada 
    }
    void verDireccion() {
        for (int i = 0; i < listaComida.size(); i += 1) {
           cout << listaComida[i] << ": ---> " << listaComida[i]->toString() << endl;  //Mismo formato pero se imprime la direccion
    }
}
};
#endif

