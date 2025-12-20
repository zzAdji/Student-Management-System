# 👥 Répartition des Tâches - Gestion des Étudiants

## 📊 Vue d'Ensemble du Projet

**Durée estimée** : 2-3 semaines  
**Membres** : 6 personnes  
**Méthode** : Développement modulaire avec intégration continue

---

## 🎯 Membre 1 - Chef de Projet & Interface

**Nom** : _______________

### Responsabilités Principales

- Coordination de l'équipe
- Gestion des Pull Requests
- Interface utilisateur (menu)
- Point d'entrée de l'application

### Fichiers à Créer

```
src/main.c
src/menu.c
include/menu.h
```

### Tâches Détaillées

#### Phase 1 : Setup Initial (Jour 1-2)
- [ ] Créer le repository GitHub
- [ ] Initialiser la structure du projet
- [ ] Créer les branches `main` et `develop`
- [ ] Configurer les protections de branches
- [ ] Inviter tous les membres

#### Phase 2 : Main (Jour 2-3)
- [ ] Implémenter `main.c`
  - [ ] Allocation dynamique mémoire
  - [ ] Demande nombre étudiants
  - [ ] Boucle principale
  - [ ] Libération mémoire
- [ ] Gestion fichier de sauvegarde (optionnel)

#### Phase 3 : Menu (Jour 3-5)
- [ ] Créer `menu.h` avec prototypes
- [ ] Implémenter `afficher_menu()`
  - [ ] Design avec bordures ASCII
  - [ ] 9 options + Quitter
- [ ] Implémenter `obtenir_choix()`
  - [ ] Validation entrée utilisateur (0-9)
  - [ ] Gestion erreurs
- [ ] Implémenter `traiter_choix()`
  - [ ] Switch case pour chaque option
  - [ ] Appel des fonctions appropriées
- [ ] Fonctions d'affichage :
  - [ ] `afficher_entete()`
  - [ ] `afficher_succes()`
  - [ ] `afficher_erreur()`

#### Phase 4 : Intégration (Jour 8-10)
- [ ] Intégrer tous les modules
- [ ] Tester l'application complète
- [ ] Corriger les bugs d'intégration
- [ ] Merger les branches vers `develop`
- [ ] Tester avant merge final vers `main`

### Estimation : 10-12 heures

---

## 👨‍💻 Membre 2 - Structure & CRUD

**Nom** : _______________

### Responsabilités Principales

- Structure de données principale
- Opérations CRUD (Create, Read, Update, Delete)
- Affichage des étudiants

### Fichiers à Créer

```
src/etudiant.c
src/operations.c
include/etudiant.h
include/operations.h
include/config.h
```

### Tâches Détaillées

#### Phase 1 : Structure (Jour 1-2)
- [ ] Créer `etudiant.h`
  - [ ] Définir structure `Date`
  - [ ] Définir structure `Gestion_des_Etudians`
  - [ ] Définir toutes les constantes (MAX_NOM, etc.)
- [ ] Créer `config.h` avec constantes globales
- [ ] Implémenter dans `etudiant.c` :
  - [ ] `initialiser_etudiant()`
  - [ ] `afficher_etudiant()`
  - [ ] `afficher_etudiant_formate()`
  - [ ] `afficher_entete_tableau()`
  - [ ] `copier_etudiant()`
  - [ ] Fonctions de comparaison (nom, filière, matricule)

#### Phase 2 : Opérations CRUD (Jour 3-6)
- [ ] Créer `operations.h` avec prototypes
- [ ] Implémenter `enregistrer_etudiant()`
  - [ ] Saisie de toutes les informations
  - [ ] Validation des données (appel validation.c)
  - [ ] Ajout au tableau
  - [ ] Gestion capacité maximale
- [ ] Implémenter `modifier_etudiant()`
  - [ ] Recherche de l'étudiant
  - [ ] Menu de modification
  - [ ] Modification via pointeurs
  - [ ] Confirmation modifications
