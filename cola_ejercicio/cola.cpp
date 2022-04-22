#include <iostream>
#include <string>
// cola.cpp : Este archivo contiene la funci�n "main". La ejecuci�n del programa comienza y termina ah�.
//

#include "cola.h"

int main()
{
    /***************************************************
    * Aprenderemos a dise�ar clases gen�ricas. Tambien se conocen como templates
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
    * Un objeto vector tiene varios m�todos. Uno de ellos
    * es pedirle su tama�o. Con ese tama�o creamos una
    * cola de ese tama�o.
    ****************************************************/
    cola micola(heroes.size() * 2);

    /***************************************************
    * Ponemos en la fila a todos los super h�roes
    ****************************************************/
    for (string heroe : heroes) {//For each de c++, recorre heroes y pone cada elemento en la variable heroe
        micola.put(heroe);
    }
    /***************************************************
    * Ya no hay espacio para un nuevo super h�roe.
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

