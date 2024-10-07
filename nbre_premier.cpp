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
    string finDeProgramme   = "O";
    int limite              = 0;
    int testChiffre         = 2;
    int tour                = 0;

    do{
        do {
            cout << "Rentrez un nombre entre 2-1000 : ";
            cin >> limite;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            if(limite > 1000 or limite < 2)
                cout << "Vous n'avez pas choisi un nombre correct. Ressayez !" << endl;
        }
        while (limite > 1000 or limite < 2);

        while(testChiffre <= limite){
            cout << "\t" << testChiffre;
            testChiffre++;
            tour++;
            for (int chiffreDivision = 2; chiffreDivision < testChiffre and testChiffre <= limite; chiffreDivision++) {
                if(testChiffre % chiffreDivision == 0) {
                    chiffreDivision = 2;
                    testChiffre++;
                    continue;
                }
            }
            if(tour == 5) {
                cout << "\n";
                tour = 0;
            }
        }

        do {
            cout << "\n Voulez-vous recommencer ? (O/N) : ";
            cin >> finDeProgramme;
        }
        while (finDeProgramme != "O" and finDeProgramme != "N");
    }while(finDeProgramme == "O");

    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cout << "\n \n Fin de Programme , pressez enter ";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    return EXIT_SUCCESS;
}