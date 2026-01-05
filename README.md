# Gestion-de-contact
Un programme en **C++** pour gérer une liste de contacts avec recherche, ajout, suppression et modification de fiches.

## Fonctionnalités
- Ajouter un nouveau contact
- Rechercher un contact par nom ou numero
- Supprimer un contact
- Afficher tous les contacts
- Sauvegarde automatique dans des fichiers

## Structure du projet

- `main.cpp` - boucle du programme
- `contact.h / contact.cpp` - Classe Contact
- `fiche_de_contact.h / fiche_de_contact.cpp` - Gestion des fiches (pas finis)
- `commande.h / commande.cpp` - Gestion des commandes

## Compilation et exécution
## Avec Code::Blocks
1. Ouvre 'gestion de contact.cbp'
2. Compile et execute

### Avec g++
bash: 
g++ -o gestion_contact main.cpp contact.cpp fiche_de_contact.cpp commande.cpp
./gestion_contact

## Prerequis 
C++11 ou supérieur
Compilateur : g++ , Code::Blocks, ou autre IDE C++

## Notes
- Les données sont sauvegardées automatiquement
- Les fichiers de données (.txt) sont ignorés par Git

Projet réaliser en entrainement pour gerer les fichiers 
