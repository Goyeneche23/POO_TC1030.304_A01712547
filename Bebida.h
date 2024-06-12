#ifndef BEBIDA_H
#define BEBIDA_H

#include "Comida.h" // Hara uso del archivo Comida.H
using namespace std; //Como no es un codigo muy complejo nos ahorrara usar std en cada string
#include <iostream> //Librerias que se usaran
#include <vector>
#include <sstream> //se usara para manipular cadenas de texto en una funcion

class Bebida : public Comida { //Clase Bebida se crea y se le da acceso (Hereda) todos los objetos publicos de Comida
private:
    string sabor; // Atributos Nuevos
    float caloriasMLitros;
    int mililitros;
    bool alcohol;
    
public:
    Bebida() : Comida("", "", 0.0), sabor(""), caloriasMLitros(0), mililitros(0), alcohol(false) {}  //valores por defecto parametr
    Bebida(const string& nombre, const string& tipo, float precio, const string& sabor, float caloriasMLitros, int mililitros, bool alcohol)
        : Comida(nombre, tipo, precio), sabor(sabor), caloriasMLitros(caloriasMLitros), mililitros(mililitros), alcohol(alcohol){}
    //const&string pasa los atributos por defecto sin que puedan ser modificados el constructor bebida hace uso de valores de constructor comida
    string getSabor()  { 
        return sabor; 
    }
    float calcularCalorias(){  // La funcion CalcularCalorias se Sobreescribira para esta clase y regresara el valor de las calorias
        float calorias = caloriasMLitros * mililitros;
        if (alcohol == true){
            calorias += (calorias * .20);
        }
        return calorias;
    }

    string toString(){ // Esta funcion iguak se sobre escribira
        stringstream ss; //Se usa la libreria sstream para cambiar tipos de datos a vcadenas de texto y asi imprimirlos 
        ss << "Bebida: " << nombre << ", Descripción: " << tipo << ", Precio: " << precio << ", Sabor: " << sabor << ", Calorías: " << calcularCalorias();
        return ss.str(); //Regresa la representacion de cadena de la Bebida, proporcionada. Osea ayuda a imprimirla vaya
    }
};
#endif
