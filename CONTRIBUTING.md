# 🤝 Guide de Contribution

Merci de votre intérêt pour ChainMaster Pro!

## 📋 Standards de Code

### Style C
- Utiliser les conventions de nommage cohérentes
- Indentation: 4 espaces (pas de tabs)
- Accolades style K&R
- Commentaires en français ou anglais

### Exemple de Code Bien Formaté
```c
// Insertion triée dans une liste
Node* insert_sorted(Node* head, int value) {
    Node* new_node = (Node*)malloc(sizeof(Node));
    if (!new_node) return head;
    
    new_node->data = value;
    // ... reste du code
    return head;
}
```

## 🧪 Tests

- Chaque nouvelle fonctionnalité doit avoir des tests
- Exécuter `make test-all` avant de commiter
- Vérifier les fuites mémoire avec `make check-memory`

## 📝 Documentation

- Documenter toutes les fonctions publiques
- Mettre à jour API_REFERENCE.md
- Ajouter des exemples d'utilisation

## 🔄 Workflow Git

1. Fork le projet
2. Créer une branche feature (`git checkout -b feature/nouvelle-fonction`)
3. Commit les changements (`git commit -m 'Ajout nouvelle fonction'`)
4. Push vers la branche (`git push origin feature/nouvelle-fonction`)
5. Créer une Pull Request

## ✅ Checklist Avant Soumission

- [ ] Code compile sans warnings (`make all`)
- [ ] Tests passent (`make test-all`)
- [ ] Documentation à jour
- [ ] Pas de fuites mémoire
- [ ] Code bien formaté

## 📞 Contact

Pour toute question, contactez l'équipe de développement via le repository GitHub.

---

**Merci de contribuer à ChainMaster Pro! 🚀**
