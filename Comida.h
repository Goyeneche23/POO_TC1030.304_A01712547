
#ifndef COMIDA_H
#define COMIDA_H
//Librerias que se usaran
#include <iostream>
#include <vector> //se usaran vectores para almanecar los punteros de los alimentos
#include <string>
#include <sstream>  //se usara para manipular cadenas de texto en una funcion
using namespace std;

class Comida { // Clase Abstracta que sera la base para los alimentos
  protected: //Protected es menos Restrictiva que private y te permite usar los atributos pero no modificarlos
    string nombre; // Son los atributos que tendran todo alimento sin importar el tipo
    string tipo;
    float precio;
  public: // Public osease que cualquier clase puede acceder a ellos
    Comida() : nombre(""), tipo(""), precio(0.0) {} //Constructor base por defecto de la clase inicializa nombre,tipo,precio vacios
    Comida(string nom, string tip, float num): //inicializa esos datos con valores como argumentos 
    nombre(nom), tipo(tip), precio(num) {};//Para inicializar los datos con los valores porporcionados directamente
    virtual ~Comida() {} //Destructor
    string get_nombre() { //Getters para llegar a los atributos aunque no sean publicos
      return nombre;
    }
    string get_tipo() {
      return tipo;
    }
    float get_precio() {
      return precio;
    }
   virtual float calcularCalorias() = 0;  // Funcion para calcular caloriasvirtual que espera ser modificada en clases derivadas
   // Se sobreescribira porque con los distintos tipos de comida se calcula las calorias de manera diferente
    virtual string toString() = 0; //Funcion virtual igual que servira para convertir en string todo el constructor creado derivado
    // Parecido al del proyecto Demo mostrado, nos permitira imprimir el constructor digamos
    //En esta ultima funcion se usara sstream se explicara mejor en otra clase pa ajamplificar
};
#endif
