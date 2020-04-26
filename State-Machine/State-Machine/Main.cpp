// State-Machine.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
//

#include <iostream>
#include "StateMachine.h"
#include <windows.h>

using namespace std;

int main()
{
    //Flag for keyboard input   
    bool A = false;
    bool Z = false;
    bool E = false;
    bool R = false;
    bool T = false;
    bool Y = false;
    bool U = false;
    bool I = false;


    //Conditions pour trigger les changement d'etats
    bool condition1to2 = false;//A
    bool condition2to1 = false;//A

    bool conditionS1toS2 = false;//Z

    bool conditionS1toS3 = false;//E

    bool conditionS2toS3 = false;//R
    bool conditionS3toS2 = false;//R

    bool conditionS2to1 = false;//T

    bool conditionS3to1 = false;//Y

    bool condition1toS1 = false;//U

    bool conditionToAny = false;//I

    bool conditionFromAny = true;


    //Création des états (nom,nombre de transitions,etat final ou non)
    State state1("1",3,false);
    State state2("2", 2, false);


    State AnyState("AnyState", 1, false);
    Trigger TrigtoAny(&conditionToAny); // Le trigger de la transition sera le bool conditionToAny 
    Transition TransAny(&AnyState, &TrigtoAny);
    Trigger TrigAnyto1(&conditionFromAny);
    Transition TransAnyTo(&state1, &TrigAnyto1);
    AnyState.AddTransition(&TransAnyTo, 0);

    State substate1("S1",2, false);
    State substate2("S2",2, false);
    State substate3("S3",2, false);

    //Trigger subMachine
    Trigger TrigS1toS2(&conditionS1toS2);
    Transition TransS1toS2(&substate2, &TrigS1toS2);
    substate1.AddTransition(&TransS1toS2,0);

    Trigger TrigS1toS3(&conditionS1toS3);
    Transition TransS1toS3(&substate3, &TrigS1toS3);
    substate1.AddTransition(&TransS1toS3,1);

    Trigger TrigS2toS3(&conditionS2toS3);
    Transition TransS2toS3(&substate3, &TrigS2toS3);
    substate2.AddTransition(&TransS2toS3, 0);

    Trigger TrigS2to1(&conditionS2to1);
    Transition TransS2to1(&state1, &TrigS2to1);
    substate2.AddTransition(&TransS2to1, 1);

    Trigger TrigS3toS2(&conditionS3toS2);
    Transition TransS3toS2(&substate2, &TrigS3toS2);
    substate3.AddTransition(&TransS3toS2, 0);

    Trigger TrigS3to1(&conditionS3to1);
    Transition TransS3to1(&state1, &TrigS3to1);
    substate3.AddTransition(&TransS3to1, 1);

    //Création de submachine
    std::vector<State> substates(3);
    substates[0] = substate1;
    substates[1] = substate2;
    substates[2] = substate3;
    StateMachine SubMachine1(substates);

    Trigger Trig1toS1(&condition1toS1); 
    Transition Trans1toS1(&substate1, &Trig1toS1);
    
    //Etat 1 vers 2 
    Trigger Trig1to2(&condition1to2); 
    Transition Trans1to2(&state2, &Trig1to2);
    state1.AddTransition(&TransAny, 0);
    state1.AddTransition(&Trans1to2,1);
    state1.AddTransition(&Trans1toS1, 2);
    state1.AddSubStateMachine(&SubMachine1, Trans1toS1);

    //Etat 2 vers 1 
    Trigger Trig2to1(&condition2to1);
    Transition Trans2to1(&state1, &Trig2to1);
    state2.AddTransition(&TransAny, 0);
    state2.AddTransition(&Trans2to1,1);

    //create StateMachine
    std::vector<State> states(2);
    states[0] = state1;
    states[1] = state2;
    StateMachine Machine(states);


    //Boucle principale pour les inputs
    while (true) {
        if (GetAsyncKeyState('A') & 0x8000 && !A) {
            A = true;
            if (condition1to2) {
                condition1to2 = false;
                condition2to1 = true;
            }
            else {
                condition1to2 = true;
                condition2to1 = false;
            }           
        }
        else if (GetAsyncKeyState('A') == 0) {
            bool condition1to2 = false;
            bool condition2to1 = false;
            A= false;
        }

        if (GetAsyncKeyState('Z') & 0x8000 && !Z) {
            Z = true;
            conditionS1toS2 = true;
        }
        else if (GetAsyncKeyState('Z') == 0) {
            conditionS1toS2 = false;
            Z = false;
        }

        if (GetAsyncKeyState('E') & 0x8000 && !E) {
            E = true;
            conditionS1toS3 = true;
        }
        else if (GetAsyncKeyState('E') == 0) {
            E = false;
            conditionS1toS3 = false;
        }

        if (GetAsyncKeyState('R') & 0x8000 && !R) {
            R = true;
            if (conditionS2toS3) {
                conditionS2toS3 = false;
                conditionS3toS2 = true;
            }
            else {
                conditionS2toS3 = true;
                conditionS3toS2 = false;
            }
        }
        else if (GetAsyncKeyState('R') == 0) {
            
            R = false;
        }

        if (GetAsyncKeyState('T') & 0x8000 && !T) {
            T = true;
            conditionS2to1 = true;
        }
        else if (GetAsyncKeyState('T') == 0) {
            T = false;
            conditionS2to1 = false;
        }

        if (GetAsyncKeyState('Y') & 0x8000 && !Y) {
            Y = true;
            conditionS3to1 = true;
        }
        else if (GetAsyncKeyState('Y') == 0) {
            Y = false;
            conditionS3to1 = false;
        }

        if (GetAsyncKeyState('U') & 0x8000 && !U) {
            U = true;
            condition1toS1 = true;
        }
        else if (GetAsyncKeyState('U') == 0) {
            U = false;
            condition1toS1 = false;
        }

        if (GetAsyncKeyState('I') & 0x8000 && !I) {
            I = true;
            conditionToAny = true;
        }
        else if (GetAsyncKeyState('I') == 0) {
            I = false;
            conditionToAny = false;
        }

        if (GetKeyState('X') & 0x8000) {
            return 0;
        }

        
        if (Machine.Current.IsFinal) {
            cout << "L'Etat " << Machine.CheckStates() << " est Terminal, fin du programme\n";
            return 0;
        }

        cout << "Etat : " << Machine.CheckStates() << " \n";
    }
    //system("pause");
    return 0;
}
