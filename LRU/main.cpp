#include <iostream>
#include "LRU.h"


int main() {
    int capacidad;
    std::cout << "Introduce la capacidad: ";
    std::cin >> capacidad;
    
    LRUCache cache(capacidad);
    
    std::string comando;
    while (true) {
        std::cout << "\nIntroduce un comando insert <clave> <valor>, delete <clave>, mostrar, exit: ";
        std::cin >> comando;

        if (comando == "insert") {
            int clave, valor;
            std::cin >> clave >> valor;
            cache.put(clave, valor);
        } else if (comando == "delete") {
            int clave;
            std::cin >> clave;
            cache.get(clave);
        } else if (comando == "mostrar") {
            cache.mostrarCache();
        } else if (comando == "exit") {
            break;
        } else {
            std::cout << "Comando inválido." << std::endl;
        }
    }

    return 0;
}