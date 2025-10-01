#  Rapport - Exercice 2
## Insertion Triée dans une Liste Simplement Chaînée

---

##  Informations Générales

| Item | Détail |
|------|--------|
| **Exercice** | 2 |
| **Titre** | Insertion d'un élément dans une liste simplement chaînée triée |
| **Type de liste** | Liste simplement chaînée |
| **Responsable** | VAMI NEGUEM YVO FREED (24F2658) |
| **Statut** | ✅ Complété et testé |
| **Date** | 25 septembre 2025 |

---

##  Objectif de l'Exercice

Implémenter une fonction qui insère un nouvel élément dans une liste simplement chaînée tout en **maintenant l'ordre croissant** de la liste.

---

##  Implémentation

### Fichier Source
**Emplacement**: `src/core/list_simple.c`

### Fonction Principale
```c
SNode* sll_insert_sorted(SNode* head, int value)
```

### Code Complet
```c
// Insertion triée croissante dans une liste simplement chaînée
SNode* sll_insert_sorted(SNode* head, int value) {
    SNode* node = (SNode*)malloc(sizeof(SNode));
    if (!node) return head; // allocation échouée
    node->data = value;
    node->next = NULL;

    if (!head || value <= head->data) {
        node->next = head;
        return node;
    }
    
    SNode* cur = head;
    while (cur->next && cur->next->data < value) {
        cur = cur->next;
    }
    node->next = cur->next;
    cur->next = node;
    return head;
}
```

---

##  Analyse de l'Algorithme

### Étapes de l'Algorithme

1. **Création du nœud**
   - Allouer mémoire pour nouveau nœud
   - Vérifier succès de l'allocation
   - Initialiser `data` et `next`

2. **Cas spécial: Insertion en tête**
   - Si liste vide OU valeur ≤ tête
   - Pointer nouveau nœud vers ancienne tête
   - Retourner nouveau nœud comme nouvelle tête

3. **Cas général: Trouver la position**
   - Parcourir avec `cur`
   - S'arrêter quand `cur->next->data >= value`
   - Insérer entre `cur` et `cur->next`

4. **Insertion**
   - `node->next = cur->next`
   - `cur->next = node`

### Invariant
**À tout moment, la liste reste triée en ordre croissant**

---

##  Cas de Figures

| Cas | État Initial | Valeur | État Final |
|-----|-------------|--------|------------|
| **Liste vide** | `NULL` | 5 | `5->NULL` |
| **Insert en tête** | `5->7->NULL` | 3 | `3->5->7->NULL` |
| **Insert au milieu** | `3->7->NULL` | 5 | `3->5->7->NULL` |
| **Insert en queue** | `3->5->NULL` | 7 | `3->5->7->NULL` |
| **Doublons** | `3->5->NULL` | 5 | `3->5->5->NULL` |

---

##  Analyse de Complexité

### Complexité Temporelle

| Opération | Complexité | Explication |
|-----------|------------|-------------|
| **Meilleur cas** | O(1) | Insertion en tête |
| **Cas moyen** | O(n/2) = O(n) | Insertion au milieu |
| **Pire cas** | O(n) | Insertion en queue |

### Complexité Spatiale
- **O(1)** - Un seul nœud alloué par insertion
- Espace constant pour les variables temporaires

### Nombre d'Opérations (n éléments)
- **Comparaisons**: Entre 1 et n
- **Allocations**: Exactement 1
- **Assignations de pointeurs**: 2 à 3

---

##  Tests Unitaires

### Test 1: Liste Vide
```c
TEST(test_sll_insert_sorted_empty) {
    SNode* list = NULL;
    list = sll_insert_sorted(list, 10);
    ASSERT(list != NULL && list->data == 10, 
           "Insert in empty list");
}
```
**Résultat**: ✅ PASS

### Test 2: Maintien de l'Ordre
```c
TEST(test_sll_insert_sorted_order) {
    SNode* list = NULL;
    list = sll_insert_sorted(list, 5);
    list = sll_insert_sorted(list, 2);
    list = sll_insert_sorted(list, 8);
    ASSERT(list->data == 2 && list->next->data == 5, 
           "Should maintain order");
}
```
**Résultat**: ✅ PASS

### Taux de Réussite
**2/2 tests passés (100%)**

---

##  Exemple d'Exécution Détaillé

### Scénario: Construction d'une Liste Triée

**Séquence d'insertions**: 15, 3, 9, 1, 12, 6

#### Étape 1: Insérer 15
```
Liste: NULL
Action: Insertion en tête (liste vide)
Résultat: 15->NULL
```

#### Étape 2: Insérer 3
```
Liste: 15->NULL
Action: 3 < 15, insertion en tête
Résultat: 3->15->NULL
```

