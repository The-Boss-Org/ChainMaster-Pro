#ifndef INTERFACES_H
#define INTERFACES_H

#include <stdio.h>
#include <stdlib.h>
#include "structures.h"

// Prototypes des fonctions pour la liste circulaire simplement chaînée
void afficher_liste(Node* head);
Node* creer_liste();
Node* inserer_tete(Node* head, int valeur);
Node* inserer_queue(Node* head, int valeur);

#endif // INTERFACES_H
