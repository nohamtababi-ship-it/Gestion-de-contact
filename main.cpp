#include <iostream>
#include "contact.h"
#include "commande.h"
//#include "test.h"
#include <vector>
using namespace std;

int main()
{
    int numero=0;
    vector<contact> contacts;
    while (numero!=999)
    {
            string nom;
            string num;
        cout << "veuillez choisir une option : " << endl;
        cout << "1 creation de contact " << endl;
        cout << "2 recherche de contact " << endl;
        cout << "3 suppression contact " << endl ;
        cout << "4 afficher tout les contact "<< endl;
        cout << "5 modifier le contact " << endl;
        cout << "999 STOP" << endl;
        cout << "votre choix : ";
        cin >> numero;
        if (numero==999)
        {
            break;
        }
        switch(numero)
        {
        case(1):
            {
            cout << "veuillez rentrer le nom du contact : ";
            cin >>nom;
            cout <<"veuillez rentrer le numero du contact : " ;
            cin >> num;
            contact c(nom,num);
            contacts.push_back(c);
            }
            break;
        case(2):
            {
               int choix;
            cout << "veuillez choisir le mode de recherche :" << endl;
            cout << "1 nom" << endl <<"2 num" << endl;
            cin >> choix;
            switch (choix)
            {
            case(1):
                cout <<"Veuillez indiquer le nom du contact (premiere lettre en maj) : ";
                cin>>nom;
                recherchecontactNom(nom);
                break;
            case(2):
                cout <<"Veuillez indiquer le numero du contact (sans espace) : ";
                cin>>num;
                recherchecontactNum(num);
                break;
            default:
                cout <<"erreur veuillez recommencer"<< endl;
                break;
            }
            }

            break;

        case(3):
        {
            suppressioncontact();

        }
                    break;
        case(4):
            {
                affichercontact();
            }
            break;
        case(5):
            {
                modifiercontact();
            }
            break;
        default:
            cout << "il faut choisir entre 1, 2, 3, 4 et 5" << endl;
            break;
        }
    }
    return 0;
}
//int main()
//{
//    lancerTests();
//    return 0;
//}