- [ ] Implémenter `supprimer_etudiant()`
  - [ ] Recherche par matricule
  - [ ] Confirmation suppression
  - [ ] Décalage des éléments
  - [ ] Mise à jour du compteur
- [ ] Implémenter `afficher_tous_etudiants()`
  - [ ] Format tableau professionnel
  - [ ] Gestion liste vide
  - [ ] Numérotation

#### Phase 3 : Tests (Jour 7)
- [ ] Tester chaque fonction CRUD
- [ ] Cas limites (tableau vide, plein)
- [ ] Documentation des fonctions

### Estimation : 12-15 heures

---

## 🔍 Membre 3 - Recherche & Tri

**Nom** : _______________

### Responsabilités Principales

- Algorithmes de recherche
- Algorithmes de tri
- Optimisation des performances

### Fichiers à Créer

```
src/recherche.c
src/tri.c
include/recherche.h
include/tri.h
```

### Tâches Détaillées

#### Phase 1 : Recherche (Jour 2-4)
- [ ] Créer `recherche.h` avec prototypes
- [ ] Implémenter `recherche_lineaire()`
  - [ ] Parcours du tableau
  - [ ] Comparaison matricules
  - [ ] Retour index ou -1
- [ ] Implémenter `recherche_dichotomique()`
  - [ ] Vérifier tri préalable
  - [ ] Algorithme binaire
  - [ ] Gestion des cas limites
- [ ] Implémenter `est_trie()`
  - [ ] Vérification ordre matricules
- [ ] Fonction wrapper pour choix automatique :
  - [ ] Si trié → dichotomique
  - [ ] Sinon → linéaire

#### Phase 2 : Tri (Jour 4-6)
- [ ] Créer `tri.h` avec prototypes
- [ ] Implémenter `trier_alphabetique()`
  - [ ] Utiliser `qsort()` avec comparaison nom
  - [ ] Gestion caractères spéciaux
  - [ ] Ignorer la casse
- [ ] Implémenter `trier_par_filiere()`
  - [ ] Tri primaire par filière
  - [ ] Tri secondaire par nom
  - [ ] Utiliser `qsort()`
- [ ] Implémenter `trier_par_matricule()`
  - [ ] Nécessaire pour recherche dichotomique
  - [ ] Utiliser `qsort()`

#### Phase 3 : Optimisation (Jour 6-7)
- [ ] Tester performances sur grands ensembles
- [ ] Comparer temps recherche linéaire vs dichotomique
- [ ] Documentation algorithmes
- [ ] Ajouter compteurs de comparaisons (optionnel)

### Estimation : 10-12 heures

---

## 🛠️ Membre 4 - Utilitaires & Validation

**Nom** : _______________

### Responsabilités Principales

- Fonctions utilitaires
- Validation des données
- Gestion des dates
- Sécurisation des entrées

### Fichiers à Créer

```
src/utils.c
src/validation.c
include/utils.h
include/validation.h
```

### Tâches Détaillées

#### Phase 1 : Utilitaires (Jour 2-3)
- [ ] Créer `utils.h` avec prototypes
- [ ] Implémenter `calculer_age()`
  - [ ] Obtenir date système
  - [ ] Calcul âge avec gestion anniversaire
  - [ ] Validation dates futures
- [ ] Implémenter `obtenir_date_actuelle()`
  - [ ] Utiliser `time()` et `localtime()`
- [ ] Implémenter `vider_buffer()`
  - [ ] Nettoyer stdin après scanf
- [ ] Implémenter `pause_systeme()`
  - [ ] Multiplateforme (Windows/Linux)
- [ ] Implémenter `effacer_ecran()`
  - [ ] Multiplateforme
- [ ] Implémenter `str_to_upper()`
- [ ] Implémenter `generer_matricule()`
  - [ ] Format : ETU + année + numéro

#### Phase 2 : Validation (Jour 4-6)
- [ ] Créer `validation.h` avec prototypes
- [ ] Implémenter `valider_matricule()`
  - [ ] Vérifier format (lettres + chiffres)
  - [ ] Vérifier longueur
