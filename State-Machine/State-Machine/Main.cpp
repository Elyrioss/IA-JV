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
    int testint = 1;

    float SubValue = 1;

    State state1("1",1,false);
    State state2("2", 1, true);

    State substate1("S1",2, false);
    State substate2("S2",0, false);
    State substate3("S3",0, false);
    //Trigger subMachine
    Trigger TrigSub1to2(&SubValue,2,1);
    Transition TransSub1to2(&substate2, &TrigSub1to2);
    substate1.AddTransition(&TransSub1to2,0);
    Trigger TrigSub1to3(&SubValue,2,0);
    Transition TransSub1to3(&substate3, &TrigSub1to3);
    substate1.AddTransition(&TransSub1to3,1);
    //Création de submachine
    std::vector<State> substates(3);
    substates[0] = substate1;
    substates[1] = substate2;
    substates[2] = substate3;
    StateMachine SubMachine1(substates);
    state1.AddSubStateMachine(&SubMachine1);



    //trigger et transition
    //Etat 1 vers 2 
    Trigger Trig1to2(&condition1to2); // Le trigger sera le bool condition1to2
    Transition Trans1to2(&state2, &Trig1to2);
    state1.AddTransition(&Trans1to2,0);

    //Etat 2 vers 1 
    Trigger Trig2to1(&testint, 2, 1); //Trigger est testint > a une valeur
    Transition Trans2to1(&state1, &Trig2to1);
    state2.AddTransition(&Trans2to1,0);

    //create StateMachine
    std::vector<State> states(2);
    states[0] = state1;
    states[1] = state2;
    StateMachine Machine(states);

    StateMachine SM(states);
    cout << "Etat : " << Machine.Current.Name << " and sub state : " + Machine.Current.Sub->Current.Name +"\n";
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
            SubValue = 2;
        }
        else if (GetAsyncKeyState('Z') == 0) {
            Z = false;
        }
        if (GetKeyState('X') & 0x8000) {
            return 0;
        }
        //testint += 1;
        cout << "Etat : " << Machine.CheckStates() << " \n";
        if (Machine.Current.IsFinal) {
            //cout << "L'Etat " << Machine.CheckStates() << " est Terminal, fin du programme\n";
            return 0;
        }
    }
    //system("pause");
    return 0;
}
