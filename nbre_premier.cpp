/*
* \file nbre_premier.cpp
 * \version 1.0.0
 * \author Dylan Berney
 * \date : 04.10.2024
 * \brief : Afficheur de nombre premier
 */

#include <iostream>
#include <limits>
#include <string>

using namespace std;

int main() {
    string finDeProgramme   = "O";                      //Declaration des variable
    int limite          = 0;
    int testChiffre     = 2;
    int tour            = 0;
    do{
        do {
            cout << "Rentrez un nombre entre 2-1000 : ";
            cin >> limite;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            if(limite > 1000 or limite < 2)                                                 //On va tester l'entrée de l'utilisateur pour lui afficher un message d'erreur si elle ne corresponds pas au critère
                cout << "Vous n'avez pas choisi un nombre correct. Ressayez !" << endl;
        }
        while (limite > 1000 or limite < 2);                                                //On va tester si le chiffre rentré par l'utilisateur est entre 2 et 1000 sinon il doit recommencer

        while(testChiffre <= limite){                                                       //On test si le chiffre tester est égal ou en dessous de la limite afin de ne pas dépasser la limite
            cout << "\t" << testChiffre;                                                    //On affiche les nombre premier avec une tabulations avant
            testChiffre++;
            tour++;

            for (int chiffreDivision = 2; chiffreDivision < testChiffre and testChiffre <= limite; chiffreDivision++) {                 //On regarde si le chiffre par lequel on fait la division est plus petit que le chiffre tester et que le chiffre tester ne dépasse pas la limite
                if(testChiffre % chiffreDivision == 0) {                                                                                //On regarde si le chiffre tester ne donne aucun reste après la divion
                    chiffreDivision = 2;
                    testChiffre++;
                    continue;                                                                                                           //Si c'est le cas alors on remonte la boucle en incrémantant le chiffre tester de 1 et en remettant chiffreDvision à 2
                }
            }
            if(tour == 5) {                                                                                                             //On test si nous avons deja affiché 5 nombre
                cout << "\n";                                                                                                           //Si c'est le cas on fait un retour à la ligne
                tour = 0;
            }
        }

        do {
            cout << "\n Voulez-vous recommencer ? (O/N) : ";
            cin >> finDeProgramme;
        }
        while (finDeProgramme != "O" and finDeProgramme != "N");                                //On boucle tant que l'utilisateur n'a pas rentré O ou N
    }while(finDeProgramme == "O");                                                              //On remonte a la seconde boucle do while si l'utilisateur à rentré O

    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cout << "\n \n Fin de Programme , pressez enter ";                                          //On affiche un message pour signaler la fin du programme
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    return EXIT_SUCCESS;
}