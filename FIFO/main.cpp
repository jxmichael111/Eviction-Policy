#include <iostream>
#include "Cola.h"

int main() {
    Cola cola;
    std::string comando;

    while (true) {
        std::cout << "\nIntroduce un comando: encolar <valor>, desencolar, verfrente, tamaño, vacia, exit: ";
        std::cin >> comando;

        if (comando == "encolar") {
            int valor;
            std::cin >> valor;
            cola.encolar(valor);
        } else if (comando == "desencolar") {
            cola.desencolar();
        } else if (comando == "verfrente") {
            std::cout << "Elemento al frente: " << cola.verFrente() << std::endl;
        } else if (comando == "tamano") {
            std::cout << "Tamano de la cola: " << cola.obtenerTamano() << std::endl;
        } else if (comando == "vacia") {
            std::cout << "La cola esta vacia: " << (cola.estaVacia() ? "Si" : "No") << std::endl;
        } else if (comando == "exit") {
            break;
        } else {
            std::cout << "Comando invalido." << std::endl;
        }
    }

    return 0;
}