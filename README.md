# POO_TC1030.304_A01712547
GestionadorRestaurantes


Este proyecto es un sistema de gestión de restaurante desarrollado en C++, que permite a los propietarios de restaurantes administrar su menú, tomar órdenes y gestionar reservaciones. 


Características principales
Gestión de menú: El sistema permite agregar platillos, bebidas y postres en el menú del restaurante.


Toma de órdenes: Los camareros pueden registrar las órdenes de los clientes, incluyendo platillos, bebidas y postres seleccionados.


Cálculo de precios: El sistema calcula automáticamente el precio total de cada orden, teniendo en cuenta los productos seleccionados y las propinas aplicadas.


Caclulo de Calorias Consumidas: Con el uso del polimorfismo igualmente se calcula para cada tipo de plato (de manera diferente) las calorias que se consumiran en los alimentos.


Direcciones: Usando pointers and references podremos acceder a la direccion donde se encuentra cada platillo.


Nota AVANCE CODIGO 1
Apenas es el concepto basandome en los ejemplos del profe de poo para ir viendo las relaciones que tendran las clases, Se agregara una clase mas para hacer una interfaz mas simple en el main probablemente, asi como mas funciones en todas las clases, todo lo que esta ahorita en el main es solo para probar el codigo.

Nota (Avance CODIGO 2, Avance3 en total)
Por lo que entendi en los comentarios a la revision de mi avance anterior la estructura del codigo iba bien por lo cual en esta entrega no cambie eso solo agregue la clase de interactive que ahorita de hecho no la corro con el codigo es solo ir creandola para el proximo avance (la quiero usar como menu para dejar el main limpio aun no se si vaya a funcionar realmente). Entonces aqui ya que las competencias que se me pedian eran polimorfismo y una classe abstracta es lo que agregue, la clase abtracta ya estaba desde el avance pasado, y el polimorfismo se puede observar en la clase calcularCalorias() que actualmente solo esta en la clase Bebida y Postre integrada. La sobrecarga que me dijeron que me faltaba en la entrega pasada tambien ya la añadi o hice mas notable en estas mismas clases en sus constructores.  para terminar recordar todo lo que esta ahorita en el main es solo para probar el codigo. (olvide mandar el link :v)

Avance 4
Por lo que entendi en los comentarios a la revision de mi avance anterior la estructura del codigo iba bien por lo cual en esta entrega no cambie eso solo agregue la clase de interactive que ahorita de hecho no la corro con el codigo es solo ir creandola para el proximo avance (la quiero usar como menu para dejar el main limpio aun no se si vaya a funcionar realmente). Entonces aqui ya que las competencias que se me pedian eran polimorfismo y una classe abstracta es lo que agregue, la clase abtracta ya estaba desde el avance pasado (class Comida), y el polimorfismo se puede observar en el objero virtual funcion calcularCalorias() que esta en la clase Bebida, platillo y Postre integrada, calculando las calorias de manera diferente con diferentes atributos cada una. La sobrecarga que me dijeron que me faltaba en la entrega pasada tambien ya la añadi o hice mas notable en estas mismas clases en sus constructores.  para terminar recordar todo lo que esta ahorita en el main es solo para probar el codigo. Tambien se corrige el UML, en si se corrigio todas las competencias que faltaron.

Subcompetencias a falta de acreditar:

Identifico los casos que harían que el proyecto deje de funcionar
Este codigo ya esta terminado por lo que realmente ya no hay error que pueda producir el codigo, aunque si hay cosas a mejorar: El codigo podria mejorarse guardando los datos (Menu) creados y modificados en un archivo y abriendo este cada vez que se ingresa al codigo, esto porque siempre que se deja de correr los nuevos alimentos agregados al menu desde el usuario se pierden, tambien se podria mejorar la interaccion con el usuario, cuando el usuario entrega un tipo de dato diferente al esperado int, str, float, string con espacios, etc... el codigo puede entrar en un bucle, investigando encontre varias maneras para solucionar esto con unas funciones pero es un trabajo un poco laborioso.


Genero un diagrama de clases UML correcto y y explico su relación con el problema de forma clara
El diagrama de clases UML se fue modificando en cada entrega hasta llegar al que esta en este repositorio (ya correcto).


Se implementa de manera correcta la sobrecarga y sobreescritura de métodos
La sobree


Se implementa de manera correcta el concepto de Polimorfismo


Se implementa de manera correcta el concepto de Clases Abstractas


Usa herramientas de control de versiones


Incluye documentación útil en el repositorio del pryecto



Entrega Final
Por los comentarios dejados en la revision del avance 4 me dare a la tarea de explicar el codigo y sus funciones a detalle (Igual cualquier duda del codigo contactarme), el codigo esta repleto de comentarios que explican el funcionamiento de muchas lineas, en este apartado me dedicare a explicar mas de manera teorica como funciona el codigo. 

Primero la Classe Comida sera una clase abstracta que servira para simplificar el trabajo en el codigo, esta generara un constructor de comida que tendra unos atributos, que todas las demas clases que hereden comida(platillo, postre, bebida) usaran, 


Vectores:
Se usan los Vectores para almacenar en forma de lista la comida que haya en el Menu y tambien en la cuenta, listaComida, listaCuenta. Pero aunque ya habiamos usado vectores antes, en esta ocasion los vectores se usaran diferente, ya que envez de almacenar la Comida entera, almacenaremos sus apuntadores, lo cual solo afectara en la syntaxis pero la funcionalidad sera igual, entonces el vector listaComida tendra las direcciones de todos los constructores clases de las comidas creadas, y cuando se quiera llama para imprimirlo por ejemplo, se usara un apuntador que seleccionara ese platillo, y luego se usara la funcion toString para que lo imprima correctamente. Otra cosa diferente que ocasionara esto sera su eliminacion para evitar fugas de memoria, primero tendremos que eliminar los objetos a los cuales apuntan las direcciones del vector y luego las direcciones mismas que estan dentro del vector.
