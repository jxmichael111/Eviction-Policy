#include <iostream>
struct Node {
    int key;
    int value;
    Node* prev;
    Node* next;
    
    Node(int k, int v) : key(k), value(v), prev(nullptr), next(nullptr) {}
};

class ListDouble {
public:
    Node* head; 
    Node* tail; 

    ListDouble() {
        head = new Node(0, 0);
        tail = new Node(0, 0);
        head->next = tail;
        tail->prev = head;
    }

    void addNode(Node* node) {
        node->next = head->next;
        node->prev = head;
        head->next->prev = node;
        head->next = node;
    }


    void removeNode(Node* node) {
        Node* prevNode = node->prev;
        Node* nextNode = node->next;
        prevNode->next = nextNode;
        nextNode->prev = prevNode;
    }

    Node* removeLastNode() {
        if (tail->prev == head) return nullptr;
        Node* lastNode = tail->prev;
        removeNode(lastNode);
        return lastNode;
    }

    void ViewList() {
        Node* current = head->next;
        while (current != tail) {
            std::cout << "[Clave: " << current->key << ", Valor: " << current->value << "] ";
            current = current->next;
            if (current != tail) { 
                std::cout << "-> ";
            }
        }
        std::cout << std::endl;
    }
};
