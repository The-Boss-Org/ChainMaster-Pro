#ifndef STRUCTURES_H
#define STRUCTURES_H

#include <stddef.h>

// Liste simplement chaînée (utilisée aussi pour la circulaire simple)
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Liste doublement chaînée (utilisée aussi pour la circulaire double)
typedef struct DNode {
    int data;
    struct DNode* prev;
    struct DNode* next;
} DNode;

#endif // STRUCTURES_H
