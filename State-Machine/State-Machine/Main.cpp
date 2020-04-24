// State-Machine.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
//

#include <iostream>
#include "StateMachine.h"
#include <windows.h>

using namespace std;

int main()
{
    bool A = false;
    bool Z = false;

    bool condition1to2 = false;
    float Vitesse = 1.1f;
    int testint = 1;

    State state1("1", 1);
    State state2("2", 1);
    //trigger et transition
    //1 vers 2 
    Trigger Trig1to2(&testint,2);
    Transition Trans1to2(&state2, &Trig1to2);
    state1.AddTransition(Trans1to2,0);
    //2 vers 1 
    Trigger Trig2to1(&condition1to2);
    Transition Trans2to1(&state1, &Trig2to1);
    state2.AddTransition(Trans2to1,0);

    //create StateMachine
    std::vector<State> states(2);
    states[0] = state1;
    states[1] = state2;
    StateMachine Machine(states);

    cout << "Etat : " << Machine.Current.name << "\n";
    while (true) {
        if (GetAsyncKeyState('A') & 0x8000 && !A) {
            A = true;
            condition1to2 = true;
        }
        else if (GetAsyncKeyState('A') == 0) {
            A= false;
        }

        if (GetAsyncKeyState('Z') & 0x8000 && !Z) {
            Z = true;
            testint += 2;
        }
        else if (GetAsyncKeyState('Z') == 0) {
            Z = false;
        }
        if (GetKeyState('X') & 0x8000) {
            return 0;
        }
        cout << "Etat : " << Machine.CheckStates() << "\n";
        
    }
    system("pause");
    return 0;
}

// Exécuter le programme : Ctrl+F5 ou menu Déboguer > Exécuter sans débogage
// Déboguer le programme : F5 ou menu Déboguer > Démarrer le débogage

// Astuces pour bien démarrer : 
//   1. Utilisez la fenêtre Explorateur de solutions pour ajouter des fichiers et les gérer.
//   2. Utilisez la fenêtre Team Explorer pour vous connecter au contrôle de code source.
//   3. Utilisez la fenêtre Sortie pour voir la sortie de la génération et d'autres messages.
//   4. Utilisez la fenêtre Liste d'erreurs pour voir les erreurs.
//   5. Accédez à Projet > Ajouter un nouvel élément pour créer des fichiers de code, ou à Projet > Ajouter un élément existant pour ajouter des fichiers de code existants au projet.
//   6. Pour rouvrir ce projet plus tard, accédez à Fichier > Ouvrir > Projet et sélectionnez le fichier .sln.
