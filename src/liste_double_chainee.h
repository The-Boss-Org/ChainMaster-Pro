#ifndef LISTE_DOUBLE_CHAINEE_H
#define LISTE_DOUBLE_CHAINEE_H

typedef struct DNode {
    int data;
    struct DNode *prev;
    struct DNode *next;
} DNode;

// Fonctions
DNode* createNode(int value);
void insertSorted(DNode **head, int value);
void printList(DNode* head);
void buildList(DNode **head);

#endif
