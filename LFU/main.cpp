#include <iostream>
#include "LFU.h"
using namespace std;

void menu() {
    int capacity;
    cout << "Ingrese la capacidad de la cache: ";
    cin >> capacity;
    LFUCache cache(capacity);

    int choice;
    do {
        cout << "\n--- Menu LFU Cache ---\n";
        cout << "1. Insertar un valor\n";
        cout << "2. Obtener un valor\n";
        cout << "3. Mostrar todos los elementos\n";
        cout << "4. Salir\n";
        cout << "Seleccione una opcion: ";
        cin >> choice;

        if (choice == 1) {
            int key, value;
            cout << "Ingrese clave y valor: ";
            cin >> key >> value;
            cache.put(key, value);
            cout << "Elemento insertado en la cache.\n";
        } else if (choice == 2) {
            int key;
            cout << "Ingrese la clave a obtener: ";
            cin >> key;
            int result = cache.get(key);
            if (result == -1) {
                cout << "Clave no encontrada en la cache.\n";
            } else {
                cout << "Valor encontrado: " << result << endl;
            }
        } else if (choice == 3) {
            cache.mostrarCache();
        }
    } while (choice != 4);

    cout << "Saliendo del programa.\n";
}

int main() {
    //menu();
    int capacity;
    cout << "Ingrese la capacidad de la cache: ";
    cin >> capacity;
    LFUCache cache(capacity);

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