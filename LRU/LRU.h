#include <unordered_map>
#include <iostream>
#include"ListDouble.h"


class LRUCache {
    int capacity;
    std::unordered_map<int, Node*> cache; 
    ListDouble* dll; 

public:
    LRUCache(int cap) : capacity(cap) {
        dll = new ListDouble();
    }

    int get(int key) {
        if (cache.find(key) == cache.end()) {
            return -1;
        }
        Node* node = cache[key];
        dll->removeNode(node); 
        dll->addNode(node);    
        return node->value;
    }

    void put(int key, int value) {
        if (cache.find(key) != cache.end()) {
            Node* node = cache[key];
            node->value = value;
            dll->removeNode(node);
            dll->addNode(node);
        } else {
            if (cache.size() >= capacity) {
                Node* lastNode = dll->removeLastNode();
                cache.erase(lastNode->key);
                delete lastNode;
            }
            Node* newNode = new Node(key, value);
            dll->addNode(newNode);
            cache[key] = newNode;
        }
    }
    void mostrarCache() {
        std::cout << "Contenido de la cache " << std::endl;
        dll->ViewList();
    }

};

