// cifrados.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include "funciones.cpp"

int main() {
        const char* message = "HELLO WORLD";
        int shift = 5;
        char* encrypted = encryptCaesar(message, shift);
        std::cout << "Encrypted: " << encrypted << std::endl;
        delete[] encrypted;;
        std::string encrypted1 = encryptCaesar1(message, shift);
        std::cout << "Encrypted: " << encrypted1 << std::endl;

        char* encrypted2 = encryptVigenere1(message, "xzy");
        std::cout << "Encrypted1: " << encrypted2 << std::endl;
        delete[] encrypted2;
        return 0;
    }



// Ejecutar programa: Ctrl + F5 o menú Depurar > Iniciar sin depurar
// Depurar programa: F5 o menú Depurar > Iniciar depuración

// Sugerencias para primeros pasos: 1. Use la ventana del Explorador de soluciones para agregar y administrar archivos
//   2. Use la ventana de Team Explorer para conectar con el control de código fuente
//   3. Use la ventana de salida para ver la salida de compilación y otros mensajes
//   4. Use la ventana Lista de errores para ver los errores
//   5. Vaya a Proyecto > Agregar nuevo elemento para crear nuevos archivos de código, o a Proyecto > Agregar elemento existente para agregar archivos de código existentes al proyecto
//   6. En el futuro, para volver a abrir este proyecto, vaya a Archivo > Abrir > Proyecto y seleccione el archivo .sln