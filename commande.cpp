#include "commande.h"
#include "contact.h"
#include <fstream>
#include <iostream>
using namespace std;
ifstream fcontacteL(fichiercontact);


unsigned int recherchecontactNum(string num)
{
    resetLecture();
    string ligne, numero,lignefinale;
    bool ok=false;
    unsigned int pvirgule, numligne=0;
    while(getline(fcontacteL, ligne) and !ok )
    {
        numligne++;
        pvirgule=trouvervirgule(ligne);
        numero.clear();
        for (unsigned int i=pvirgule+2; i<ligne.size(); i++) // ligne pour enregistrer verifier le numero
        {
            numero.push_back(ligne[i]);
        }
        ok=true;
        for (int i=0; i<10; i++) //comparer les numero
        {
            if (toupper(numero[i])!=toupper(num[i]))
            {
                ok=false;
                break;
            }
        }
        if(ok)
        {

            lignefinale=ligne;
            lignefinale.resize(pvirgule);
        }

    }

    if (ok)
    {
        cout << "nom : " << lignefinale << endl;
        cout << "numero : " << numero <<endl ;
        return numligne;
    }
    else
    {
        cout << "il n'y a pas de contact ayant ce numero." << endl;
    }
    return 0;
}

unsigned int recherchecontactNom(string nom)
{
    nom[0]=toupper(nom[0]);
    resetLecture();
    bool ok=false;
    string ligne,numero;
    unsigned int indexL=0;
    while(getline(fcontacteL, ligne) and !ok ) //comparer le nom avec le nom de la ligne
    {
        indexL++;
        unsigned int pvirgule=trouvervirgule(ligne);
        for (unsigned int i=0; i<pvirgule-1; i++)
        {
            ok=true;
            if(toupper(ligne[i])!=toupper(nom[i]))
            {
                ok=false;
                break;
            }
        }
        if (ok)
        {
            remplirnumero(numero,ligne,pvirgule);
        }
    }
    if(ok)
    {
        cout << "nom : "<<nom<<endl;
        cout << "numero : " << numero<<endl;
        return indexL;
    }
    else
    {
        cout << "il n'y a pas de contact avec ce nom." <<endl;
    }
    return 0;
}

void affichercontact()
{
    resetLecture();
    unsigned int i=0, pvirgule;
    string ligne;
    while(getline(fcontacteL, ligne))
    {
        string numero, nom;
        pvirgule=trouvervirgule(ligne);
        remplirnumero(numero,ligne,pvirgule);
        remplirnom(nom,ligne,pvirgule);
        cout << "contact numero " <<i << endl;
        cout << "nom : " << nom <<endl ;
        cout << "numero : " << numero<< endl;
        i++;
    }
    cout << "il y a au total " << (i-1)<< " contact." << endl;
}

int trouvervirgule(string ligne)
{
    unsigned int tailleligne=ligne.size();
    for (unsigned int i=0; i<tailleligne; i++)  // boucle pour trouver le virgule
    {
        if (ligne[i]==',')
        {
            return i;
            break;
        }
    }
    return -1; // jamais besoin de ce return car toujours une virgule.
}

void remplirnumero(string& numero, string ligne,unsigned int pvirgule)
{
    unsigned int sizeL=ligne.size();
    for (unsigned int i=pvirgule+2; i<sizeL; i++)
    {
        numero.push_back(ligne[i]);
    }
}

void remplirnom(string& nom, string ligne, unsigned int pvirgule)
{
    for (unsigned int i=0; i<pvirgule-1; i++)
    {
        nom.push_back(ligne[i]);
    }
}

void resetLecture()
{
    fcontacteL.clear();                // enlève EOF
    fcontacteL.seekg(0, ios::beg);     // revient au début
}

bool suppressioncontact()
{
    string nom, num;
    unsigned int choix,ligneContact;
    cout << "comment voulez vous supprimer le contact : " <<endl << "1 par nom " << endl << "2 par numero" << endl;
    cin >>choix;
    switch (choix)
    {
    case(1):
    {
        cout << "Entrez le nom : ";
        cin >>nom;
        cout <<"lancement de la recherche : " << endl;
        ligneContact=recherchecontactNom(nom);
        if (ligneContact==0)
        {
            return false;
        }
        else
        {
            suppressionLigne(fichiercontact, ligneContact);
        }
        break;
    }
    case(2):
    {
        cout << "Entrez le numero : ";
        cin >>num;
        cout <<"lancement de la recherche : " << endl;
        ligneContact=recherchecontactNum(num);
        if (ligneContact==0)
        {
            return false;
        }
        else
        {
            suppressionLigne(fichiercontact, ligneContact);
        }
    }
    break;
    default:
        cout << "erreur sur le nombre rentrer.";
        return false;
        break;
    }
    return true;
}

void suppressionLigne(const string& fichier, int ligneSupprimer)
{
    ifstream entree(fichier);
    ofstream sortie(fichiertempo);
    string ligne;
    int numligne=1;
    while (getline(entree,ligne))
    {
        if (numligne!=ligneSupprimer)
        {
            sortie<< ligne<< '\n';
        }
        numligne++;
    }
    entree.close();
    sortie.close();

    remove(fichier.c_str());
    rename(fichiertempo.c_str(), fichier.c_str());

}


bool modifiercontact()
{
    int ligneContact,choix;
    string nom,num;
        cout << "comment voulez vous modifier le contact : " <<endl << "1 par nom " << endl << "2 par numero" << endl;
    cin >>choix;
    switch (choix)
    {
    case(1):
    {
        cout << "Entrez le nom : ";
        cin >> nom;
        cout <<"lancement de la recherche : " << endl;
        ligneContact=recherchecontactNom(nom);
        if (ligneContact==0)
        {
            return false;
        }
        else
        {
            modifierligne(fichiercontact,ligneContact);
        }
    }
    break;
    case(2):
    {
        cout << "Entrez le numero : ";
        cin>> num;
        cout <<"lancement de la recherche : " << endl;
        ligneContact=recherchecontactNum(num);
        if (ligneContact==0)
        {
            return false;
        }
        else
        {
            modifierligne(fichiercontact,ligneContact);
        }
    }
        break;
    }
    return true;
}

void modifierligne(const string& fichier,int ligneChanger)
{
    string nvnom,nvnum,ligne,nvligne;
    ifstream entree(fichier);
    ofstream sortie(fichiertempo);
    int numligne=1;
    cout << "veuiller entrer le nouveau nom : ";
    cin >>nvnom;
    cout << "veuiller entrer le nouveau numero : ";
    cin >>nvnum;
    nvligne=nvnom+" , "+nvnum;
    while (getline(entree,ligne))
    {
        if (numligne!=ligneChanger)
        {
            sortie<< ligne<< '\n';
        }
        else
        {
            sortie<<nvligne<<'\n';
        }
        numligne++;
    }
    entree.close();
    sortie.close();

    remove(fichier.c_str());
    rename(fichiertempo.c_str(), fichier.c_str());

}

/*
c_str() convertis dans le bon format le format attendu par la fonction

*/
