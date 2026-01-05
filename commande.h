
#ifndef COMMANDE_H
#define COMMANDE_H
#include <fstream>
#include <iostream>
using namespace std;
unsigned int recherchecontactNum(string num);
unsigned int recherchecontactNom(string nom);
void affichercontact();
int trouverfin();
int trouvervirgule(string ligne);
void remplirnumero(string& numero,string ligne,unsigned int pvirgule);
void remplirnom(string& nom, string ligne, unsigned int pvirgule);
void resetLecture();
bool suppressioncontact();
void suppressionLigne(const string& fichier, int ligneSupprimer);
bool modifiercontact();
void modifierligne(const string& fichier,int ligneChanger);
#endif