#### Étape 3: Insérer 9
```
Liste: 3->15->NULL
Action: 3 < 9 < 15, insertion entre 3 et 15
Processus:
  - cur = 3
  - 3->next (15) >= 9, stop
  - Insérer 9 après 3
Résultat: 3->9->15->NULL
```

#### Étape 4: Insérer 1
```
Liste: 3->9->15->NULL
Action: 1 < 3, insertion en tête
Résultat: 1->3->9->15->NULL
```

#### Étape 5: Insérer 12
```
Liste: 1->3->9->15->NULL
Action: 9 < 12 < 15, insertion entre 9 et 15
Résultat: 1->3->9->12->15->NULL
```

#### Étape 6: Insérer 6
```
Liste: 1->3->9->12->15->NULL
Action: 3 < 6 < 9, insertion entre 3 et 9
Résultat: 1->3->6->9->12->15->NULL
```

### Liste Finale
```
1 -> 3 -> 6 -> 9 -> 12 -> 15 -> NULL
```
✅ **Ordre croissant maintenu**

---

##  Gestion de la Mémoire

### Allocation
```c
SNode* node = (SNode*)malloc(sizeof(SNode));
if (!node) return head;  // Échec d'allocation géré
```

### Points de Vigilance
1. ✅ Vérification du retour de `malloc`
2. ✅ Initialisation complète du nœud
3. ✅ Pas de fuite mémoire

### Vérification Valgrind
```bash
valgrind --leak-check=full ./demo_all
```
**Résultat**: ✅ All heap blocks were freed -- no leaks are possible

---

##  Comparaison: Insertion Triée vs Insertion + Tri

### Méthode 1: Insertion Triée (Notre Approche)
```
Insertions successives: O(n) × n = O(n²)
Avantage: Liste toujours triée
```

### Méthode 2: Insertion Simple + Tri Final
```
Insertions: O(1) × n = O(n)
Tri (merge sort): O(n log n)
Total: O(n + n log n) = O(n log n)
```

### Quand Utiliser l'Insertion Triée?
- ✅ Insertions peu fréquentes
- ✅ Besoin de liste triée en permanence
- ✅ Recherche fréquente (dichotomie impossible mais ordre utile)

---

##  Optimisations et Variantes

### Optimisation 1: Pointeur de Queue
```c
// Si on maintient un pointeur tail
if (value >= tail->data) {
    tail->next = node;
    tail = node;
    return head;  // O(1) pour insertion en queue
}
```

### Variante 1: Ordre Décroissant
```c
// Changer la condition de comparaison
while (cur->next && cur->next->data > value) {
    cur = cur->next;
}
```

### Variante 2: Éviter les Doublons
```c
// Ajouter une vérification
if (cur->next && cur->next->data == value) {
    free(node);
    return head;  // Ne pas insérer si déjà présent
}
```

---

## 🎓 Concepts Appliqués

### Structures de Données
- Liste chaînée simple
- Tri par insertion
- Invariants de structure

### Algorithmes
- Recherche séquentielle
- Insertion en place
- Maintien d'ordre

### Techniques de Programmation
- Manipulation de pointeurs
- Gestion de cas limites
- Allocation dynamique

---

## 📚 Applications Pratiques

### Cas d'Usage
1. **File de priorité simple**
2. **Historique chronologique**
3. **Liste de tâches par priorité**
4. **Fusion de flux de données triés**

### Exemple Réel
```c
// Système de gestion de tâches
typedef struct Task {
    int priority;
    struct Task* next;
} Task;

Task* add_task(Task* tasks, int priority) {
    return sll_insert_sorted(tasks, priority);
}
```

---

## ⚠️ Limitations

### Points Faibles
1. ❌ Pas d'accès direct aux éléments (O(n))
2. ❌ Insertion en O(n) dans le pire cas
3. ❌ Pas de navigation arrière

### Solutions Alternatives
- **Liste doublement chaînée**: Navigation bidirectionnelle
- **Arbre binaire de recherche**: Insertion/recherche en O(log n)
- **Tas**: File de priorité en O(log n)

---

## ✅ Conclusion

L'exercice 2 démontre la **maîtrise de l'insertion triée**:

- ✅ Algorithme correct et efficace
- ✅ Ordre maintenu après chaque insertion
- ✅ Gestion robuste de tous les cas
- ✅ Complexité O(n) respectée
- ✅ Tests unitaires validés (2/2)
- ✅ Code propre et documenté

### Points Forts
- Simplicité de l'implémentation
- Robustesse face aux cas limites
- Gestion mémoire sans fuites

### Apprentissages
- Importance de l'invariant de structure
- Gestion des pointeurs en C
- Trade-off performance vs simplicité

**Statut Final**: ✅ **VALIDÉ**

---

**Auteur**: VAMI NEGUEM YVO FREED (24F2658)  
**Cours**: INF 231 - Prof. Melatagia  
**Date de Validation**: 1er octobre 2025
