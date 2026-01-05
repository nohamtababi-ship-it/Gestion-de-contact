#ifndef FICHE_DE_CONTACT_H
#define FICHE_DE_CONTACT_H
#include <iostream>
#include "contact.h"
#include <vector>
using namespace std;

class fiche_de_contact
{
    public:
        fiche_de_contact();
        fiche_de_contact(string nomfiche, contact contact1);
        void ajoutcontact(contact c1);

    private:
        string _nomfiche;
        vector<contact> _fichecontact;
};

#endif // FICHE DE CONTACT_H
