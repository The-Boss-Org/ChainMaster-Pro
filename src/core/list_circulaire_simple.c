#include <stdlib.h>
#include <stdio.h>
#include "../../include/interfaces.h"
#include "../../include/chainmaster.h"


// Définition de la structure du nœud

// Affichage de la liste circulaire
void afficher_liste(Node* head) {
	if (!head) {
		printf("Liste vide\n");
		return;
	}
	Node* temp = head;
	do {
		printf("%d ", temp->data);
		temp = temp->next;
	} while (temp != head);
	printf("\n");
}

// Création d'une nouvelle liste (retourne NULL)
Node* creer_liste() {
	return NULL;
}

// Insertion en tête
Node* inserer_tete(Node* head, int valeur) {
	Node* nouveau = (Node*)malloc(sizeof(Node));
	if (!nouveau) return head;
	nouveau->data = valeur;
	if (!head) {
		nouveau->next = nouveau;
		return nouveau;
	}
	Node* temp = head;
	while (temp->next != head) {
		temp = temp->next;
	}
	temp->next = nouveau;
	nouveau->next = head;
	return nouveau;
}

// Insertion en queue
Node* inserer_queue(Node* head, int valeur) {
	Node* nouveau = (Node*)malloc(sizeof(Node));
	if (!nouveau) return head;
	nouveau->data = valeur;
	if (!head) {
		nouveau->next = nouveau;
		return nouveau;
	}
	Node* temp = head;
	while (temp->next != head) {
		temp = temp->next;
	}
	temp->next = nouveau;
	nouveau->next = head;
	return head;
}

// === Wrappers conformes à chainmaster.h ===
Node* cll_create(void) { return creer_liste(); }
Node* cll_insert_head(Node* head, int value) { return inserer_tete(head, value); }
Node* cll_insert_tail(Node* head, int value) { return inserer_queue(head, value); }
void  cll_print(const Node* head) { afficher_liste((Node*)head); }
void  cll_free(Node* head) {
    if (!head) return;
    Node* cur = head->next;
    while (cur != head) {
        Node* nxt = cur->next;
        free(cur);
        cur = nxt;
    }
    free(head);
}
