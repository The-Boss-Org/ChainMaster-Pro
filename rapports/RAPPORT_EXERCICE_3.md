#  Rapport - Exercice 3
## Insertion Triée dans une Liste Doublement Chaînée

---

##  Informations Générales

| Item | Détail |
|------|--------|
| **Exercice** | 3 |
| **Titre** | Insertion d'un élément dans une liste doublement chaînée triée |
| **Type de liste** | Liste doublement chaînée |
| **Responsable** | FOKOU FOFOU STEDDY RONEL (24G2255) |
| **Statut** | ✅ Complété et testé |
| **Date** | 25 septembre 2025 |

---

##  Objectif de l'Exercice

Implémenter une fonction qui insère un élément dans une liste doublement chaînée tout en maintenant l'ordre croissant et en gérant **deux pointeurs** (prev et next) pour chaque nœud.

---

##  Implémentation

### Fichier Source
**Emplacement**: `src/core/list_double.c`

### Structure de Données
```c
typedef struct DNode {
    int data;
    struct DNode* prev;  // Pointeur vers le précédent
    struct DNode* next;  // Pointeur vers le suivant
} DNode;
```

### Fonction Principale
```c
DList* dll_insert_sorted(DList* head, int value)
```

### Code Complet
```c
// Insertion triée croissante dans une liste doublement chaînée
DList* dll_insert_sorted(DList* head, int value) {
    DList* node = (DList*)malloc(sizeof(DList));
    if (!node) return head;
    node->data = value;
    node->prev = node->next = NULL;

    if (!head) {
        return node;
    }
    
    if (value <= head->data) {
        node->next = head;
        head->prev = node;
        return node;
    }
    
    DList* cur = head;
    while (cur->next && cur->next->data < value) {
        cur = cur->next;
    }
    
    node->next = cur->next;
    if (cur->next) cur->next->prev = node;
    cur->next = node;
    node->prev = cur;
    return head;
}
```

---

##  Analyse de l'Algorithme

### Différence avec Liste Simple

| Aspect | Liste Simple | Liste Double |
|--------|-------------|--------------|
| **Pointeurs par nœud** | 1 (next) | 2 (prev, next) |
| **Navigation** | Unidirectionnelle → | Bidirectionnelle ↔ |
| **Insertion** | Ajuster 1 lien | Ajuster 2-4 liens |
| **Suppression** | O(n) chercher prédécesseur | O(1) avec référence |
| **Mémoire** | ~8 bytes/nœud | ~16 bytes/nœud |

### Étapes de l'Algorithme

1. **Allocation et initialisation**
   ```c
   DList* node = malloc(sizeof(DList));
   node->data = value;
   node->prev = node->next = NULL;
   ```

2. **Cas 1: Liste vide**
   ```c
   if (!head) return node;
   ```

3. **Cas 2: Insertion en tête**
   ```c
   if (value <= head->data) {
       node->next = head;    // Lier vers avant
       head->prev = node;    // Lier vers arrière
       return node;          // Nouvelle tête
   }
   ```

4. **Cas 3: Trouver la position**
   ```c
   while (cur->next && cur->next->data < value) {
       cur = cur->next;
   }
   ```

5. **Cas 4: Insérer entre cur et cur->next**
   ```c
   node->next = cur->next;              // 1. Lier nouveau vers avant
   if (cur->next) cur->next->prev = node;  // 2. Ancien next vers nouveau
   cur->next = node;                    // 3. cur vers nouveau
   node->prev = cur;                    // 4. Nouveau vers cur
   ```

### Invariants Maintenus
1. ✅ **Ordre croissant** préservé
2. ✅ **Double liaison** cohérente: `a->next->prev == a`
3. ✅ **Symétrie** des pointeurs

---

##  Visualisation des Insertions

### Cas 1: Insertion en Tête
```
Avant:     NULL <- [5|prev|next] <-> [10|prev|next] -> NULL
Insert 3:  
Après:     NULL <- [3] <-> [5] <-> [10] -> NULL
           
Liens créés:
  3->next = 5
  5->prev = 3
```

### Cas 2: Insertion au Milieu
```
Avant:     NULL <- [3] <-> [10] -> NULL
Insert 7:
Processus:
  1. cur = 3
  2. cur->next (10) >= 7, stop
  3. Insérer 7 entre 3 et 10

Après:     NULL <- [3] <-> [7] <-> [10] -> NULL

Liens créés:
  7->next = 10
  10->prev = 7
  3->next = 7
  7->prev = 3
```

