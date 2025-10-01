#include <stdio.h>
#include <stdlib.h>
#include "liste_double_chainee.h"

// Création d’un nouveau nœud
DNode* createNode(int value) {
    DNode* newNode = (DNode*)malloc(sizeof(DNode));
    if (newNode == NULL) {
        printf("Erreur d’allocation mémoire\n");
        exit(1);
    }
    newNode->data = value;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

// Insertion triée
void insertSorted(DNode **head, int value) {
    DNode* newNode = createNode(value);

    if (*head == NULL) { // liste vide
        *head = newNode;
        return;
    }

    if (value <= (*head)->data) { // insertion avant la tête
        newNode->next = *head;
        (*head)->prev = newNode;
        *head = newNode;
        return;
    }

    DNode* current = *head;
    while (current->next != NULL && current->next->data < value) {
        current = current->next;
    }

    newNode->next = current->next;
    if (current->next != NULL)
        current->next->prev = newNode;
    current->next = newNode;
    newNode->prev = current;
}

// Affichage
void printList(DNode* head) {
    DNode* temp = head;
    printf("Liste : ");
    while (temp != NULL) {
        printf("%d <-> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// Construction de la liste depuis l’utilisateur
void buildList(DNode **head) {
    int n, val;
    printf("Combien de valeurs voulez-vous insérer ? ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("Entrez la valeur %d : ", i + 1);
        scanf("%d", &val);
        insertSorted(head, val);
    }
}
