#include "Menu.h" 
#include "Cuenta.h"
#include <iostream>
#include <sstream>
#include <vector>
using namespace std;



int main() {
    
    Platillo* p1 = new Platillo("Hamburguesa", "Deliciosa hamburguesa con queso y vegetales", 100);
    Bebida* b1 = new Bebida("Refresco", "Refresco de cola", 1.99, "Cola", 150);
    Postre* postre1 = new Postre("Pastel de chocolate", "Pastel de chocolate con crema batida", 5.99, 350);
    Platillo* p2 = new Platillo("Spaghetti", "Spaghetti con salsa de tomate", 8.0);

   
    Cuenta cuenta;
    
   
    cuenta.agregarComida(p1);
    cuenta.agregarComida(b1);
    cuenta.agregarComida(postre1);
    cuenta.agregarComida(p2);
    cuenta.printProductos();
    
    cuenta.agregarPropina(10); // 10% de propina
    cuenta.dejarComentario("Excelente servicio, muy buena comida!");

    cout << "Precio Total: $" << cuenta.calcularPrecioTotal() << endl;
    cout << "Comentario: " << cuenta.getComentario() << endl;

    return 0;
}