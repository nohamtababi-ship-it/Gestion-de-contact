#include "contact.h"
ofstream fcontactE(fichiercontact, ios::app);

contact::contact()
{
    _num="0000000000";
    _nom="inconnu";
}
contact::contact(string nom, string num)
{
    _nom=nom;
    while (num.size()<10)
    {
        cout << "le numero est incorrecte car comporte moins de 10 chiffre veuillez rentrer un numero de 10 chiffre : ";
        cin >> num;
    }
    _num=num;

    if(fcontactE)
    {
        fcontactE << _nom << " , " << _num << endl;
    }
    else
    {
        cout << "ERREUR: Impossible d'ouvrir le fichier." << endl;
    }

    cout << "contact cree : "<< _nom <<" , " <<_num << endl;

}
contact::~contact()
{

}
