#include <iostream>
#include "LRU.h"


int main() {
    /*
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
    //*/

    int capacity;
    std::cout << "Ingrese la capacidad de la cache: ";
    std::cin >> capacity;
    LRUCache cache(capacity);

    for (int i = 0; i < 9; i++) {
        cache.put(i, i*2);
    }
    cache.get(7);
    cache.get(7);
    cache.get(4);
    
    cache.put(10,34);

    cache.get(7);
    cache.get(7);
    cache.get(7);

    cache.put(50,50);

    cache.get(3);
    cache.get(3);
    cache.get(3);

    cache.mostrarCache();
    cache.put(100,100);
    cache.mostrarCache();
    return 0;
}