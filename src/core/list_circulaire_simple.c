#include <stdlib.h>
#include <stdio.h>


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
typedef struct Node {
	int data;
	struct Node* next;
} Node;

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