### Cas 3: Insertion en Queue
```
Avant:     NULL <- [3] <-> [7] -> NULL
Insert 10:
Après:     NULL <- [3] <-> [7] <-> [10] -> NULL

Liens créés:
  10->next = NULL
  7->next = 10
  10->prev = 7
```

---

##  Analyse de Complexité

### Complexité Temporelle

| Opération | Simple | Double | Gain |
|-----------|--------|--------|------|
| **Insert en tête** | O(1) | O(1) | = |
| **Insert milieu** | O(n) | O(n) | = |
| **Insert en queue** | O(n) | O(n) ou O(1)* | ✓ |
| **Supprimer nœud** | O(n) | O(1)** | ✓✓ |
| **Parcours arrière** | Impossible | O(n) | ✓✓✓ |

\* Avec pointeur tail maintenu  
** Avec référence directe au nœud

### Complexité Spatiale
- **Stockage**: O(n) avec n nœuds × 16 bytes
- **Temporaire**: O(1) - quelques pointeurs

---

##  Tests Unitaires

### Test 1: Liste Vide
```c
TEST(test_dll_insert_sorted_empty) {
    DList* list = NULL;
    list = dll_insert_sorted(list, 10);
    ASSERT(list != NULL && list->data == 10, 
           "DLL insert in empty");
}
```
**Résultat**: ✅ PASS

### Test 2: Maintien de l'Ordre
```c
TEST(test_dll_insert_sorted_order) {
    DList* list = NULL;
    list = dll_insert_sorted(list, 5);
    list = dll_insert_sorted(list, 2);
    ASSERT(list->data == 2 && list->next->data == 5, 
           "DLL should maintain order");
}
```
**Résultat**: ✅ PASS

### Test 3: Cohérence des Liens (Manuel)
```c
DList* list = NULL;
list = dll_insert_sorted(list, 5);
list = dll_insert_sorted(list, 2);
list = dll_insert_sorted(list, 8);

// Vérifier symétrie
assert(list->next->prev == list);  // 2->5->prev == 2
assert(list->next->next->prev == list->next);  // 5->8->prev == 5
```
**Résultat**: ✅ PASS

### Taux de Réussite
**2/2 tests automatiques + vérifications manuelles (100%)**

---

## 🎬 Exemple d'Exécution Complète

### Construction Étape par Étape

**Séquence**: Insérer 10, 5, 15, 2, 12

#### État 1: Insérer 10
```
Liste: NULL <- [10] -> NULL
Liens: prev=NULL, next=NULL
```

#### État 2: Insérer 5
```
Liste: NULL <- [5] <-> [10] -> NULL
Liens créés:
  5->next = 10, 5->prev = NULL
  10->prev = 5, 10->next = NULL
```

#### État 3: Insérer 15
```
Liste: NULL <- [5] <-> [10] <-> [15] -> NULL
Liens créés:
  15->prev = 10, 15->next = NULL
  10->next = 15
```

#### État 4: Insérer 2
```
Liste: NULL <- [2] <-> [5] <-> [10] <-> [15] -> NULL
Liens créés:
  2->next = 5, 2->prev = NULL
  5->prev = 2
```

#### État 5: Insérer 12
```
Liste: NULL <- [2] <-> [5] <-> [10] <-> [12] <-> [15] -> NULL
Liens créés:
  12->prev = 10, 12->next = 15
  10->next = 12
  15->prev = 12
```

### Vérification de Cohérence
```
Parcours avant:  2 -> 5 -> 10 -> 12 -> 15 ✅
Parcours arrière: 15 -> 12 -> 10 -> 5 -> 2 ✅
Symétrie: ∀ nœud n, n->next->prev == n ✅
```

---

## 🔧 Gestion de la Mémoire

### Allocation
```c
DList* node = (DList*)malloc(sizeof(DList));
if (!node) return head;  // Gestion d'échec
```

### Initialisation Complète
```c
node->data = value;
node->prev = NULL;  // Important!
node->next = NULL;  // Important!
```

### Points Critiques
1. ✅ Toujours initialiser `prev` et `next`
2. ✅ Vérifier `cur->next` avant `cur->next->prev`
3. ✅ Maintenir symétrie des liens

---

## 💡 Avantages de la Double Liaison

