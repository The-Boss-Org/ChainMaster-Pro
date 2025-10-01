
#include <stdio.h>
#include <stdlib.h>
#include "../../include/interfaces.h"

int main() {
    Node* liste = NULL;
    int choix, valeur;

    do {
        printf("\n--- MENU DU TP ---\n");
        printf("1. Créer une nouvelle liste\n");
        printf("2. Insérer en tête\n");
        printf("3. Insérer en queue\n");
        printf("4. Afficher la liste\n");
        printf("0. Quitter\n");
        printf("Votre choix : ");
        scanf("%d", &choix);
        switch (choix) {
            case 1:
                liste = creer_liste();
                printf("Liste créée.\n");
                break;
            case 2:
                printf("Entrez la valeur à insérer en tête : ");
                scanf("%d", &valeur);
                liste = inserer_tete(liste, valeur);
                printf("Valeur insérée en tête.\n");
                break;
            case 3:
                printf("Entrez la valeur à insérer en queue : ");
                scanf("%d", &valeur);
                liste = inserer_queue(liste, valeur);
                printf("Valeur insérée en queue.\n");
                break;
            case 4:
                printf("Contenu de la liste : ");
                afficher_liste(liste);
                break;
            case 0:
                printf("Au revoir !\n");
                break;
            default:
                printf("Choix invalide.\n");
        }
    } while (choix != 0);
    return 0;
}