- [ ] Implémenter `valider_date()`
  - [ ] Vérifier jours selon mois
  - [ ] Gérer années bissextiles
  - [ ] Vérifier cohérence (pas de dates futures)
- [ ] Implémenter `valider_sexe()`
  - [ ] Accepter 'M', 'm', 'F', 'f'
  - [ ] Convertir en majuscule
- [ ] Implémenter `valider_chaine()`
  - [ ] Vérifier non vide
  - [ ] Supprimer espaces début/fin
  - [ ] Vérifier longueur
- [ ] Implémenter `saisir_chaine_valide()`
  - [ ] Boucle jusqu'à entrée valide
  - [ ] Afficher messages d'erreur clairs
- [ ] Implémenter `saisir_date_valide()`
  - [ ] Validation avec feedback
- [ ] Implémenter `matricule_existe()`
  - [ ] Vérifier unicité matricule

#### Phase 3 : Tests (Jour 7)
- [ ] Tester toutes les validations
- [ ] Cas limites (chaînes vides, dates invalides)
- [ ] Documentation

### Estimation : 12-14 heures

---

## 📝 Membre 5 - Documentation & Tests

**Nom** : _______________

### Responsabilités Principales

- Documentation complète
- Tests manuels
- Guide utilisateur
- Rapport de bugs

### Fichiers à Créer

```
docs/GUIDE_UTILISATEUR.md
docs/RAPPORT_TESTS.md
docs/BUGS_CONNUS.md
tests/ (optionnel)
```

### Tâches Détaillées

#### Phase 1 : Documentation Technique (Jour 1-3)
- [ ] Compléter README.md
  - [ ] Ajouter exemples d'utilisation
  - [ ] Screenshots du menu
- [ ] Créer GUIDE_UTILISATEUR.md
  - [ ] Tutoriel pas à pas
  - [ ] Captures d'écran de chaque fonctionnalité
  - [ ] FAQ
  - [ ] Résolution de problèmes
- [ ] Documenter l'API
  - [ ] Description de chaque fonction
  - [ ] Paramètres et retours
  - [ ] Exemples d'utilisation
- [ ] Créer diagrammes (optionnel)
  - [ ] Diagramme de flux
  - [ ] Diagramme de structure

#### Phase 2 : Tests (Jour 4-7)
- [ ] Créer plan de tests
  - [ ] Liste de tous les scénarios
  - [ ] Cas normaux et limites
- [ ] Tester chaque fonctionnalité :
  - [ ] Enregistrement (normal, erreurs)
  - [ ] Modification (existant, inexistant)
  - [ ] Recherche (trouvé, non trouvé)
  - [ ] Suppression (existant, inexistant)
  - [ ] Tri alphabétique
  - [ ] Recherche dichotomique (trié, non trié)
  - [ ] Calcul âge (dates variées)
  - [ ] Tri par filière
  - [ ] Affichage
- [ ] Documenter résultats tests
  - [ ] Créer RAPPORT_TESTS.md
  - [ ] Pour chaque test : attendu vs obtenu
  - [ ] Bugs trouvés
- [ ] Créer BUGS_CONNUS.md
  - [ ] Lister tous les bugs
  - [ ] Prioriser (critique, majeur, mineur)
  - [ ] Proposer solutions

#### Phase 3 : Amélioration (Jour 8-10)
- [ ] Relire tout le code
- [ ] Suggérer améliorations
- [ ] Vérifier commentaires code
- [ ] Valider conventions respectées
- [ ] Créer tutoriels vidéo (optionnel)

### Estimation : 12-15 heures

---

## 🔧 Membre 6 - Build & Intégration

**Nom** : _______________

### Responsabilités Principales

- Système de build (Makefile)
- Intégration continue
- Résolution des conflits
- Support technique

### Fichiers à Créer

```
Makefile
.gitignore
scripts/ (optionnel)
```

### Tâches Détaillées

