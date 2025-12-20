# 🔄 Guide Complet du Workflow Git

## 📑 Table des Matières

1. [Configuration Initiale](#configuration-initiale)
2. [Structure des Branches](#structure-des-branches)
3. [Workflow Quotidien](#workflow-quotidien)
4. [Gestion des Conflits](#gestion-des-conflits)
5. [Pull Requests](#pull-requests)
6. [Bonnes Pratiques](#bonnes-pratiques)

---

## Configuration Initiale

### 1. Configuration Git (Une seule fois)

```bash
# Configurer votre identité
git config --global user.name "Votre Nom"
git config --global user.email "votre.email@example.com"

# Configurer l'éditeur (optionnel)
git config --global core.editor "code --wait"  # Pour VS Code
```

### 2. Cloner le Projet

```bash
# Cloner le dépôt
git clone https://github.com/zzAdji/Student-Management-System.git
cd Student-Management-System

# Vérifier les branches distantes
git branch -a
```

### 3. Configuration des Branches Locales

```bash
# Créer votre branche develop locale
git checkout -b develop origin/develop

# Revenir sur main
git checkout main
```

---

## Structure des Branches

### Hiérarchie des Branches

```
main (production - stable - à modifier uniquement pour les codes fiables)
  ↑
develop (intégration - développement actif)
  ↑
feature/* (fonctionnalités individuelles)
fix/* (corrections de bugs)
```

### Types de Branches

#### `main`
- **Usage** : Version stable et fonctionnelle
- **Protection** : Aucun commit direct autorisé
- **Merge depuis** : `develop` uniquement (après validation complète)

#### `develop`
- **Usage** : Branche de développement principal
- **Mise à jour** : Fusion des features terminées
- **Protection** : Commits directs déconseillés

#### `feature/*`
- **Usage** : Développement de nouvelles fonctionnalités
- **Nomenclature** : `feature/nom-fonctionnalite`
- **Exemples** :
  - `feature/menu-principal`
  - `feature/recherche-dichotomique`
  - `feature/tri-alphabetique`
  - `feature/calcul-age`
  - `feature/validation-donnees`

#### `fix/*`
- **Usage** : Correction de bugs
- **Nomenclature** : `fix/description-bug`
- **Exemples** :
  - `fix/segmentation-fault-recherche`
  - `fix/validation-date`

---

## Workflow Quotidien

### Démarrer une Nouvelle Tâche

```bash
# 1. Assurez-vous d'être sur develop
git checkout develop

# 2. Récupérez les dernières modifications
git pull origin develop

# 3. Créez votre branche de fonctionnalité
git checkout -b feature/nom-de-votre-feature

# Exemple concret
git checkout -b feature/menu-principal
```

### Travailler sur Votre Branche

```bash
# 1. Modifier vos fichiers dans votre éditeur

# 2. Vérifier les modifications
git status

# 3. Ajouter les fichiers modifiés
git add src/menu.c include/menu.h
# ou ajouter tous les fichiers
git add .

# 4. Commiter avec un message clair
git commit -m "feat(menu): ajout du menu principal avec 9 options"

# 5. Continuer à développer et commiter régulièrement
git add .
git commit -m "feat(menu): ajout validation choix utilisateur"
```

### Pousser Votre Travail

```bash
# Première fois (créer la branche distante)
git push -u origin feature/nom-de-votre-feature

# Pushs suivants
git push
```

### Mettre à Jour Votre Branche avec develop

```bash
# Si develop a évolué pendant votre développement
git checkout develop
git pull origin develop
git checkout feature/votre-feature
git merge develop

# Résoudre les conflits si nécessaire
# Puis
git push
```

---

## Gestion des Conflits

### Identifier un Conflit

Lors d'un `git merge` ou `git pull`, si vous voyez :

```
CONFLICT (content): Merge conflict in src/operations.c
Automatic merge failed; fix conflicts and then commit the result.
```

### Résoudre le Conflit

1. **Ouvrir le fichier en conflit**

```c
<<<<<<< HEAD
// Votre code
int fonction_a() {
    return 1;
}
=======
// Code de la branche mergée
int fonction_a() {
    return 2;
}
>>>>>>> develop
```

2. **Choisir la bonne version**

```c
// Version finale (gardez une seule version)
int fonction_a() {
    return 1;  // ou 2, ou une combinaison des deux
}
```

3. **Marquer comme résolu et commiter**

```bash
git add src/operations.c
git commit -m "fix: résolution conflit merge develop"
git push
```

---

## Pull Requests

### Créer une Pull Request

1. **Sur GitHub** : Cliquez sur "New Pull Request"

2. **Configuration** :
   - **Base** : `develop`
   - **Compare** : `feature/votre-feature`

3. **Remplir le Template** :

```markdown
## Description
Ajout de la fonctionnalité de recherche dichotomique pour les étudiants.

## Type de Changement
- [x] Nouvelle fonctionnalité
- [ ] Correction de bug
- [ ] Documentation

## Modifications
- Ajout de la fonction `recherche_dichotomique()`
- Modification du menu pour intégrer l'option 6
- Tests effectués sur 100 étudiants

## Tests Effectués
- [x] Compilation sans erreurs
- [x] Tests avec liste triée
- [x] Tests avec liste vide
- [x] Tests cas limites

## Checklist
- [x] Code commenté
- [x] Respecte les conventions
- [x] Documentation mise à jour
- [x] Pas de warnings de compilation
```

### Processus de Revue

1. **Assignez des reviewers** (au moins 2 membres)
2. **Attendez les retours**
3. **Intégrez les suggestions**
4. **Re-push** les modifications
5. **Attendez l'approbation finale**
6. **Merge** (par le chef de projet ou responsable)

### Après le Merge

```bash
# Supprimer votre branche locale
git checkout develop
git branch -d feature/votre-feature

# Supprimer la branche distante (si nécessaire)
git push origin --delete feature/votre-feature

# Mettre à jour develop
git pull origin develop
```

---

## Bonnes Pratiques

### Convention de Nommage des Commits

**Format** : `type(scope): description`

#### Types

- `feat` : Nouvelle fonctionnalité
- `fix` : Correction de bug
- `docs` : Documentation uniquement
- `style` : Formatage (pas de changement de code)
- `refactor` : Refactorisation
- `test` : Ajout/modification de tests
- `chore` : Maintenance (build, config, etc.)

#### Exemples Concrets

```bash
# Bonnes pratiques ✅
git commit -m "feat(etudiant): ajout structure Gestion_des_Etudians"
git commit -m "feat(menu): implémentation menu avec 9 options"
git commit -m "fix(recherche): correction segfault recherche matricule"
git commit -m "docs(readme): ajout section installation"
git commit -m "refactor(tri): optimisation algorithme tri alphabétique"
git commit -m "test(operations): ajout tests CRUD"

# Mauvaises pratiques ❌
git commit -m "update"
git commit -m "fix bug"
git commit -m "modifications"
git commit -m "ça marche maintenant"
```

### Commits Atomiques

**Principe** : Un commit = Une modification logique

```bash
# Mauvais : Tout en un commit
git add .
git commit -m "ajout menu, recherche et tri"

# Bon : Commits séparés
git add src/menu.c include/menu.h
git commit -m "feat(menu): ajout menu principal"

git add src/recherche.c include/recherche.h
git commit -m "feat(recherche): ajout recherche par matricule"

git add src/tri.c include/tri.h
git commit -m "feat(tri): ajout tri alphabétique"
```

### Fréquence des Commits

- **Commit souvent** : Chaque fonctionnalité complétée
- **Push régulièrement** : Au moins une fois par jour
- **Ne pas attendre** : Ne gardez pas de code non versionné longtemps

### Messages de Commit Descriptifs

```bash
# Trop vague ❌
git commit -m "fix"

# Beaucoup mieux ✅
git commit -m "fix(validation): ajout validation format date JJ/MM/AAAA"
```

---

## Scénarios Pratiques

### Scénario 1 : Démarrer une Feature

```bash
git checkout develop
git pull origin develop
git checkout -b feature/affichage-liste
# ... développement ...
git add src/operations.c
git commit -m "feat(affichage): ajout fonction afficher_tous_etudiants"
git push -u origin feature/affichage-liste
# Créer PR sur GitHub
```

### Scénario 2 : Corriger un Bug Urgent

```bash
git checkout develop
git pull origin develop
git checkout -b fix/validation-matricule
# ... correction ...
git add src/validation.c
git commit -m "fix(validation): correction regex validation matricule"
git push -u origin fix/validation-matricule
# Créer PR avec label "urgent"
```

### Scénario 3 : Mettre à Jour Votre Branche

```bash
# Vous êtes sur feature/ma-feature depuis 3 jours
# develop a évolué entre temps

git checkout develop
git pull origin develop
git checkout feature/ma-feature
git merge develop
# Résoudre conflits si nécessaire
git push
```

### Scénario 4 : Annuler des Modifications

```bash
# Annuler modifications non commitées
git checkout -- src/fichier.c

# Annuler le dernier commit (avant push)
git reset --soft HEAD~1

# Annuler les modifications ajoutées (staged)
git reset HEAD src/fichier.c
```

---

## Outils Utiles

### Commandes Fréquentes

```bash
# Voir l'état actuel
git status

# Voir l'historique
git log --oneline --graph --all

# Voir les différences
git diff

# Voir les branches
git branch -a

# Changer de branche
git checkout nom-branche

# Voir les modifications d'un fichier
git log -p src/fichier.c
```

### Aliases Utiles (Optionnel)

```bash
# Ajouter dans ~/.gitconfig
[alias]
    st = status
    co = checkout
    br = branch
    ci = commit
    lg = log --oneline --graph --all
    unstage = reset HEAD --
```

---

## Résolution de Problèmes

### "J'ai fait un commit sur la mauvaise branche"

```bash
# Annuler le commit (garde les modifications)
git reset --soft HEAD~1

# Changer de branche
git checkout bonne-branche

# Refaire le commit
git add .
git commit -m "votre message"
```

### "J'ai des conflits et je suis perdu"

```bash
# Annuler le merge/pull
git merge --abort
# ou
git pull --abort

# Demander de l'aide à l'équipe
```

### "Je veux supprimer ma branche et recommencer"

```bash
# Sauvegarder vos modifications d'abord !
git stash

# Supprimer la branche locale
git checkout develop
git branch -D feature/ma-vieille-feature

# Recréer une branche propre
git checkout -b feature/ma-nouvelle-feature

# Récupérer vos modifications si nécessaire
git stash pop
```

---

## Checklist Quotidienne

### Début de Journée ☀️

- [ ] `git checkout develop`
- [ ] `git pull origin develop`
- [ ] Créer/reprendre votre branche feature
- [ ] Vérifier les nouvelles PR à reviewer

### Fin de Journée 🌙

- [ ] Commiter vos modifications
- [ ] Pusher votre branche
- [ ] Vérifier le statut de vos PR
- [ ] Documenter votre progression

---

**Dernière mise à jour** : 20 Décembre 2025