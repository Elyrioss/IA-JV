#pragma once
#include <vector>
#include <string>
#include "Transition.h"

class StateMachine;

class State
{
private:
	
public:

	std::vector<Transition> Transitions;
	std::string Name;
	bool IsFinal;
	State(std::string Name, int NbTransitions,bool final);
	State();
	void AddTransition(Transition* transition,int index);
	void AddTransition(State* S,Trigger* TransTrig,int index);

	StateMachine* SubStateMachine;
};


