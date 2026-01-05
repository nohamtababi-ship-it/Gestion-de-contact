#include "fiche_de_contact.h"

fiche_de_contact::fiche_de_contact()
{
    _nomfiche="inconnu";
}

fiche_de_contact::fiche_de_contact(string nomfiche, contact contact1)
{
    _nomfiche=nomfiche;
    _fichecontact.push_back(contact1);
}

void fiche_de_contact::ajoutcontact(contact c)
{
    _fichecontact.push_back(c);
}


