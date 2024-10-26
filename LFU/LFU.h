#include <iostream>
#include <unordered_map>
#include <cmath>
#include <climits>
#include "FibonacciHeap.h"
using namespace std;

class LFUCache {
private:
    unordered_map<int, pair<int, FiboNode*>> cache;
    unordered_map<int, FiboNode*> freqNodes;
    FibonacciHeap freqHeap;
    int capacity;

public:
    LFUCache(int capacity) : capacity(capacity) {}

    int get(int key) {
        if (cache.find(key) == cache.end()) return -1;
        pair<int, FiboNode*>& valNode = cache[key];
        int value = valNode.first;
        updateFrequency(key, valNode.second);
        return value;
    }

    void put(int key, int value) {
    if (capacity == 0) return;


    if (cache.find(key) != cache.end()) {
        cache[key].first = value;
        updateFrequency(key, cache[key].second);
    } else {
        if (cache.size() == capacity) {
            FiboNode* minNode = freqHeap.extractMin();
            if (minNode) {
                cache.erase(minNode->key);
                delete minNode;
            }
        }
        FiboNode* node = freqHeap.insert(key, 1);
        cache[key] = {value, node};
    }
}



    void mostrarCache() {
        cout << "\nElementos en la cache:\n";
        for (const auto& entry : cache) {
            int key = entry.first;
            int value = entry.second.first;
            int frequency = entry.second.second->frequency;
            cout << "Clave: " << key << ", Valor: " << value << ", Frecuencia: " << frequency << endl;
        }
    }

private:
void updateFrequency(int key, FiboNode* node) {
    int newFreq = node->frequency + 1;
    node->frequency = newFreq;
    freqHeap.decreaseKey(node, newFreq);
}

};
