#include "Menu.h" 
#include "Cuenta.h"
#include <iostream>
#include <sstream>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

int main() {

    Cuenta cuenta;
    Comida* Carajillo = new Bebida("Carajillo", "CAfe con Licor 43", 3.99, "Carajillo", .20, 600, true);
    Comida* Cocacola = new Bebida("Cocacola", "Refresco Coca cola Norm", 1.99, "Carajillo", .30, 600, false);
    Comida* pastelChocolate = new Postre("Pastel chocolate", "Pastel", 5.99, 2, 50, 200, "Chocolate");
    Comida* spaghetti = new Platillo("Spaghetti", "Spaghetti con salsa de tomate", 8.0);
    cout << pastelChocolate ->toString() << endl;
    cout << Carajillo ->toString() << endl;
    cout << Cocacola ->toString() << endl;

    cuenta.agregarComida(Carajillo);
    cuenta.agregarComida(Cocacola);
    cuenta.agregarComida(pastelChocolate);
    cuenta.agregarComida(spaghetti);
    cuenta.printProductos();
    
    cuenta.agregarPropina(10); // 10% de propina
    cuenta.dejarComentario("Excelente servicio, muy buena comida!");

    cout << "Precio Total: $" << cuenta.calcularPrecioTotal() << endl;
    cout << "Comentario: " << cuenta.getComentario() << endl;

    delete Carajillo;
    delete Cocacola;
    delete pastelChocolate;
    delete spaghetti;
    
    return 0;
}