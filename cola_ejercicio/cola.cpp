#include <iostream>
#include <string>
// cola.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include "cola.h"

int main()
{
    /***************************************************
    * Aprenderemos a diseñar clases genéricas. Tambien se conocen como templates
    * Por lo pronto usamos una de ellas: la clase vector
    ****************************************************/
    vector<string> heroes = { 
	"WonderWoman",
	"SpiderMan",
        "Aquaman", 
		"DeadPool", 
		"IronMan",
		"Batman", 
		"Flash",
		"Thor",
    "BlackWidow",
	 "SuperMan", 
	 "Hulk",
	  "CaptainAmerica", 
	  "BlackPanter",
    "Wolverine",
	 "DareDevil", 
	 "DoctorStrange",
	  "Hawkeye" };

    /***************************************************
    * Un objeto vector tiene varios métodos. Uno de ellos
    * es pedirle su tamaño. Con ese tamaño creamos una
    * cola de ese tamaño.
    ****************************************************/
    cola micola(heroes.size() * 2);

    /***************************************************
    * Ponemos en la fila a todos los super héroes
    ****************************************************/
    for (string heroe : heroes) {//For each de c++, recorre heroes y pone cada elemento en la variable heroe
        micola.put(heroe);
    }
    /***************************************************
    * Ya no hay espacio para un nuevo super héroe.
    * Se acabaron los turnos
    ****************************************************/
    
    
    //********** PRIMER PUNTO
    //micola.put("Melvin Beederman");
    micola.print_cola();
    
    //********** SEGUNDO PUNTO
    int index = -1;
    string original = "";
    string nuevo = "Pepe";
    
    cout << "\n\nIngrese un index para intercambiar por Jorge: " << endl << endl;
    cin >> index;
    
    micola.cambio(index, nuevo);
    
    micola.print_cola();
    
    cout << "\n\nCOLADO: " << endl << endl;
    
    string colado = "Jorge";
    micola.colado(colado);
    //while (true) {
    //    cout << "Atendiendo a: " << micola.get() << endl;
    //}
    micola.print_cola();
    micola.get();
}
//Para estudiar: Metodo para invertir cola.

