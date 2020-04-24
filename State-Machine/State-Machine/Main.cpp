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

    State state1("1", 1,false);
    State state2("2", 1,true);

    //trigger et transition

    //1 vers 2 
    Trigger Trig1to2(&condition1to2);
    Transition Trans1to2(&state2, &Trig1to2);
    state1.AddTransition(&Trans1to2,0);

    //2 vers 1 
    Trigger Trig2to1(&testint, 2, 1);
    Transition Trans2to1(&state1, &Trig2to1);
    state2.AddTransition(&Trans2to1,0);

    //create StateMachine
    std::vector<State> states(2);
    states[0] = state1;
    states[1] = state2;
    StateMachine Machine(states);

    StateMachine SM(states);
    Machine.States[0].AddSubStateMachine(&SM);
    cout << "Etat : " << Machine.Current.Name << "\n";
    while (true) {
        if (GetAsyncKeyState('A') & 0x8000 && !A) {
            A = true;
            if (condition1to2) {
                condition1to2 = false;
            }
            else {
                condition1to2 = true;
            }           
        }
        else if (GetAsyncKeyState('A') == 0) {
            A= false;
        }

        if (GetAsyncKeyState('Z') & 0x8000 && !Z) {
            Z = true;
            
        }
        else if (GetAsyncKeyState('Z') == 0) {
            Z = false;
        }
        if (GetKeyState('X') & 0x8000) {
            return 0;
        }
        testint += 1;
        Vitesse += 0.1f;
        cout << "Etat : " << Machine.CheckStates() << "\n";
        if (Machine.Current.IsFinal) {
            cout << "L'Etat " << Machine.CheckStates() << " est Terminal, fin du programme\n";
            return 0;
        }
    }
    system("pause");
    return 0;
}
