#include <iostream>
#include <unordered_map>
#include <cmath>
#include <climits>
#include <vector>
using namespace std;

struct FiboNode {
    int key, frequency;
    FiboNode *parent, *child, *left, *right;
    bool marked;
    int degree;

    FiboNode(int key, int frequency) 
        : key(key), frequency(frequency), parent(nullptr), child(nullptr), 
          left(this), right(this), marked(false), degree(0) {}
};

class FibonacciHeap {
private:
    FiboNode* min;
    int nodeCount;

public:
    FibonacciHeap() : min(nullptr), nodeCount(0) {}

    FiboNode* insert(int key, int frequency) {
        FiboNode* node = new FiboNode(key, frequency);
        if (!min) {
            min = node;
        } else {
            // Insertar nodo en la lista raíz
            node->right = min->right;
            min->right->left = node;
            min->right = node;
            node->left = min;
            if (node->frequency < min->frequency) min = node;
        }
        nodeCount++;
        return node;
    }

    FiboNode* extractMin() {
        if (!min) return nullptr;
        FiboNode* extracted = min;

        // Mover hijos de min al nivel superior
        if (min->child) {
            FiboNode* child = min->child;
            do {
                child->parent = nullptr;
                child = child->right;
            } while (child != min->child);
        }

        // Quitar min de la lista raíz
        if (extracted == extracted->right) {
            min = nullptr;
        } else {
            min->left->right = min->right;
            min->right->left = min->left;
            min = min->right;
            consolidate();
        }
        nodeCount--;
        return extracted;
    }

    void decreaseKey(FiboNode* node, int newFrequency) {
        if (newFrequency >= node->frequency) return;

        node->frequency = newFrequency;
        FiboNode* parent = node->parent;

        if (parent && node->frequency < parent->frequency) {
            cut(node, parent);
            cascadingCut(parent);
        }

        if (node->frequency < min->frequency) min = node;
    }

private:
    void consolidate() {
        int maxDegree = static_cast<int>(log2(nodeCount)) + 1;
        vector<FiboNode*> degreeTable(maxDegree, nullptr);

        vector<FiboNode*> rootNodes;
        FiboNode* current = min;
        if (current) {
            do {
                rootNodes.push_back(current);
                current = current->right;
            } while (current != min);
        }

        for (FiboNode* node : rootNodes) {
            int degree = node->degree;
            while (degreeTable[degree]) {
                FiboNode* other = degreeTable[degree];
                if (node->frequency > other->frequency) swap(node, other);
                link(other, node);
                degreeTable[degree] = nullptr;
                degree++;
            }
            degreeTable[degree] = node;
        }

        min = nullptr;
        for (FiboNode* node : degreeTable) {
            if (node) {
                if (!min) {
                    min = node;
                } else {
                    node->right = min->right;
                    min->right->left = node;
                    min->right = node;
                    node->left = min;
                    if (node->frequency < min->frequency) min = node;
                }
            }
        }
    }

    void link(FiboNode* y, FiboNode* x) {
        y->left->right = y->right;
        y->right->left = y->left;
        y->parent = x;

        if (!x->child) {
            x->child = y;
            y->right = y;
            y->left = y;
        } else {
            y->right = x->child->right;
            x->child->right->left = y;
            x->child->right = y;
            y->left = x->child;
        }
        x->degree++;
        y->marked = false;
    }

    void cut(FiboNode* child, FiboNode* parent) {
        if (parent->child == child) {
            if (child->right == child) {
                parent->child = nullptr;
            } else {
                parent->child = child->right;
            }
        }
        child->left->right = child->right;
        child->right->left = child->left;
        parent->degree--;

        child->right = min->right;
        min->right->left = child;
        min->right = child;
        child->left = min;
        child->parent = nullptr;
        child->marked = false;
    }

    void cascadingCut(FiboNode* node) {
        FiboNode* parent = node->parent;
        if (parent) {
            if (!node->marked) {
                node->marked = true;
            } else {
                cut(node, parent);
                cascadingCut(parent);
            }
        }
    }
};
