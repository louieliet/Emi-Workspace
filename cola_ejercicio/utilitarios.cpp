#include "cola.h"

void cola::colado(string nuevo) {
	int j = size;

	try {//Le decimos al lenguaje que vigile si en la siguiente porcion de codigo puede ocurrir una excepcion
        if (top == 0)
            throw FullQueue();//Si esta lleno se dispara la excepcion FullQueue usando el operador throw
        //una vez ocurre la excepcion se va al catch. Si hay mas de una excepcion posible en el try, el catch tiene que estar
        //Adaptado para cacharla.
    }//Todo lo que esta adentro de este bloque puede generar una excepcion, si ocurre lo manda al catch
    catch (FullQueue& ex) {
        std::cout << ex.what() << std::endl;
        exit(2);
    }//En el catch se especifica que se hace si ocurre una excepcion. In try you throw an exception and catch catches it.
    top--;
    
    for (int i = size; i < capacity; i++) {
    	//cout << " i : " << i << " nom : " << espacio[i]<< endl;
        espacio[i - 1] = espacio[i];
    }
    
    espacio[capacity - 1] = nuevo ;
    size++;
}

int cola::cambio(int index, string nuevo) 
{
	for (int i = capacity-1; i >= 0; i--) 
    {
        if (i == (capacity -1 - index)){
        	espacio[i] = nuevo;
		}
    }
    return 0;
}

cola::cola(int capacity) {
    this->capacity = capacity;
    // Operador para reservar memoria de C++. El operador new
    espacio = new string[capacity];
    //espacio = (int*)malloc(sizeof(int) * capacity);
    for (int i = 0; i < capacity; i++)
        espacio[i] = "a";
    size = 0;
    top = capacity;
}

//constructor copia
cola::cola(const cola& origen) {
    cout << "se ejecuta el constructor copia" << endl;
    size = origen.size;
    top = origen.top;
    capacity = origen.capacity;
    //espacio = origen.espacio;
    //crear un nuevo espacio de la misma capacidad y con los mismos valores
    espacio = new string[origen.capacity];
    //espacio = (int*)malloc(sizeof(int) * origen.capacity);
    for (int i = 0; i < origen.capacity; i++) {
        espacio[i] = origen.espacio[i];
    }

}
cola::~cola() {
    cout << "Se destruyo el objeto" << endl;
    //delete, delete[]
    delete[] espacio;
}
int cola::tamano() {
    return size;

}
void cola::put(string el) {
    try {//Le decimos al lenguaje que vigile si en la siguiente porcion de codigo puede ocurrir una excepcion
        if (top == 0)
            throw FullQueue();//Si esta lleno se dispara la excepcion FullQueue usando el operador throw
        //una vez ocurre la excepcion se va al catch. Si hay mas de una excepcion posible en el try, el catch tiene que estar
        //Adaptado para cacharla.
    }//Todo lo que esta adentro de este bloque puede generar una excepcion, si ocurre lo manda al catch
    catch (FullQueue& ex) {
        std::cout << ex.what() << std::endl;
        exit(2);
    }//En el catch se especifica que se hace si ocurre una excepcion. In try you throw an exception and catch catches it.
    top--;
    espacio[top] = el;
    size++;

}
string cola::peek() {
    string resultado = get();
    if (resultado != "")
        put(resultado);
    return resultado;


}
int cola::isempty() {
    return (size) == 0 ? 1 : 0;
    //return (st->top) == CAPACITY? 1: 0;
}

int cola::capacidad() {
    return capacity;
    //return (*st).capacity;
}
string cola::get() {
    string resultado = "";
    try {
        if (top == capacity)
            throw EmptyQueue();
    }
    catch (EmptyQueue& ex) {
        std::cout << ex.what() << std::endl;
        exit(2);//Exit es el metodo que se usa para terminar el codigo, lo terminamos con el numero 2, que indica que algo salio mal
                //0 significa que todo fue bien, cualquier otro valor indica que algo salio mal.
    }
    resultado = espacio[capacity - 1];
    for (int i = capacity - 2; i > capacity - size - 1; i--)
        espacio[i + 1] = espacio[i];
    espacio[capacity - size] = "";
    top++;
    size--;
    return resultado;

}
void cola::print_cola() {
    for (int i = capacity-1; i >= 0; i--) {
        cout << espacio[i] << " ";
    }
    cout << "\n";

}
void cola::clean_cola() {
    top = capacity;
    size = 0;

}

//Sobre carga de operadores
void cola::operator+=(int valor) {
    cout << "tope: " << top << endl;
    for (int i = capacity - 1; i >= top; i--) {
        espacio[i] += valor;
    }

}

//
//cola& cola::invertircola() {
//    cola resultado = cola(*this);//se crea una copia a la cola original
//}