### 1. Suppression Efficace
```c
// Avec liste simple: O(n) pour trouver prédécesseur
// Avec liste double: O(1) si on a la référence

void dll_delete_node(DList** head, DList* node) {
    if (node->prev) {
        node->prev->next = node->next;
    } else {
        *head = node->next;  // Suppression de tête
    }
    if (node->next) {
        node->next->prev = node->prev;
    }
    free(node);  // O(1) !
}
```

### 2. Navigation Bidirectionnelle
```c
// Parcours arrière possible
DList* tail = head;
while (tail->next) tail = tail->next;

while (tail) {
    printf("%d ", tail->data);
    tail = tail->prev;  // ← Impossible en simple!
}
```

### 3. Insertion avant un Nœud
```c
// En simple: O(n) pour trouver prédécesseur
// En double: O(1) direct
void insert_before(DList* node, int value) {
    DList* new = create_node(value);
    new->next = node;
    new->prev = node->prev;
    if (node->prev) node->prev->next = new;
    node->prev = new;
}
```

---

## ⚠️ Pièges Courants

### Piège 1: Oublier de Mettre à Jour prev
```c
// ❌ MAUVAIS
cur->next = node;
node->next = cur->next;  // prev oublié!

// ✅ BON
node->next = cur->next;
if (cur->next) cur->next->prev = node;
cur->next = node;
node->prev = cur;
```

### Piège 2: Ordre des Opérations
```c
// ❌ MAUVAIS - Perte de référence
cur->next = node;  // On perd cur->next original!
node->next = cur->next;  // Pointe vers node lui-même!

// ✅ BON - Sauvegarder d'abord
node->next = cur->next;  // Sauvegarder la référence
cur->next = node;         // Puis modifier
```

### Piège 3: NULL Dereference
```c
// ❌ MAUVAIS
cur->next->prev = node;  // Crash si cur->next == NULL

// ✅ BON
if (cur->next) cur->next->prev = node;
```

---

##  Applications Pratiques

### Cas d'Usage Idéaux
1. **Éditeur de texte** (undo/redo)
2. **Historique de navigation** (avant/arrière)
3. **LRU Cache** (Least Recently Used)
4. **Playlist musicale** (précédent/suivant)

### Exemple: LRU Cache
```c
typedef struct CacheNode {
    int key;
    int value;
    struct CacheNode *prev, *next;
} CacheNode;

// Déplacer en tête (le plus récent)
void move_to_head(CacheNode** head, CacheNode* node) {
    // Retirer de position actuelle
    if (node->prev) node->prev->next = node->next;
    if (node->next) node->next->prev = node->prev;
    
    // Mettre en tête
    node->next = *head;
    node->prev = NULL;
    if (*head) (*head)->prev = node;
    *head = node;
}
```

---

## 🎓 Concepts Appliqués

### Structures de Données
- Liste doublement chaînée
- Maintien d'invariants multiples
- Gestion de symétrie

### Algorithmes
- Insertion triée
- Manipulation de pointeurs bidirectionnels
- Maintien de cohérence

### Techniques Avancées
- Gestion de cas multiples
- Vérification de NULL
- Ordre des opérations crucial

---

## ✅ Conclusion

L'exercice 3 démontre la **maîtrise des listes doublement chaînées**:

- ✅ Double liaison correctement gérée
- ✅ Symétrie des pointeurs maintenue
- ✅ Ordre croissant préservé
- ✅ Tous les cas limites gérés
- ✅ Tests validés (2/2)
- ✅ Complexité O(n) respectée

### Comparaison avec Exercice 2

| Aspect | Ex. 2 (Simple) | Ex. 3 (Double) |
|--------|---------------|----------------|
| **Complexité insert** | O(n) | O(n) |
| **Liens à gérer** | 1 | 2-4 |
| **Navigation arrière** | ❌ | ✅ |
| **Suppression** | O(n) | O(1)* |
| **Mémoire** | Moins | Plus |

\* Avec référence au nœud

### Points Forts
- Navigation bidirectionnelle
- Suppression efficace
- Applications riches

### Apprentissages
- Importance de l'ordre des opérations
- Gestion de la symétrie
- Trade-off mémoire vs fonctionnalité

**Statut Final**: ✅ **VALIDÉ**

---

**Auteur**: FOKOU FOFOU STEDDY RONEL (24G2255)  
**Cours**: INF 231 - Prof. Melatagia  
**Date de Validation**: 1er octobre 2025
