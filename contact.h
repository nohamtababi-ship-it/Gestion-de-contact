
#ifndef CONTACT_H
#define CONTACT_H
#include <iostream>
#include <fstream>
using namespace std;

// mettez votre chemin pour le fichier
string const fichiercontact = "votre fichier";
string const fichiertempo   = "votre fichier";

class contact
{
    public:
        contact();
        contact(string nom, string num);
        ~contact();
    private:
        string _nom;
        string _num;
};

#endif // CONTACT_H
