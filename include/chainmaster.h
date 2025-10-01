#ifndef CHAINMASTER_H
#define CHAINMASTER_H

#include <stdio.h>
#include <stdlib.h>
#include "structures.h"

// =====================
// Exercice 1 & 2: Liste simplement chaînée
// =====================
// Supprimer toutes les occurrences de 'key' dans la liste simple
typedef Node SNode; // alias for clarity
SNode* sll_delete_all(SNode* head, int key);
// Insertion triée croissante dans une liste simplement chaînée
SNode* sll_insert_sorted(SNode* head, int value);

// =====================
// Exercice 3: Liste doublement chaînée
// =====================
// Insertion triée croissante dans une liste doublement chaînée
typedef DNode DList;
DList* dll_insert_sorted(DList* head, int value);

// =====================
// Exercice 4: Liste simplement chaînée circulaire
// =====================
// On réutilise Node et des fonctions 
Node* cll_create(void);
Node* cll_insert_head(Node* head, int value);
Node* cll_insert_tail(Node* head, int value);
void  cll_print(const Node* head);
void  cll_free(Node* head);

// =====================
// Exercice 5: Liste doublement chaînée circulaire
// =====================
DNode* cdll_create(void);
DNode* cdll_insert_head(DNode* head, int value);
DNode* cdll_insert_tail(DNode* head, int value);
void   cdll_print_forward(const DNode* head);
void   cdll_print_backward(const DNode* head);
void   cdll_free(DNode* head);

#endif // CHAINMASTER_H
