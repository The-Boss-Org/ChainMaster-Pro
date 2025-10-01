#ifndef INTERFACES_H
#define INTERFACES_H

#include <stdio.h>
#include <stdlib.h>

// Définition de la structure du nœud
typedef struct Node {
    int data;
    struct Node* next;
} Node;//node pour nœud

// Prototypes des fonctions pour la liste circulaire simplement chaînée
void afficher_liste(Node* head);
Node* creer_liste();
Node* inserer_tete(Node* head, int valeur);
Node* inserer_queue(Node* head, int valeur);

#endif // INTERFACES_H
