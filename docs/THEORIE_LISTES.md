# 📘 Théorie des Listes Chaînées

## 🎯 Introduction aux Structures Linéaires

Les listes chaînées sont des structures de données dynamiques fondamentales en informatique, permettant une gestion flexible de collections d'éléments.

## 📚 Les Différents Types de Listes

### 1️⃣ Liste Simplement Chaînée

**Définition**: Chaque nœud contient une donnée et un pointeur vers le nœud suivant.

```
[data|next] -> [data|next] -> [data|next] -> NULL
```

**Structure en C**:
```c
typedef struct Node {
    int data;
    struct Node* next;
} Node;
```

**Avantages**:
- ✅ Insertion/suppression en tête en O(1)
- ✅ Taille dynamique (pas de limite fixe)
- ✅ Mémoire utilisée proportionnelle aux éléments

**Inconvénients**:
- ❌ Accès séquentiel uniquement (pas d'accès direct)
- ❌ Insertion/suppression en queue en O(n)
- ❌ Navigation unidirectionnelle

**Complexités**:
- Insertion en tête: O(1)
- Insertion en queue: O(n)
- Recherche: O(n)
- Suppression: O(n)

---

### 2️⃣ Liste Doublement Chaînée

**Définition**: Chaque nœud contient une donnée, un pointeur vers le suivant ET un vers le précédent.

```
NULL <- [prev|data|next] <-> [prev|data|next] <-> [prev|data|next] -> NULL
```

**Structure en C**:
```c
typedef struct DNode {
    int data;
    struct DNode* prev;
    struct DNode* next;
} DNode;
```

**Avantages**:
- ✅ Navigation bidirectionnelle
- ✅ Suppression d'un nœud donné en O(1)
- ✅ Insertion avant/après un nœud en O(1)

**Inconvénients**:
- ❌ Consommation mémoire double (2 pointeurs)
- ❌ Gestion plus complexe (maintenir 2 liens)

**Complexités**:
- Insertion en tête/queue: O(1) si on garde un pointeur tail
- Recherche: O(n)
- Suppression avec référence: O(1)

---

### 3️⃣ Liste Circulaire Simplement Chaînée

**Définition**: Le dernier nœud pointe vers le premier (pas de NULL).

```
     ┌──────────────────────────┐
     ↓                          |
[data|next] -> [data|next] -> [data|next]
```

**Caractéristiques**:
- Le dernier nœud a `next` pointant vers `head`
- Aucun pointeur NULL (sauf liste vide)
- Parcours infini possible

**Avantages**:
- ✅ Accès au dernier élément via head->prev (si circulaire)
- ✅ Utile pour files circulaires (round-robin)
- ✅ Pas de cas spécial début/fin

**Applications**:
- Gestion de tours de jeu
- Buffers circulaires
- Listes de lecture en boucle

---

### 4️⃣ Liste Circulaire Doublement Chaînée

**Définition**: Liste doublement chaînée où premier et dernier sont connectés.

```
     ┌─────────────────────────────────┐
     ↓                                 |
[prev|data|next] <-> [prev|data|next] <-> [prev|data|next]
     |                                 ↑
     └─────────────────────────────────┘
```

**Caractéristiques**:
- `head->prev` pointe vers le dernier nœud (tail)
- `tail->next` pointe vers le premier nœud (head)
- Navigation circulaire dans les deux sens

**Avantages**:
- ✅ Insertion en tête en O(1)
- ✅ Insertion en queue en O(1) (via head->prev)
- ✅ Navigation bidirectionnelle circulaire
- ✅ Pas de cas spécial NULL

**Complexités**:
- Insertion tête/queue: O(1)
- Recherche: O(n)
- Suppression: O(1) avec référence

---

## 🔄 Comparaison des Structures

| Opération | Simple | Double | Circ. Simple | Circ. Double |
|-----------|--------|--------|--------------|--------------|
| Insert Tête | O(1) | O(1) | O(1) | O(1) |
| Insert Queue | O(n) | O(1)* | O(n) | O(1) |
| Suppr. Tête | O(1) | O(1) | O(1) | O(1) |
| Suppr. Queue | O(n) | O(1)* | O(n) | O(1) |
| Recherche | O(n) | O(n) | O(n) | O(n) |
| Mémoire/nœud | 1 ptr | 2 ptr | 1 ptr | 2 ptr |

\* Avec pointeur tail maintenu

---

## 💡 Algorithmes Classiques

### Insertion Triée

**Principe**: Maintenir la liste ordonnée à chaque insertion.

**Algorithme**:
1. Si liste vide → créer nœud et retourner
2. Si valeur ≤ tête → insérer avant tête
3. Sinon parcourir jusqu'à trouver position
4. Insérer entre deux nœuds

**Pseudo-code**:
```
fonction insertion_triée(liste, valeur):
    nouveau = créer_nœud(valeur)
    si liste est vide:
        retourner nouveau
    si valeur ≤ liste.tête.data:
        nouveau.next = liste.tête
        retourner nouveau
    courant = liste.tête
    tant que courant.next ≠ NULL et courant.next.data < valeur:
        courant = courant.next
    nouveau.next = courant.next
    courant.next = nouveau
    retourner liste
```

---

### Suppression de Toutes les Occurrences

**Principe**: Parcourir la liste et supprimer tous les nœuds avec la valeur cible.

**Algorithme**:
1. Supprimer de la tête tant qu'elle matche
2. Parcourir et supprimer du milieu/fin
3. Libérer la mémoire des nœuds supprimés

**Complexité**: O(n) - un seul parcours

---

## 🎓 Quand Utiliser Quelle Structure?

### Liste Simple
- ✅ Pile (LIFO)
- ✅ File avec ajout en queue occasionnel
- ✅ Minimiser la mémoire

### Liste Double
- ✅ Navigation avant/arrière nécessaire
- ✅ Historique (undo/redo)
- ✅ LRU Cache

### Liste Circulaire Simple
- ✅ Files circulaires
- ✅ Round-robin scheduling
- ✅ Playlists en boucle

### Liste Circulaire Double
- ✅ Éditeurs de texte
- ✅ Buffers circulaires avancés
- ✅ Applications nécessitant O(1) partout

---

## 🔍 Pièges Courants et Solutions

### Piège 1: Fuites Mémoire
```c
// ❌ Mauvais
head = head->next;  // Perte du nœud!

// ✅ Bon
Node* tmp = head;
head = head->next;
free(tmp);
```

### Piège 2: Déréférencement NULL
```c
// ❌ Mauvais
if (head->next->data == 5)  // Crash si head ou head->next est NULL

// ✅ Bon
if (head && head->next && head->next->data == 5)
```

### Piège 3: Boucle Infinie dans Circulaire
```c
// ❌ Mauvais
while (cur != NULL)  // Jamais NULL en circulaire!

// ✅ Bon
Node* start = head;
do {
    // traitement
    cur = cur->next;
} while (cur != start);
```

---

## 📊 Analyse de Performance

### Complexités Spatiales
- Liste simple: O(n) avec n nœuds, chacun ~12 bytes
- Liste double: O(n) avec n nœuds, chacun ~16 bytes

### Optimisations
- Maintenir un pointeur tail pour O(1) en queue
- Utiliser sentinel nodes pour simplifier le code
- Cache locality: préférer tableaux si accès aléatoire fréquent

---

## 🎯 Exercices Pratiques

1. Inverser une liste simplement chaînée
2. Détecter un cycle dans une liste (Floyd's algorithm)
3. Fusionner deux listes triées
4. Trouver le milieu d'une liste (two pointers)
5. Implémenter une pile avec liste chaînée

---

**Maîtrisez ces concepts pour exceller en structures de données! 📚**