#### Phase 1 : Build System (Jour 1-2)
- [ ] Créer Makefile complet
  - [ ] Règle `all` (compilation)
  - [ ] Règle `clean` (nettoyage objets)
  - [ ] Règle `fclean` (nettoyage complet)
  - [ ] Règle `re` (recompilation)
  - [ ] Règle `run` (exécution)
  - [ ] Règle `debug` (mode debug)
  - [ ] Règle `help` (aide)
- [ ] Configurer flags compilation
  - [ ] `-Wall -Wextra -Werror`
  - [ ] Options d'optimisation
- [ ] Créer `.gitignore`
  - [ ] Fichiers compilés
  - [ ] Fichiers temporaires
  - [ ] IDE specifics

#### Phase 2 : Intégration Continue (Jour 3-5)
- [ ] Tester compilation après chaque merge
- [ ] Vérifier compatibilité modules
- [ ] Résoudre conflits Git
- [ ] Aider membres avec problèmes Git
- [ ] Créer scripts utilitaires :
  - [ ] Script de test automatique
  - [ ] Script de nettoyage
  - [ ] Script de backup

#### Phase 3 : Support (Jour 6-10)
- [ ] Disponible pour problèmes techniques
- [ ] Aider avec erreurs compilation
- [ ] Debugger problèmes d'intégration
- [ ] Optimiser Makefile si besoin
- [ ] Tester sur différentes plateformes :
  - [ ] Windows (MinGW)
  - [ ] Linux
  - [ ] macOS (si disponible)

#### Phase 4 : Livraison (Jour 10)
- [ ] Compilation finale sans erreurs
- [ ] Créer version release
- [ ] Générer archive projet
- [ ] Vérifier tous fichiers nécessaires
- [ ] Tester installation depuis zéro

### Estimation : 10-12 heures

---

## 📅 Planning

### Semaine 1

**Jours 1-2 : Setup & Structure**
- Tous : Setup Git, branches
- M1 : Main basique
- M2 : Structures
- M3 : Headers recherche/tri
- M4 : Headers utils/validation
- M5 : Plan documentation
- M6 : Makefile

**Jours 3-5 : Développement Core**
- M1 : Menu complet
- M2 : CRUD complet
- M3 : Recherche
- M4 : Validation
- M5 : Tests CRUD
- M6 : Tests compilation

**Jours 6-7 : Fonctionnalités Avancées**
- M1 : Intégration menu
- M2 : Peaufinage CRUD
- M3 : Tri complet
- M4 : Utilitaires complets
- M5 : Tests avancés
- M6 : Debug intégration

### Semaine 2

**Jours 8-10 : Intégration & Tests**
- M1 : Coordination intégration
- M2-M4 : Corrections bugs
- M3 : Optimisations
- M4 : Edge cases
- M5 : Documentation finale
- M6 : Tests finaux

**Jours 11-12 : Polish & Livraison**
- Tous : Tests finaux
- M1 : Merge vers main
- M5 : Documentation complète
- M6 : Archive livraison

---

## 🎯 Critères de Succès

### Fonctionnel
- [ ] Toutes les 9 fonctionnalités implémentées
- [ ] Aucune erreur de compilation
- [ ] Aucun segmentation fault
- [ ] Gestion correcte de la mémoire

### Code Quality
- [ ] Code commenté et lisible
- [ ] Conventions respectées
- [ ] Pas de code dupliqué
- [ ] Fonctions bien découpées

### Collaboration
- [ ] Tous les membres ont contribué
- [ ] Historique Git propre
- [ ] PRs reviewées avant merge
- [ ] Documentation à jour

### User Experience
- [ ] Interface claire et intuitive
- [ ] Messages d'erreur explicites
- [ ] Gestion robuste des entrées
- [ ] Performance acceptable

---

## 💡 Conseils Finaux

1. **Communiquez** : Sur Whatsapp
2. **Committez souvent** : Petits commits fréquents
3. **Testez tôt** : Ne pas attendre la fin
4. **Demandez de l'aide** : N'hésitez pas
5. **Respectez les deadlines** : Suivez le planning
6. **Soyez professionnel** : Code propre et documenté
