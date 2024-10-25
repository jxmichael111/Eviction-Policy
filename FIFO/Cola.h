#include <iostream>
class Nodo {
public:
    int valor;
    Nodo* siguiente;

    Nodo(int val) : valor(val), siguiente(nullptr) {}
};

class Cola {
private:
    Nodo* frente;  
    Nodo* final;   
    int tamano;    

public:
    Cola() : frente(nullptr), final(nullptr), tamano(0) {}

    
    ~Cola() {
        while (!estaVacia()) {
            desencolar();
        }
    }

    
    void encolar(int valor) {
        Nodo* nuevoNodo = new Nodo(valor);
        if (final) {
            final->siguiente = nuevoNodo;
        }
        final = nuevoNodo; 
        if (!frente) {
            frente = nuevoNodo; 
        }
        tamano++;
        std::cout << "Elemento " << valor << " encolado." << std::endl;
    }

    
    void desencolar() {
        if (estaVacia()) {
            std::cout << "La cola está vacia. No se puede desencolar." << std::endl;
            return;
        }
        Nodo* nodoAEliminar = frente;
        std::cout << "Elemento " << frente->valor << " desencolado." << std::endl;
        frente = frente->siguiente;
        delete nodoAEliminar;
        tamano--;

        if (estaVacia()) {
            final = nullptr; 
        }
    }

    int verFrente() const {
        if (estaVacia()) {
            std::cout << "La cola esta vacia." << std::endl;
            return -1;
        }
        return frente->valor;
    }

    
    bool estaVacia() const {
        return frente == nullptr;
    }

    int obtenerTamano() const {
        return tamano;
    }
};